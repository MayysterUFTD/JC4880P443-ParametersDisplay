#ifndef EEZ_LVGL_UI_STYLES_H
#define EEZ_LVGL_UI_STYLES_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

// Style: Label30
lv_style_t *get_style_label30_MAIN_DEFAULT();
void add_style_label30(lv_obj_t *obj);
void remove_style_label30(lv_obj_t *obj);

// Style: panelDefault
lv_style_t *get_style_panel_default_MAIN_DEFAULT();
void add_style_panel_default(lv_obj_t *obj);
void remove_style_panel_default(lv_obj_t *obj);

// Style: Label15
lv_style_t *get_style_label15_MAIN_DEFAULT();
void add_style_label15(lv_obj_t *obj);
void remove_style_label15(lv_obj_t *obj);

// Style: panelParameters
lv_style_t *get_style_panel_parameters_MAIN_DEFAULT();
void add_style_panel_parameters(lv_obj_t *obj);
void remove_style_panel_parameters(lv_obj_t *obj);

// Style: containerParameters
lv_style_t *get_style_container_parameters_MAIN_DEFAULT();
void add_style_container_parameters(lv_obj_t *obj);
void remove_style_container_parameters(lv_obj_t *obj);

// Style: barDefault
lv_style_t *get_style_bar_default_MAIN_DEFAULT();
lv_style_t *get_style_bar_default_INDICATOR_DEFAULT();
void add_style_bar_default(lv_obj_t *obj);
void remove_style_bar_default(lv_obj_t *obj);

// Style: defaultScale
lv_style_t *get_style_default_scale_ITEMS_DEFAULT();
lv_style_t *get_style_default_scale_INDICATOR_DEFAULT();
lv_style_t *get_style_default_scale_MAIN_DEFAULT();
void add_style_default_scale(lv_obj_t *obj);
void remove_style_default_scale(lv_obj_t *obj);

// Style: barDefaulta
lv_style_t *get_style_bar_defaulta_MAIN_DEFAULT();
lv_style_t *get_style_bar_defaulta_INDICATOR_DEFAULT();
void add_style_bar_defaulta(lv_obj_t *obj);
void remove_style_bar_defaulta(lv_obj_t *obj);

// Style: defaultArc
lv_style_t *get_style_default_arc_KNOB_DEFAULT();
lv_style_t *get_style_default_arc_MAIN_DEFAULT();
lv_style_t *get_style_default_arc_INDICATOR_DEFAULT();
void add_style_default_arc(lv_obj_t *obj);
void remove_style_default_arc(lv_obj_t *obj);



#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_STYLES_H*/