#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *main;
    lv_obj_t *panel_main_channel1;
    lv_obj_t *panel_main_channel1__obj5;
    lv_obj_t *panel_main_channel1__label_channel_number;
    lv_obj_t *panel_main_channel1__obj6;
    lv_obj_t *panel_main_channel1__label_stage;
    lv_obj_t *panel_main_channel1__led_stage;
    lv_obj_t *panel_main_channel1__obj7;
    lv_obj_t *panel_main_channel1__label_type;
    lv_obj_t *panel_main_channel1__obj8;
    lv_obj_t *panel_main_channel1__label_voltage;
    lv_obj_t *panel_main_channel1__label_current;
    lv_obj_t *panel_main_channel1__label_temperature;
    lv_obj_t *panel_main_channel1__obj9;
    lv_obj_t *panel_main_channel1__bar_progress_percent;
    lv_obj_t *panel_main_channel1__label_bar_percentt;
    lv_obj_t *panel_main_channel1__label_eta_time;
    lv_obj_t *panel_main_channel1__label_elapsed_time;
    lv_obj_t *panel_main_channel2;
    lv_obj_t *panel_main_channel2__obj5;
    lv_obj_t *panel_main_channel2__label_channel_number;
    lv_obj_t *panel_main_channel2__obj6;
    lv_obj_t *panel_main_channel2__label_stage;
    lv_obj_t *panel_main_channel2__led_stage;
    lv_obj_t *panel_main_channel2__obj7;
    lv_obj_t *panel_main_channel2__label_type;
    lv_obj_t *panel_main_channel2__obj8;
    lv_obj_t *panel_main_channel2__label_voltage;
    lv_obj_t *panel_main_channel2__label_current;
    lv_obj_t *panel_main_channel2__label_temperature;
    lv_obj_t *panel_main_channel2__obj9;
    lv_obj_t *panel_main_channel2__bar_progress_percent;
    lv_obj_t *panel_main_channel2__label_bar_percentt;
    lv_obj_t *panel_main_channel2__label_eta_time;
    lv_obj_t *panel_main_channel2__label_elapsed_time;
    lv_obj_t *panel_main_channel3;
    lv_obj_t *panel_main_channel3__obj5;
    lv_obj_t *panel_main_channel3__label_channel_number;
    lv_obj_t *panel_main_channel3__obj6;
    lv_obj_t *panel_main_channel3__label_stage;
    lv_obj_t *panel_main_channel3__led_stage;
    lv_obj_t *panel_main_channel3__obj7;
    lv_obj_t *panel_main_channel3__label_type;
    lv_obj_t *panel_main_channel3__obj8;
    lv_obj_t *panel_main_channel3__label_voltage;
    lv_obj_t *panel_main_channel3__label_current;
    lv_obj_t *panel_main_channel3__label_temperature;
    lv_obj_t *panel_main_channel3__obj9;
    lv_obj_t *panel_main_channel3__bar_progress_percent;
    lv_obj_t *panel_main_channel3__label_bar_percentt;
    lv_obj_t *panel_main_channel3__label_eta_time;
    lv_obj_t *panel_main_channel3__label_elapsed_time;
    lv_obj_t *panel_main_channel4;
    lv_obj_t *panel_main_channel4__obj5;
    lv_obj_t *panel_main_channel4__label_channel_number;
    lv_obj_t *panel_main_channel4__obj6;
    lv_obj_t *panel_main_channel4__label_stage;
    lv_obj_t *panel_main_channel4__led_stage;
    lv_obj_t *panel_main_channel4__obj7;
    lv_obj_t *panel_main_channel4__label_type;
    lv_obj_t *panel_main_channel4__obj8;
    lv_obj_t *panel_main_channel4__label_voltage;
    lv_obj_t *panel_main_channel4__label_current;
    lv_obj_t *panel_main_channel4__label_temperature;
    lv_obj_t *panel_main_channel4__obj9;
    lv_obj_t *panel_main_channel4__bar_progress_percent;
    lv_obj_t *panel_main_channel4__label_bar_percentt;
    lv_obj_t *panel_main_channel4__label_eta_time;
    lv_obj_t *panel_main_channel4__label_elapsed_time;
    lv_obj_t *details_channel1;
    lv_obj_t *details_channel1__obj0;
    lv_obj_t *details_channel1__dropdown_battery_type;
    lv_obj_t *details_channel1__obj1;
    lv_obj_t *details_channel1__switch_charge;
    lv_obj_t *details_channel1__switch_discharge;
    lv_obj_t *details_channel1__switch_resist;
    lv_obj_t *details_channel1__switch_capacity;
    lv_obj_t *details_channel1__switch_storage;
    lv_obj_t *details_channel1__switch_cycle;
    lv_obj_t *details_channel1__button_start;
    lv_obj_t *details_channel1__obj2;
    lv_obj_t *details_channel1__obj3;
    lv_obj_t *details_channel1__label_main_voltage;
    lv_obj_t *details_channel1__label_main_current;
    lv_obj_t *details_channel1__obj4;
    lv_obj_t *details_channel1__label_main_resistance;
    lv_obj_t *details_channel1__textarea_voltage_max;
    lv_obj_t *details_channel1__textarea_voltage_min;
    lv_obj_t *details_channel1__textarea_charge_current;
    lv_obj_t *details_channel1__textarea_discharge_current;
    lv_obj_t *details_channel1__chart_main;
    lv_obj_t *details_channel1__keyboard_numbers;
    lv_obj_t *details_channel1__bar_current_process;
    lv_obj_t *details_channel1__label_current_process_percent;
    lv_obj_t *details_channel1__label_current_process_name;
    lv_obj_t *details_channel2;
    lv_obj_t *details_channel2__obj0;
    lv_obj_t *details_channel2__dropdown_battery_type;
    lv_obj_t *details_channel2__obj1;
    lv_obj_t *details_channel2__switch_charge;
    lv_obj_t *details_channel2__switch_discharge;
    lv_obj_t *details_channel2__switch_resist;
    lv_obj_t *details_channel2__switch_capacity;
    lv_obj_t *details_channel2__switch_storage;
    lv_obj_t *details_channel2__switch_cycle;
    lv_obj_t *details_channel2__button_start;
    lv_obj_t *details_channel2__obj2;
    lv_obj_t *details_channel2__obj3;
    lv_obj_t *details_channel2__label_main_voltage;
    lv_obj_t *details_channel2__label_main_current;
    lv_obj_t *details_channel2__obj4;
    lv_obj_t *details_channel2__label_main_resistance;
    lv_obj_t *details_channel2__textarea_voltage_max;
    lv_obj_t *details_channel2__textarea_voltage_min;
    lv_obj_t *details_channel2__textarea_charge_current;
    lv_obj_t *details_channel2__textarea_discharge_current;
    lv_obj_t *details_channel2__chart_main;
    lv_obj_t *details_channel2__keyboard_numbers;
    lv_obj_t *details_channel2__bar_current_process;
    lv_obj_t *details_channel2__label_current_process_percent;
    lv_obj_t *details_channel2__label_current_process_name;
    lv_obj_t *details_channel3;
    lv_obj_t *details_channel3__obj0;
    lv_obj_t *details_channel3__dropdown_battery_type;
    lv_obj_t *details_channel3__obj1;
    lv_obj_t *details_channel3__switch_charge;
    lv_obj_t *details_channel3__switch_discharge;
    lv_obj_t *details_channel3__switch_resist;
    lv_obj_t *details_channel3__switch_capacity;
    lv_obj_t *details_channel3__switch_storage;
    lv_obj_t *details_channel3__switch_cycle;
    lv_obj_t *details_channel3__button_start;
    lv_obj_t *details_channel3__obj2;
    lv_obj_t *details_channel3__obj3;
    lv_obj_t *details_channel3__label_main_voltage;
    lv_obj_t *details_channel3__label_main_current;
    lv_obj_t *details_channel3__obj4;
    lv_obj_t *details_channel3__label_main_resistance;
    lv_obj_t *details_channel3__textarea_voltage_max;
    lv_obj_t *details_channel3__textarea_voltage_min;
    lv_obj_t *details_channel3__textarea_charge_current;
    lv_obj_t *details_channel3__textarea_discharge_current;
    lv_obj_t *details_channel3__chart_main;
    lv_obj_t *details_channel3__keyboard_numbers;
    lv_obj_t *details_channel3__bar_current_process;
    lv_obj_t *details_channel3__label_current_process_percent;
    lv_obj_t *details_channel3__label_current_process_name;
    lv_obj_t *details_channel4;
    lv_obj_t *details_channel4__obj0;
    lv_obj_t *details_channel4__dropdown_battery_type;
    lv_obj_t *details_channel4__obj1;
    lv_obj_t *details_channel4__switch_charge;
    lv_obj_t *details_channel4__switch_discharge;
    lv_obj_t *details_channel4__switch_resist;
    lv_obj_t *details_channel4__switch_capacity;
    lv_obj_t *details_channel4__switch_storage;
    lv_obj_t *details_channel4__switch_cycle;
    lv_obj_t *details_channel4__button_start;
    lv_obj_t *details_channel4__obj2;
    lv_obj_t *details_channel4__obj3;
    lv_obj_t *details_channel4__label_main_voltage;
    lv_obj_t *details_channel4__label_main_current;
    lv_obj_t *details_channel4__obj4;
    lv_obj_t *details_channel4__label_main_resistance;
    lv_obj_t *details_channel4__textarea_voltage_max;
    lv_obj_t *details_channel4__textarea_voltage_min;
    lv_obj_t *details_channel4__textarea_charge_current;
    lv_obj_t *details_channel4__textarea_discharge_current;
    lv_obj_t *details_channel4__chart_main;
    lv_obj_t *details_channel4__keyboard_numbers;
    lv_obj_t *details_channel4__bar_current_process;
    lv_obj_t *details_channel4__label_current_process_percent;
    lv_obj_t *details_channel4__label_current_process_name;
    lv_obj_t *main_tabview;
    lv_obj_t *obj0;
    lv_obj_t *obj1;
    lv_obj_t *obj2;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_MAIN = 1,
};

void create_screen_main();
void delete_screen_main();
void tick_screen_main();

void create_user_widget_details(lv_obj_t *parent_obj, void *flowState, int startWidgetIndex);
void tick_user_widget_details(void *flowState, int startWidgetIndex);

void create_user_widget_panel_summary(lv_obj_t *parent_obj, void *flowState, int startWidgetIndex);
void tick_user_widget_panel_summary(void *flowState, int startWidgetIndex);

void create_screen_by_id(enum ScreensEnum screenId);
void delete_screen_by_id(enum ScreensEnum screenId);
void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/