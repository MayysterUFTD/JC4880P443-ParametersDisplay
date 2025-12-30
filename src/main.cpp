/**
 * @file main.cpp
 * @brief ESP32-P4 Hardware Monitor Display with EEZ Studio UI
 *
 * MIPI DSI display (ST7701 480x800) with GT911 touch and LVGL 9.x
 */

#pragma GCC push_options
#pragma GCC optimize("O3")

#include <Arduino.h>
#include <USB.h>
#include <USBCDC.h>

// ESP-IDF drivers
#include "driver/gpio.h"
#include "driver/ledc.h"
#include "driver/i2c_master.h"
#include "esp_ldo_regulator.h"
#include "esp_lcd_panel_io.h"
#include "esp_lcd_panel_ops.h"
#include "esp_lcd_mipi_dsi.h"

// LCD & Touch
#include "lcd/esp_lcd_st7701.h"
#include "touch/esp_lcd_touch_gt911.h"

// LVGL
#include "lvgl.h"
#include "lvgl_port_v9.h"
#include "pins_config.h"

// UI & Application
#include "ui/ui.h"
#include "ui/screens.h"
#include "HWMonitor/HWMonitor.h"
#include "SmoothValue.h"

/*===========================================================================*/
/*  CONFIGURATION                                                            */
/*===========================================================================*/

#define TAG "main"

// Display
#define LCD_H_RES 480
#define LCD_V_RES 800
#define LCD_RST_PIN GPIO_NUM_5
#define LCD_BACKLIGHT_PIN GPIO_NUM_23
#define LCD_LEDC_CHANNEL LEDC_CHANNEL_0

// I2C (Touch)
#define I2C_PORT I2C_NUM_1
#define I2C_SDA_PIN GPIO_NUM_7
#define I2C_SCL_PIN GPIO_NUM_8

// MIPI DSI PHY Power
#define MIPI_DSI_PHY_LDO_CHAN 3
#define MIPI_DSI_PHY_LDO_MV 2500

/*===========================================================================*/
/*  GLOBALS                                                                  */
/*===========================================================================*/

extern "C" int16_t g_currentScreen;

static i2c_master_bus_handle_t s_i2c_handle = NULL;
static HWMonitor s_monitor;
static USBCDC USBSerial;
static SmoothValueManager<32> s_smooth(0.01f); // Wygładzanie wartości sensorów

/*===========================================================================*/
/*  BACKLIGHT CONTROL                                                        */
/*===========================================================================*/

static void backlight_init(void)
{
  const ledc_timer_config_t timer_cfg = {
      .speed_mode = LEDC_LOW_SPEED_MODE,
      .duty_resolution = LEDC_TIMER_10_BIT,
      .timer_num = LEDC_TIMER_1,
      .freq_hz = 5000,
      .clk_cfg = LEDC_AUTO_CLK};

  const ledc_channel_config_t channel_cfg = {
      .gpio_num = LCD_BACKLIGHT_PIN,
      .speed_mode = LEDC_LOW_SPEED_MODE,
      .channel = LCD_LEDC_CHANNEL,
      .intr_type = LEDC_INTR_DISABLE,
      .timer_sel = LEDC_TIMER_1,
      .duty = 0,
      .hpoint = 0};

  ledc_timer_config(&timer_cfg);
  ledc_channel_config(&channel_cfg);
}

static void backlight_set(uint8_t percent)
{
  if (percent > 100)
    percent = 100;
  uint32_t duty = (1023 * percent) / 100;
  ledc_set_duty(LEDC_LOW_SPEED_MODE, LCD_LEDC_CHANNEL, duty);
  ledc_update_duty(LEDC_LOW_SPEED_MODE, LCD_LEDC_CHANNEL);
}

/*===========================================================================*/
/*  HARDWARE INITIALIZATION                                                  */
/*===========================================================================*/

static void init_i2c(void)
{
  i2c_master_bus_config_t cfg = {
      .i2c_port = I2C_PORT,
      .sda_io_num = I2C_SDA_PIN,
      .scl_io_num = I2C_SCL_PIN,
      .clk_source = I2C_CLK_SRC_DEFAULT,
  };
  i2c_new_master_bus(&cfg, &s_i2c_handle);
}

static void init_mipi_dsi_power(void)
{
  static esp_ldo_channel_handle_t ldo_handle = NULL;
  esp_ldo_channel_config_t cfg = {
      .chan_id = MIPI_DSI_PHY_LDO_CHAN,
      .voltage_mv = MIPI_DSI_PHY_LDO_MV,
  };
  esp_ldo_acquire_channel(&cfg, &ldo_handle);
}

static IRAM_ATTR bool lcd_vsync_callback(esp_lcd_panel_handle_t panel,
                                         esp_lcd_dpi_panel_event_data_t *edata,
                                         void *user_ctx)
{
  return lvgl_port_notify_lcd_vsync();
}

static esp_lcd_panel_handle_t init_lcd(esp_lcd_dsi_bus_handle_t dsi_bus)
{
  // DBI IO for commands
  esp_lcd_panel_io_handle_t io = NULL;
  esp_lcd_dbi_io_config_t dbi_cfg = ST7701_PANEL_IO_DBI_CONFIG();
  esp_lcd_new_panel_io_dbi(dsi_bus, &dbi_cfg, &io);

  // DPI config
  esp_lcd_dpi_panel_config_t dpi_cfg = ST7701_480_360_PANEL_60HZ_DPI_CONFIG(LCD_COLOR_PIXEL_FORMAT_RGB565);
  dpi_cfg.num_fbs = LVGL_PORT_LCD_BUFFER_NUMS;

  // Panel config
  st7701_vendor_config_t vendor_cfg = {
      .mipi_config = {
          .dsi_bus = dsi_bus,
          .dpi_config = &dpi_cfg,
      },
      .flags = {.use_mipi_interface = 1},
  };

  esp_lcd_panel_dev_config_t panel_cfg = {
      .reset_gpio_num = LCD_RST_PIN,
      .rgb_ele_order = ESP_LCD_COLOR_SPACE_RGB,
      .bits_per_pixel = 16,
      .vendor_config = &vendor_cfg,
  };

  esp_lcd_panel_handle_t panel = NULL;
  esp_lcd_new_panel_st7701(io, &panel_cfg, &panel);
  esp_lcd_panel_reset(panel);
  esp_lcd_panel_init(panel);

  // Register vsync callback
  esp_lcd_dpi_panel_event_callbacks_t cbs = {
#if LVGL_PORT_AVOID_TEAR_MODE
      .on_refresh_done = lcd_vsync_callback,
#else
      .on_color_trans_done = lcd_vsync_callback,
#endif
  };
  esp_lcd_dpi_panel_register_event_callbacks(panel, &cbs, NULL);

  return panel;
}

static esp_lcd_touch_handle_t init_touch(void)
{
  esp_lcd_panel_io_handle_t io = NULL;
  esp_lcd_panel_io_i2c_config_t io_cfg = ESP_LCD_TOUCH_IO_I2C_GT911_CONFIG();
  io_cfg.scl_speed_hz = 100000;
  esp_lcd_new_panel_io_i2c(s_i2c_handle, &io_cfg, &io);

  esp_lcd_touch_config_t touch_cfg = {
      .x_max = LCD_H_RES,
      .y_max = LCD_V_RES,
      .rst_gpio_num = GPIO_NUM_NC,
      .int_gpio_num = GPIO_NUM_NC,
      .levels = {.reset = 0, .interrupt = 0},
      .flags = {.swap_xy = 0, .mirror_x = 0, .mirror_y = 0},
  };

  esp_lcd_touch_handle_t handle = NULL;
  esp_lcd_touch_new_i2c_gt911(io, &touch_cfg, &handle);
  return handle;
}

static bool init_ui(void)
{
  // Wait for LVGL task to stabilize
  vTaskDelay(pdMS_TO_TICKS(500));

  // Try to acquire lock and initialize UI
  for (int attempt = 0; attempt < 50; attempt++)
  {
    if (lvgl_port_lock(100))
    {
      ui_init();
      lvgl_port_unlock();
      return true;
    }
    vTaskDelay(pdMS_TO_TICKS(20));
  }
  return false;
}

/*===========================================================================*/
/*  ARDUINO SETUP & LOOP                                                     */
/*===========================================================================*/

void setup()
{
  Serial.begin(115200);
  delay(500);

  // USB CDC
  USBSerial.setRxBufferSize(4096);
  USBSerial.begin();
  USB.begin();

  Serial.println("=== Hardware Monitor Display ===");

  // Initialize hardware
  backlight_init();
  init_i2c();
  init_mipi_dsi_power();

  // Initialize DSI bus
  esp_lcd_dsi_bus_handle_t dsi_bus = NULL;
  esp_lcd_dsi_bus_config_t bus_cfg = ST7701_PANEL_BUS_DSI_2CH_CONFIG();
  esp_lcd_new_dsi_bus(&bus_cfg, &dsi_bus);

  // Initialize LCD and touch
  esp_lcd_panel_handle_t lcd = init_lcd(dsi_bus);
  esp_lcd_touch_handle_t touch = init_touch();

  // Initialize LVGL port
  lvgl_port_interface_t iface = LVGL_PORT_INTERFACE_MIPI_DSI_NO_DMA;
  ESP_ERROR_CHECK(lvgl_port_init(lcd, touch, iface));

  // Initialize EEZ UI
  if (!init_ui())
  {
    Serial.println("ERROR: UI initialization failed!");
  }

  // Start monitor and enable backlight
  s_monitor.begin();
  backlight_set(50);

  Serial.println("=== Ready ===");
}

void loop()
{
  // Aktualizuj wartości docelowe gdy przychodzą nowe dane z USB
  if (s_monitor.update(USBSerial))
  {
    // CPU
    s_smooth.setTarget(0x01, s_monitor.get(0x01)); // CPU Load
    s_smooth.setTarget(0x02, s_monitor.get(0x02)); // CPU Temp

    // GPU
    s_smooth.setTarget(0x5D, s_monitor.get(0x5D)); // GPU Load
    s_smooth.setTarget(0x5A, s_monitor.get(0x5A)); // GPU Temp

    // RAM
    s_smooth.setTarget(0x38, s_monitor.get(0x38)); // RAM Used GB
    s_smooth.setTarget(0x39, s_monitor.get(0x39)); // RAM Available GB
    s_smooth.setTarget(0x3A, s_monitor.get(0x3A)); // RAM Load %

    Serial.println(s_monitor.sensorCount);
  }

  // Interpoluj wartości w każdej klatce (płynne przejścia)
  s_smooth.updateAll();

  // Update UI - teraz wykonuje się w każdej klatce z wygładzonymi wartościami
  if (lvgl_port_lock(10))
  {
    if (g_currentScreen >= 0)
    {
      ui_tick();
    }

    // CPU - wygładzone wartości
    lv_label_set_text_fmt(objects.label_cpu_load,
                          "%.0f", s_smooth.get(0x01));
    lv_label_set_text_fmt(objects.label_cpu_temp,
                          "%.0f", s_smooth.get(0x02));
    lv_arc_set_value(objects.arc_cpu_load,
                     (int)s_smooth.getInt(0x01));
    lv_arc_set_value(objects.arc_cpu_temp,
                     (int)s_smooth.getInt(0x02));

    // GPU - wygładzone wartości
    lv_label_set_text_fmt(objects.label_gpu_load,
                          "%.0f", s_smooth.get(0x5D));
    lv_label_set_text_fmt(objects.label_gpu_temp,
                          "%.0f", s_smooth.get(0x5A));

    lv_arc_set_value(objects.arc_gpu_load,
                     (int)s_smooth.getInt(0x5D));
    lv_arc_set_value(objects.arc_gpu_temp,
                     (int)s_smooth.getInt(0x5A));

    // RAM - wygładzone wartości
    float ram_used_gb = s_smooth.get(0x38);
    float ram_available_gb = s_smooth.get(0x39);
    float ram_load_percent = s_smooth.get(0x3A);

    lv_bar_set_value(objects.bar_ram_used,
                     (int)(ram_load_percent + 0.5f), LV_ANIM_OFF); // Wyłącz animację LVGL - mamy własną
    lv_label_set_text_fmt(objects.label_ram_gb_used,
                          "%.0f", ram_used_gb);
    lv_label_set_text_fmt(objects.label_ram_gb_avalivable,
                          "%.0f", ram_available_gb);
    lv_label_set_text_fmt(objects.label_ram_used,
                          "%.1f", ram_load_percent);

    lvgl_port_unlock();
  }

  vTaskDelay(pdMS_TO_TICKS(16)); // ~60 FPS dla płynnej animacji
}

#pragma GCC pop_options
