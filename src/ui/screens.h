#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *main;
    lv_obj_t *main_tabview;
    lv_obj_t *bar_ram_used;
    lv_obj_t *arc_cpu_temp;
    lv_obj_t *arc_cpu_load;
    lv_obj_t *label_cpu_temp;
    lv_obj_t *label_cpu_load;
    lv_obj_t *arc_gpu_temp;
    lv_obj_t *arc_gpu_load;
    lv_obj_t *label_gpu_temp;
    lv_obj_t *label_gpu_load;
    lv_obj_t *label_ram_used;
    lv_obj_t *label_ram_gb_used;
    lv_obj_t *label_ram_gb_avalivable;
    lv_obj_t *arc1;
    lv_obj_t *label1;
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