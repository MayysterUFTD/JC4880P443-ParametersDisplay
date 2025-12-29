#include "styles.h"
#include "images.h"
#include "fonts.h"

#include "ui.h"
#include "screens.h"

//
// Style: Label30
//

void init_style_label30_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_font(style, &ui_font_chakra40);
    lv_style_set_text_color(style, lv_color_hex(0xfff0f5ff));
};

lv_style_t *get_style_label30_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_label30_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_label30(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_label30_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_label30(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_label30_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: panelDefault
//

void init_style_panel_default_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_opa(style, 0);
    lv_style_set_border_width(style, 1);
    lv_style_set_radius(style, 3);
    lv_style_set_border_opa(style, 255);
    lv_style_set_bg_color(style, lv_color_hex(0xff14181c));
    lv_style_set_border_color(style, lv_color_hex(0xff323c4b));
};

lv_style_t *get_style_panel_default_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_panel_default_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_panel_default(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_panel_default_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_panel_default(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_panel_default_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: Label15
//

void init_style_label15_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_font(style, &ui_font_chakra15);
    lv_style_set_text_color(style, lv_color_hex(0xff788796));
};

lv_style_t *get_style_label15_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_label15_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_label15(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_label15_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_label15(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_label15_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: panelParameters
//

void init_style_panel_parameters_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_bg_opa(style, 0);
    lv_style_set_border_opa(style, 0);
    lv_style_set_layout(style, LV_LAYOUT_FLEX);
    lv_style_set_flex_flow(style, LV_FLEX_FLOW_ROW);
    lv_style_set_flex_main_place(style, LV_FLEX_ALIGN_SPACE_EVENLY);
    lv_style_set_flex_cross_place(style, LV_FLEX_ALIGN_CENTER);
    lv_style_set_flex_track_place(style, LV_FLEX_ALIGN_CENTER);
};

lv_style_t *get_style_panel_parameters_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_panel_parameters_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_panel_parameters(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_panel_parameters_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_panel_parameters(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_panel_parameters_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: containerParameters
//

void init_style_container_parameters_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_layout(style, LV_LAYOUT_FLEX);
    lv_style_set_flex_flow(style, LV_FLEX_FLOW_COLUMN);
    lv_style_set_flex_main_place(style, LV_FLEX_ALIGN_SPACE_BETWEEN);
    lv_style_set_flex_cross_place(style, LV_FLEX_ALIGN_CENTER);
    lv_style_set_flex_track_place(style, LV_FLEX_ALIGN_CENTER);
    lv_style_set_flex_grow(style, 0);
};

lv_style_t *get_style_container_parameters_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_container_parameters_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_container_parameters(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_container_parameters_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_container_parameters(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_container_parameters_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
// Style: barDefault
//

void init_style_bar_default_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_radius(style, 0);
    lv_style_set_bg_color(style, lv_color_hex(0xff646464));
};

lv_style_t *get_style_bar_default_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_bar_default_MAIN_DEFAULT(style);
    }
    return style;
};

void init_style_bar_default_INDICATOR_DEFAULT(lv_style_t *style) {
    lv_style_set_radius(style, 0);
    lv_style_set_bg_color(style, lv_color_hex(0xffa8a8a8));
    lv_style_set_shadow_width(style, 35);
    lv_style_set_shadow_spread(style, 2);
    lv_style_set_shadow_color(style, lv_color_hex(0xff969696));
};

lv_style_t *get_style_bar_default_INDICATOR_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_bar_default_INDICATOR_DEFAULT(style);
    }
    return style;
};

void add_style_bar_default(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_bar_default_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_bar_default_INDICATOR_DEFAULT(), LV_PART_INDICATOR | LV_STATE_DEFAULT);
};

void remove_style_bar_default(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_bar_default_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_bar_default_INDICATOR_DEFAULT(), LV_PART_INDICATOR | LV_STATE_DEFAULT);
};

//
// Style: defaultScale
//

void init_style_default_scale_ITEMS_DEFAULT(lv_style_t *style) {
    lv_style_set_length(style, 5);
    lv_style_set_line_color(style, lv_color_hex(0xff2f3237));
    lv_style_set_line_width(style, 1);
};

lv_style_t *get_style_default_scale_ITEMS_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_default_scale_ITEMS_DEFAULT(style);
    }
    return style;
};

void init_style_default_scale_INDICATOR_DEFAULT(lv_style_t *style) {
    lv_style_set_length(style, 10);
    lv_style_set_line_color(style, lv_color_hex(0xff2f3237));
    lv_style_set_line_width(style, 1);
};

lv_style_t *get_style_default_scale_INDICATOR_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_default_scale_INDICATOR_DEFAULT(style);
    }
    return style;
};

void init_style_default_scale_MAIN_DEFAULT(lv_style_t *style) {
    lv_style_set_text_color(style, lv_color_hex(0xff788796));
    lv_style_set_line_color(style, lv_color_hex(0xff2f3237));
    lv_style_set_text_font(style, &ui_font_chakra15);
    lv_style_set_line_width(style, 1);
};

lv_style_t *get_style_default_scale_MAIN_DEFAULT() {
    static lv_style_t *style;
    if (!style) {
        style = lv_malloc(sizeof(lv_style_t));
        lv_style_init(style);
        init_style_default_scale_MAIN_DEFAULT(style);
    }
    return style;
};

void add_style_default_scale(lv_obj_t *obj) {
    (void)obj;
    lv_obj_add_style(obj, get_style_default_scale_ITEMS_DEFAULT(), LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_default_scale_INDICATOR_DEFAULT(), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_add_style(obj, get_style_default_scale_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

void remove_style_default_scale(lv_obj_t *obj) {
    (void)obj;
    lv_obj_remove_style(obj, get_style_default_scale_ITEMS_DEFAULT(), LV_PART_ITEMS | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_default_scale_INDICATOR_DEFAULT(), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_remove_style(obj, get_style_default_scale_MAIN_DEFAULT(), LV_PART_MAIN | LV_STATE_DEFAULT);
};

//
//
//

void add_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*AddStyleFunc)(lv_obj_t *obj);
    static const AddStyleFunc add_style_funcs[] = {
        add_style_label30,
        add_style_panel_default,
        add_style_label15,
        add_style_panel_parameters,
        add_style_container_parameters,
        add_style_bar_default,
        add_style_default_scale,
    };
    add_style_funcs[styleIndex](obj);
}

void remove_style(lv_obj_t *obj, int32_t styleIndex) {
    typedef void (*RemoveStyleFunc)(lv_obj_t *obj);
    static const RemoveStyleFunc remove_style_funcs[] = {
        remove_style_label30,
        remove_style_panel_default,
        remove_style_label15,
        remove_style_panel_parameters,
        remove_style_container_parameters,
        remove_style_bar_default,
        remove_style_default_scale,
    };
    remove_style_funcs[styleIndex](obj);
}

