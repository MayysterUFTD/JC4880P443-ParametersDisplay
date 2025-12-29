#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;

void create_screen_main() {
    void *flowState = getFlowState(0, 0);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // mainTabview
            lv_obj_t *obj = lv_tabview_create(parent_obj);
            objects.main_tabview = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 800, 480);
            lv_tabview_set_tab_bar_position(obj, LV_DIR_TOP);
            lv_tabview_set_tab_bar_size(obj, 30);
            lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
            lv_obj_set_style_text_font(obj, &ui_font_orbition20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff101316), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "MAIN");
                    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                }
                {
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "CPU");
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // arc1
                            lv_obj_t *obj = lv_arc_create(parent_obj);
                            objects.arc1 = obj;
                            lv_obj_set_pos(obj, 230, 55);
                            lv_obj_set_size(obj, 300, 300);
                            lv_arc_set_value(obj, 25);
                            lv_arc_set_bg_start_angle(obj, 90);
                            lv_arc_set_bg_end_angle(obj, 0);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // label1
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    objects.label1 = obj;
                                    lv_obj_set_pos(obj, 112, 129);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    add_style_label30(obj);
                                    lv_label_set_text(obj, "Text");
                                }
                            }
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "GPU");
                }
                {
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "RAM");
                }
                {
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "DISK");
                }
            }
        }
    }
    
    tick_screen_main();
}

void delete_screen_main() {
    lv_obj_delete(objects.main);
    objects.main = 0;
    objects.main_tabview = 0;
    objects.arc1 = 0;
    objects.label1 = 0;
    deletePageFlowState(0);
}

void tick_screen_main() {
    void *flowState = getFlowState(0, 0);
    (void)flowState;
}

void create_screen_test() {
    void *flowState = getFlowState(0, 1);
    (void)flowState;
    lv_obj_t *obj = lv_obj_create(0);
    objects.test = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_tabview_create(parent_obj);
            objects.obj0 = obj;
            lv_obj_set_pos(obj, 541, 0);
            lv_obj_set_size(obj, 259, 480);
            lv_tabview_set_tab_bar_position(obj, LV_DIR_TOP);
            lv_tabview_set_tab_bar_size(obj, 32);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xffc5c5c5), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Tab");
                }
                {
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Tab");
                }
                {
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Tab");
                }
            }
        }
        {
            lv_obj_t *obj = lv_tabview_create(parent_obj);
            objects.obj1 = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 400, 480);
            lv_tabview_set_tab_bar_position(obj, LV_DIR_TOP);
            lv_tabview_set_tab_bar_size(obj, 32);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xffb2b2b2), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Tab");
                }
                {
                    lv_obj_t *obj = lv_tabview_add_tab(parent_obj, "Tab");
                }
            }
        }
    }
    
    tick_screen_test();
}

void delete_screen_test() {
    lv_obj_delete(objects.test);
    objects.test = 0;
    objects.obj0 = 0;
    objects.obj1 = 0;
    deletePageFlowState(1);
}

void tick_screen_test() {
    void *flowState = getFlowState(0, 1);
    (void)flowState;
}

void create_user_widget_details(lv_obj_t *parent_obj, void *flowState, int startWidgetIndex) {
    (void)flowState;
    (void)startWidgetIndex;
    lv_obj_t *obj = parent_obj;
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            ((lv_obj_t **)&objects)[startWidgetIndex + 0] = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 201, 448);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
            add_style_panel_default(obj);
            lv_obj_set_style_text_font(obj, &ui_font_fira_code15, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff101316), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // dropdownBatteryType
                    lv_obj_t *obj = lv_dropdown_create(parent_obj);
                    ((lv_obj_t **)&objects)[startWidgetIndex + 1] = obj;
                    lv_obj_set_pos(obj, -3, -7);
                    lv_obj_set_size(obj, 166, LV_SIZE_CONTENT);
                    lv_dropdown_set_options(obj, "Li-Ion\nLi-Po\nLiFePo4\nNiMh\nPB");
                    lv_dropdown_set_dir(obj, LV_DIR_RIGHT);
                    lv_dropdown_set_symbol(obj, LV_SYMBOL_RIGHT);
                    lv_dropdown_set_selected(obj, 0);
                    lv_obj_set_style_text_font(obj, &ui_font_chakra30, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_width(obj, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff646464), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff282b30), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, -3724, 0);
                    lv_obj_set_size(obj, 182, 10);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    ((lv_obj_t **)&objects)[startWidgetIndex + 2] = obj;
                    lv_obj_set_pos(obj, -1442, -331);
                    lv_obj_set_size(obj, 189, 246);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                    add_style_panel_parameters(obj);
                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff171b20), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff646464), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_width(obj, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_EVENLY, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, -21, 61);
                            lv_obj_set_size(obj, 185, 35);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &ui_font_fira_code15, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // switchCharge
                                    lv_obj_t *obj = lv_switch_create(parent_obj);
                                    ((lv_obj_t **)&objects)[startWidgetIndex + 3] = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 50, 25);
                                }
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    add_style_label30(obj);
                                    lv_obj_set_style_text_font(obj, &ui_font_chakra30, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_letter_space(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "Charge");
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, -21, 61);
                            lv_obj_set_size(obj, 185, 35);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &ui_font_fira_code15, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // switchDischarge
                                    lv_obj_t *obj = lv_switch_create(parent_obj);
                                    ((lv_obj_t **)&objects)[startWidgetIndex + 4] = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 50, 25);
                                }
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    add_style_label30(obj);
                                    lv_obj_set_style_text_font(obj, &ui_font_chakra30, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_letter_space(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "Disharge");
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, -21, 61);
                            lv_obj_set_size(obj, 185, 35);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &ui_font_fira_code15, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // switchResist
                                    lv_obj_t *obj = lv_switch_create(parent_obj);
                                    ((lv_obj_t **)&objects)[startWidgetIndex + 5] = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 50, 25);
                                }
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    add_style_label30(obj);
                                    lv_obj_set_style_text_font(obj, &ui_font_chakra30, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_letter_space(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "Resist");
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, -21, 61);
                            lv_obj_set_size(obj, 185, 35);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &ui_font_fira_code15, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // switchCapacity
                                    lv_obj_t *obj = lv_switch_create(parent_obj);
                                    ((lv_obj_t **)&objects)[startWidgetIndex + 6] = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 50, 25);
                                }
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    add_style_label30(obj);
                                    lv_obj_set_style_text_font(obj, &ui_font_chakra30, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_letter_space(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "Capacity");
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, -21, 61);
                            lv_obj_set_size(obj, 185, 35);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &ui_font_fira_code15, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // switchStorage
                                    lv_obj_t *obj = lv_switch_create(parent_obj);
                                    ((lv_obj_t **)&objects)[startWidgetIndex + 7] = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 50, 25);
                                }
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    add_style_label30(obj);
                                    lv_obj_set_style_text_font(obj, &ui_font_chakra30, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_letter_space(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "Storage");
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, -21, 61);
                            lv_obj_set_size(obj, 185, 35);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_font(obj, &ui_font_fira_code15, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    // switchCycle
                                    lv_obj_t *obj = lv_switch_create(parent_obj);
                                    ((lv_obj_t **)&objects)[startWidgetIndex + 8] = obj;
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, 50, 25);
                                }
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    add_style_label30(obj);
                                    lv_obj_set_style_text_font(obj, &ui_font_chakra30, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_letter_space(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "Cycle");
                                }
                            }
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, 182, 10);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // buttonStart
                    lv_obj_t *obj = lv_button_create(parent_obj);
                    ((lv_obj_t **)&objects)[startWidgetIndex + 9] = obj;
                    lv_obj_set_pos(obj, 1431, 0);
                    lv_obj_set_size(obj, 183, 50);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff00a653), LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            add_style_label30(obj);
                            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "[ Start ]");
                        }
                    }
                }
            }
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            ((lv_obj_t **)&objects)[startWidgetIndex + 10] = obj;
            lv_obj_set_pos(obj, 201, 0);
            lv_obj_set_size(obj, 599, 448);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
            add_style_panel_default(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff101316), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    ((lv_obj_t **)&objects)[startWidgetIndex + 11] = obj;
                    lv_obj_set_pos(obj, -4, -15);
                    lv_obj_set_size(obj, 566, 127);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                    add_style_panel_default(obj);
                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW_WRAP, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_EVENLY, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_SPACE_EVENLY, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_grow(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff171b20), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_color(obj, lv_color_hex(0xff646464), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_shadow_width(obj, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, 252, -433);
                            lv_obj_set_size(obj, 230, 80);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            add_style_container_parameters(obj);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    add_style_label15(obj);
                                    lv_label_set_text(obj, "Voltage");
                                }
                                {
                                    // labelMainVoltage
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    ((lv_obj_t **)&objects)[startWidgetIndex + 12] = obj;
                                    lv_obj_set_pos(obj, -18, 3);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    add_style_label30(obj);
                                    lv_obj_set_style_text_font(obj, &ui_font_orbition60, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "4.20V");
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, -5, 15);
                            lv_obj_set_size(obj, 230, 80);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            add_style_container_parameters(obj);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    add_style_label15(obj);
                                    lv_label_set_text(obj, "Current");
                                }
                                {
                                    // labelMainCurrent
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    ((lv_obj_t **)&objects)[startWidgetIndex + 13] = obj;
                                    lv_obj_set_pos(obj, -18, 3);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    add_style_label30(obj);
                                    lv_obj_set_style_text_font(obj, &ui_font_orbition60, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "2.55A");
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, 9, -372);
                            lv_obj_set_size(obj, 184, 54);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            add_style_container_parameters(obj);
                            lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_COLUMN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    ((lv_obj_t **)&objects)[startWidgetIndex + 14] = obj;
                                    lv_obj_set_pos(obj, -4, 33);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    add_style_label15(obj);
                                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff788796), LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "Internal Resistance");
                                }
                                {
                                    // labelMainResistance
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    ((lv_obj_t **)&objects)[startWidgetIndex + 15] = obj;
                                    lv_obj_set_pos(obj, -18, 3);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    add_style_label30(obj);
                                    lv_obj_set_style_text_font(obj, &ui_font_orbition30, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "0.15R");
                                }
                            }
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, -4, 286);
                    lv_obj_set_size(obj, 300, 32);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                    add_style_panel_default(obj);
                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_END, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_grow(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            lv_obj_set_pos(obj, 407, 290);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            add_style_label30(obj);
                            lv_obj_set_style_text_font(obj, &ui_font_chakra30, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_letter_space(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "Voltage MAX:");
                        }
                        {
                            // textareaVoltageMax
                            lv_obj_t *obj = lv_textarea_create(parent_obj);
                            ((lv_obj_t **)&objects)[startWidgetIndex + 16] = obj;
                            lv_obj_set_pos(obj, 30, 399);
                            lv_obj_set_size(obj, 86, 60);
                            lv_textarea_set_accepted_chars(obj, "1234567980.");
                            lv_textarea_set_max_length(obj, 5);
                            lv_textarea_set_placeholder_text(obj, "4.20");
                            lv_textarea_set_one_line(obj, true);
                            lv_textarea_set_password_mode(obj, false);
                            lv_obj_set_style_text_font(obj, &ui_font_fira_code30, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, -4, 320);
                    lv_obj_set_size(obj, 300, 32);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                    add_style_panel_default(obj);
                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_END, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_grow(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            lv_obj_set_pos(obj, 209, 373);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            add_style_label30(obj);
                            lv_obj_set_style_text_font(obj, &ui_font_chakra30, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_letter_space(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "Voltage MIN:");
                        }
                        {
                            // textareaVoltageMin
                            lv_obj_t *obj = lv_textarea_create(parent_obj);
                            ((lv_obj_t **)&objects)[startWidgetIndex + 17] = obj;
                            lv_obj_set_pos(obj, 745, 404);
                            lv_obj_set_size(obj, 86, 60);
                            lv_textarea_set_accepted_chars(obj, "1234567980.");
                            lv_textarea_set_max_length(obj, 5);
                            lv_textarea_set_placeholder_text(obj, "3.20");
                            lv_textarea_set_one_line(obj, true);
                            lv_textarea_set_password_mode(obj, false);
                            lv_obj_set_style_text_font(obj, &ui_font_fira_code30, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, -4, 354);
                    lv_obj_set_size(obj, 300, 32);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                    add_style_panel_default(obj);
                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_END, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_SPACE_EVENLY, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_grow(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            lv_obj_set_pos(obj, -15, 297);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            add_style_label30(obj);
                            lv_obj_set_style_text_font(obj, &ui_font_chakra30, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_letter_space(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "Ch Current:");
                        }
                        {
                            // textareaChargeCurrent
                            lv_obj_t *obj = lv_textarea_create(parent_obj);
                            ((lv_obj_t **)&objects)[startWidgetIndex + 18] = obj;
                            lv_obj_set_pos(obj, 755, 453);
                            lv_obj_set_size(obj, 86, 60);
                            lv_textarea_set_accepted_chars(obj, "1234567980.");
                            lv_textarea_set_max_length(obj, 5);
                            lv_textarea_set_placeholder_text(obj, "1.00");
                            lv_textarea_set_one_line(obj, true);
                            lv_textarea_set_password_mode(obj, false);
                            lv_obj_set_style_text_font(obj, &ui_font_fira_code30, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, -4, 388);
                    lv_obj_set_size(obj, 300, 32);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                    add_style_panel_default(obj);
                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_END, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_SPACE_EVENLY, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_grow(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            lv_obj_set_pos(obj, 149, 297);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            add_style_label30(obj);
                            lv_obj_set_style_text_font(obj, &ui_font_chakra30, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_letter_space(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "Dc Current:");
                        }
                        {
                            // textareaDischargeCurrent
                            lv_obj_t *obj = lv_textarea_create(parent_obj);
                            ((lv_obj_t **)&objects)[startWidgetIndex + 19] = obj;
                            lv_obj_set_pos(obj, 384, 324);
                            lv_obj_set_size(obj, 86, 60);
                            lv_textarea_set_accepted_chars(obj, "1234567980.");
                            lv_textarea_set_max_length(obj, 5);
                            lv_textarea_set_placeholder_text(obj, "0.50");
                            lv_textarea_set_one_line(obj, true);
                            lv_textarea_set_password_mode(obj, false);
                            lv_obj_set_style_text_font(obj, &ui_font_fira_code30, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                        }
                    }
                }
                {
                    // chartMain
                    lv_obj_t *obj = lv_chart_create(parent_obj);
                    ((lv_obj_t **)&objects)[startWidgetIndex + 20] = obj;
                    lv_obj_set_pos(obj, 6, 120);
                    lv_obj_set_size(obj, 554, 148);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_OVERFLOW_VISIBLE);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_scale_create(parent_obj);
                    lv_obj_set_pos(obj, -3, 133);
                    lv_obj_set_size(obj, 24, 123);
                    lv_scale_set_mode(obj, LV_SCALE_MODE_VERTICAL_LEFT);
                    lv_scale_set_range(obj, 0, 5);
                    lv_scale_set_total_tick_count(obj, 5);
                    lv_scale_set_major_tick_every(obj, 1);
                    lv_scale_set_label_show(obj, true);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                    add_style_default_scale(obj);
                }
                {
                    lv_obj_t *obj = lv_scale_create(parent_obj);
                    lv_obj_set_pos(obj, 19, 255);
                    lv_obj_set_size(obj, 529, 19);
                    lv_scale_set_mode(obj, LV_SCALE_MODE_HORIZONTAL_BOTTOM);
                    lv_scale_set_range(obj, -60, 0);
                    lv_scale_set_total_tick_count(obj, 5);
                    lv_scale_set_major_tick_every(obj, 1);
                    lv_scale_set_label_show(obj, true);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
                    add_style_default_scale(obj);
                }
            }
        }
        {
            // keyboardNumbers
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            ((lv_obj_t **)&objects)[startWidgetIndex + 21] = obj;
            lv_obj_set_pos(obj, 75, 14);
            lv_obj_set_size(obj, 650, 288);
            lv_keyboard_set_mode(obj, LV_KEYBOARD_MODE_NUMBER);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 245, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_clip_corner(obj, false, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 25, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(obj, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_color(obj, lv_color_hex(0xffb6b6b6), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 501, 315);
            lv_obj_set_size(obj, 299, 133);
            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_OVERFLOW_VISIBLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 95, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    add_style_label15(obj);
                    lv_obj_set_style_text_font(obj, &ui_font_chakra30, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Process");
                }
                {
                    // barCurrentProcess
                    lv_obj_t *obj = lv_bar_create(parent_obj);
                    ((lv_obj_t **)&objects)[startWidgetIndex + 22] = obj;
                    lv_obj_set_pos(obj, 20, 77);
                    lv_obj_set_size(obj, 259, 22);
                    lv_bar_set_value(obj, 20, LV_ANIM_OFF);
                    lv_obj_add_flag(obj, LV_OBJ_FLAG_OVERFLOW_VISIBLE);
                    add_style_bar_default(obj);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // labelCurrentProcessPercent
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            ((lv_obj_t **)&objects)[startWidgetIndex + 23] = obj;
                            lv_obj_set_pos(obj, 88, 0);
                            lv_obj_set_size(obj, 83, LV_SIZE_CONTENT);
                            add_style_label15(obj);
                            lv_obj_set_style_text_font(obj, &ui_font_orbition20, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "20%");
                        }
                    }
                }
                {
                    // labelCurrentProcessName
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    ((lv_obj_t **)&objects)[startWidgetIndex + 24] = obj;
                    lv_obj_set_pos(obj, 26, 26);
                    lv_obj_set_size(obj, 247, LV_SIZE_CONTENT);
                    add_style_label30(obj);
                    lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Discharging");
                }
                {
                    lv_obj_t *obj = lv_scale_create(parent_obj);
                    lv_obj_set_pos(obj, 21, 100);
                    lv_obj_set_size(obj, 258, 22);
                    lv_scale_set_mode(obj, LV_SCALE_MODE_HORIZONTAL_BOTTOM);
                    lv_scale_set_range(obj, 0, 100);
                    lv_scale_set_total_tick_count(obj, 31);
                    lv_scale_set_major_tick_every(obj, 6);
                    lv_scale_set_label_show(obj, true);
                    add_style_default_scale(obj);
                }
            }
        }
    }
    lv_keyboard_set_textarea(((lv_obj_t **)&objects)[startWidgetIndex + 21], ((lv_obj_t **)&objects)[startWidgetIndex + 18]);
}

void tick_user_widget_details(void *flowState, int startWidgetIndex) {
    (void)flowState;
    (void)startWidgetIndex;
}

void create_user_widget_panel_summary(lv_obj_t *parent_obj, void *flowState, int startWidgetIndex) {
    (void)flowState;
    (void)startWidgetIndex;
    lv_obj_t *obj = parent_obj;
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            ((lv_obj_t **)&objects)[startWidgetIndex + 0] = obj;
            lv_obj_set_pos(obj, 0, 0);
            lv_obj_set_size(obj, 400, 26);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
            add_style_panel_default(obj);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff282b30), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff626262), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, -17, -20);
                    lv_obj_set_size(obj, 133, 23);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_SPACE_EVENLY, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_INDICATOR | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // labelChannelNumber
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            ((lv_obj_t **)&objects)[startWidgetIndex + 1] = obj;
                            lv_obj_set_pos(obj, 0, 0);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            add_style_label15(obj);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffe9f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "Channel: 1");
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_line_create(parent_obj);
                    ((lv_obj_t **)&objects)[startWidgetIndex + 2] = obj;
                    lv_obj_set_pos(obj, 249, -20);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    static lv_point_precise_t line_points[] = {
                        { 0, 0 },
                        { 0, 26 }
                    };
                    lv_line_set_points(obj, line_points, 2);
                    lv_obj_set_style_line_color(obj, lv_color_hex(0xff626262), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 117, -20);
                    lv_obj_set_size(obj, 132, 23);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_SPACE_EVENLY, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // labelStage
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            ((lv_obj_t **)&objects)[startWidgetIndex + 3] = obj;
                            lv_obj_set_pos(obj, 115, -13);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            add_style_label15(obj);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffe9f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "Stage: Charge");
                        }
                        {
                            // ledStage
                            lv_obj_t *obj = lv_led_create(parent_obj);
                            ((lv_obj_t **)&objects)[startWidgetIndex + 4] = obj;
                            lv_obj_set_pos(obj, 0, 12);
                            lv_obj_set_size(obj, 5, 5);
                            lv_led_set_color(obj, lv_color_hex(0xff00ff00));
                            lv_led_set_brightness(obj, 255);
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_line_create(parent_obj);
                    ((lv_obj_t **)&objects)[startWidgetIndex + 5] = obj;
                    lv_obj_set_pos(obj, 116, -20);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    static lv_point_precise_t line_points[] = {
                        { 0, 0 },
                        { 0, 26 }
                    };
                    lv_line_set_points(obj, line_points, 2);
                    lv_obj_set_style_line_color(obj, lv_color_hex(0xff626262), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, 249, -20);
                    lv_obj_set_size(obj, 132, 23);
                    lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_layout(obj, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_SPACE_EVENLY, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // labelType
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            ((lv_obj_t **)&objects)[startWidgetIndex + 6] = obj;
                            lv_obj_set_pos(obj, 216, -13);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            add_style_label15(obj);
                            lv_obj_set_style_text_color(obj, lv_color_hex(0xffe9f4ff), LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "Type: Li-Ion");
                        }
                    }
                }
            }
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            ((lv_obj_t **)&objects)[startWidgetIndex + 7] = obj;
            lv_obj_set_pos(obj, 0, 24);
            lv_obj_set_size(obj, 400, 200);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
            add_style_panel_default(obj);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff626262), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff101316), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, -15, -12);
                    lv_obj_set_size(obj, 396, 70);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                    add_style_panel_parameters(obj);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, -5, -151);
                            lv_obj_set_size(obj, 132, 65);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                            add_style_container_parameters(obj);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    add_style_label15(obj);
                                    lv_label_set_text(obj, "Voltage");
                                }
                                {
                                    // labelVoltage
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    ((lv_obj_t **)&objects)[startWidgetIndex + 8] = obj;
                                    lv_obj_set_pos(obj, -18, 3);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    add_style_label30(obj);
                                    lv_obj_set_style_text_font(obj, &ui_font_chakra50, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "4.20V");
                                }
                            }
                        }
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, -5, -104);
                            lv_obj_set_size(obj, 132, 65);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                            add_style_container_parameters(obj);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    add_style_label15(obj);
                                    lv_label_set_text(obj, "Current");
                                }
                                {
                                    // labelCurrent
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    ((lv_obj_t **)&objects)[startWidgetIndex + 9] = obj;
                                    lv_obj_set_pos(obj, -18, 3);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    add_style_label30(obj);
                                    lv_obj_set_style_text_font(obj, &ui_font_chakra50, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "2.55A");
                                }
                            }
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, -15, 59);
                    lv_obj_set_size(obj, 396, 70);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                    add_style_panel_parameters(obj);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            lv_obj_t *obj = lv_obj_create(parent_obj);
                            lv_obj_set_pos(obj, -5, -191);
                            lv_obj_set_size(obj, 132, 65);
                            lv_obj_set_style_pad_left(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_right(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_pad_bottom(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_border_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                            add_style_container_parameters(obj);
                            {
                                lv_obj_t *parent_obj = obj;
                                {
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    lv_obj_set_pos(obj, 0, 0);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    add_style_label15(obj);
                                    lv_label_set_text(obj, "Temperature");
                                }
                                {
                                    // labelTemperature
                                    lv_obj_t *obj = lv_label_create(parent_obj);
                                    ((lv_obj_t **)&objects)[startWidgetIndex + 10] = obj;
                                    lv_obj_set_pos(obj, -18, 3);
                                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                                    add_style_label30(obj);
                                    lv_obj_set_style_text_font(obj, &ui_font_chakra50, LV_PART_MAIN | LV_STATE_DEFAULT);
                                    lv_label_set_text(obj, "50oC");
                                }
                            }
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_line_create(parent_obj);
                    ((lv_obj_t **)&objects)[startWidgetIndex + 11] = obj;
                    lv_obj_set_pos(obj, -17, 130);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    static lv_point_precise_t line_points[] = {
                        { 0, 0 },
                        { 400, 0 }
                    };
                    lv_line_set_points(obj, line_points, 2);
                    lv_obj_set_style_line_color(obj, lv_color_hex(0xff626262), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                {
                    // barProgressPercent
                    lv_obj_t *obj = lv_bar_create(parent_obj);
                    ((lv_obj_t **)&objects)[startWidgetIndex + 12] = obj;
                    lv_obj_set_pos(obj, -16, 137);
                    lv_obj_set_size(obj, 390, 18);
                    lv_bar_set_value(obj, 50, LV_ANIM_OFF);
                    add_style_bar_default(obj);
                    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // labelBarPercentt
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            ((lv_obj_t **)&objects)[startWidgetIndex + 13] = obj;
                            lv_obj_set_pos(obj, 181, 1);
                            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                            add_style_label15(obj);
                            lv_obj_set_style_blend_mode(obj, LV_BLEND_MODE_MULTIPLY, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "25%");
                        }
                    }
                }
                {
                    lv_obj_t *obj = lv_obj_create(parent_obj);
                    lv_obj_set_pos(obj, -15, 153);
                    lv_obj_set_size(obj, 396, 20);
                    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
                    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
                    add_style_panel_default(obj);
                    lv_obj_set_style_flex_flow(obj, LV_FLEX_FLOW_ROW, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_main_place(obj, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_cross_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_track_place(obj, LV_FLEX_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_flex_grow(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_bg_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
                    {
                        lv_obj_t *parent_obj = obj;
                        {
                            // labelEtaTime
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            ((lv_obj_t **)&objects)[startWidgetIndex + 14] = obj;
                            lv_obj_set_pos(obj, -17, -17);
                            lv_obj_set_size(obj, 186, LV_SIZE_CONTENT);
                            add_style_label15(obj);
                            lv_label_set_text(obj, "ETA: 92:52:11");
                        }
                        {
                            // labelElapsedTime
                            lv_obj_t *obj = lv_label_create(parent_obj);
                            ((lv_obj_t **)&objects)[startWidgetIndex + 15] = obj;
                            lv_obj_set_pos(obj, 223, -18);
                            lv_obj_set_size(obj, 140, LV_SIZE_CONTENT);
                            add_style_label15(obj);
                            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
                            lv_label_set_text(obj, "Elapsed: 92:52:11");
                        }
                    }
                }
            }
        }
    }
}

void tick_user_widget_panel_summary(void *flowState, int startWidgetIndex) {
    (void)flowState;
    (void)startWidgetIndex;
}


extern void add_style(lv_obj_t *obj, int32_t styleIndex);
extern void remove_style(lv_obj_t *obj, int32_t styleIndex);

static const char *screen_names[] = { "Main", "test" };
static const char *object_names[] = { "main", "test", "main_tabview", "arc1", "label1", "obj0", "obj1" };
static const char *style_names[] = { "Label30", "panelDefault", "Label15", "panelParameters", "containerParameters", "barDefault", "defaultScale" };


typedef void (*create_screen_func_t)();
create_screen_func_t create_screen_funcs[] = {
    create_screen_main,
    create_screen_test,
};
void create_screen(int screen_index) {
    create_screen_funcs[screen_index]();
}
void create_screen_by_id(enum ScreensEnum screenId) {
    create_screen_funcs[screenId - 1]();
}

typedef void (*delete_screen_func_t)();
delete_screen_func_t delete_screen_funcs[] = {
    delete_screen_main,
    delete_screen_test,
};
void delete_screen(int screen_index) {
    delete_screen_funcs[screen_index]();
}
void delete_screen_by_id(enum ScreensEnum screenId) {
    delete_screen_funcs[screenId - 1]();
}

typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
    tick_screen_test,
};
void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen_funcs[screenId - 1]();
}

void create_screens() {
    eez_flow_init_styles(add_style, remove_style);
    
    eez_flow_init_screen_names(screen_names, sizeof(screen_names) / sizeof(const char *));
    eez_flow_init_object_names(object_names, sizeof(object_names) / sizeof(const char *));
    eez_flow_init_style_names(style_names, sizeof(style_names) / sizeof(const char *));
    
    eez_flow_set_create_screen_func(create_screen);
    eez_flow_set_delete_screen_func(delete_screen);
    
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main();
    create_screen_test();
}
