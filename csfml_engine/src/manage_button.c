/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** manage_button
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void set_shape_wall(char *tag, int *i);

void info_wall(char *tag, var_t *var)
{
    set_shape_tag(tag, (sfIntRect){get_size_tag(tag).x, 0,
    get_size_tag(tag).x, get_size_tag(tag).y}, true);
    set_position_tag("money_bar", (V2f){
    sfMouse_getPositionRenderWindow(engine.win_settings.window).x -
    get_size_tag("money_bar").x / 2,
    sfMouse_getPositionRenderWindow(engine.win_settings.window).y - 50});
    set_visible_tag("money_bar", true);
    set_text_position_tag("price_wall", (V2f){get_position_tag("money_bar").x
    + get_size_tag("money_bar").x / 2 - (5 * int_size(var->price_wall)),
    get_position_tag("money_bar").y + 5});
    set_text_visible_tag("price_wall", true);
}

void first_wall(var_t *var, int *action)
{
    static int i = 0;
    static float incrementation = 0.00;
    static float save = 0.00;

    update_button_exists("wall_1", "btn_wall_1", &incrementation, &save);
    if (var->thor_mod == true)
        return;
    if (mouse_inside_tag("btn_wall_1") && get_exits_tag("btn_wall_1")) {
        info_wall("btn_wall_1", var);
        change_cursor(var, "cursor");
        if (mouse_pressed(sfMouseLeft, &i) &&
            var->money -var->price_wall >= 0) {
            set_exits_tag("wall_1", true);
            set_exits_tag("btn_wall_1", false);
            set_exits_tag("clock_wall1", true);
            var->money -= var->price_wall;
        }
        *action += 1;
        return;
    }
    set_shape_wall("btn_wall_1", &i);
}

void second_wall(var_t *var, int *action)
{
    static int i = 0;
    static float incrementation = 0.00;
    static float save = 0.00;

    update_button_exists("wall_2", "btn_wall_2", &incrementation, &save);
    if (var->thor_mod == true)
        return;
    if (mouse_inside_tag("btn_wall_2") && get_exits_tag("btn_wall_2")) {
        info_wall("btn_wall_2", var);
        change_cursor(var, "cursor");
        if (mouse_pressed(sfMouseLeft, &i) &&
            var->money - var->price_wall >= 0) {
            set_exits_tag("wall_2", true);
            set_exits_tag("btn_wall_2", false);
            set_exits_tag("clock_wall2", true);
            var->money -= var->price_wall;
        }
        *action += 1;
        return;
    }
    set_shape_wall("btn_wall_2", &i);
}

void third_wall(var_t *var, int *action)
{
    static int i = 0;
    static float incrementation = 0.00;
    static float save = 0.00;

    update_button_exists("wall_3", "btn_wall_3", &incrementation, &save);
    if (var->thor_mod == true)
        return;
    if (mouse_inside_tag("btn_wall_3") && get_exits_tag("btn_wall_3")) {
        info_wall("btn_wall_3", var);
        change_cursor(var, "cursor");
        if (mouse_pressed(sfMouseLeft, &i) &&
            var->money - var->price_wall >= 0) {
            set_exits_tag("wall_3", true);
            set_exits_tag("btn_wall_3", false);
            set_exits_tag("clock_wall3", true);
            var->money -= var->price_wall;
        }
        *action += 1;
        return;
    }
    set_shape_wall("btn_wall_3", &i);
}

void manage_button(var_t *var)
{
    int action = 0;
    if (var->pause)
        return;

    if (var->destroy_mod == false) {
        first_wall(var, &action);
        second_wall(var, &action);
        third_wall(var, &action);
    }
    if (action == 0) {
        set_visible_tag("money_bar", false);
        set_text_visible_tag("price_wall", false);
    }
    selected_button_tower(var);
    selecte_button_delete(var);
    btn_settings(var);
}
