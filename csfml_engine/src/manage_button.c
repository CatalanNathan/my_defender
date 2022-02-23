/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** manage_button
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void first_wall(var_t *var, int *action)
{
    if (mouse_inside_tag("btn_wall_1")) {
        set_shape_tag("btn_wall_1", (sfIntRect){get_size_tag("btn_wall_1").x, 0, get_size_tag("btn_wall_1").x, get_size_tag("btn_wall_1").y}, true);
        set_position_tag("money_bar", (V2f){sfMouse_getPositionRenderWindow(engine.win_settings.window).x - get_size_tag("money_bar").x/2,sfMouse_getPositionRenderWindow(engine.win_settings.window).y - 50});
        set_visible_tag("money_bar", true);
        if (mouse_pressed(sfMouseLeft)) {
            set_exits_tag("wall_1", true);
            set_exits_tag("btn_wall_1", false);
        }
        *action += 1;
    } else
        set_shape_tag("btn_wall_1",(sfIntRect){0, 0, get_size_tag("btn_wall_1").x, get_size_tag("btn_wall_1").y}, true);
}

void second_wall(var_t *var, int *action)
{
    if (mouse_inside_tag("btn_wall_2")) {
        set_shape_tag("btn_wall_2", (sfIntRect){get_size_tag("btn_wall_2").x, 0, get_size_tag("btn_wall_2").x, get_size_tag("btn_wall_2").y}, true);
        set_position_tag("money_bar", (V2f){sfMouse_getPositionRenderWindow(engine.win_settings.window).x - get_size_tag("money_bar").x/2,sfMouse_getPositionRenderWindow(engine.win_settings.window).y - 50});
        set_visible_tag("money_bar", true);
        if (mouse_pressed(sfMouseLeft))
            set_exits_tag("wall_2", true);
        *action += 1;
    } else
        set_shape_tag("btn_wall_2",(sfIntRect){0, 0, get_size_tag("btn_wall_2").x, get_size_tag("btn_wall_2").y}, true);
}

void third_wall(var_t *var, int *action)
{
    if (mouse_inside_tag("btn_wall_3")) {
        set_shape_tag("btn_wall_3", (sfIntRect){get_size_tag("btn_wall_3").x, 0, get_size_tag("btn_wall_3").x, get_size_tag("btn_wall_3").y}, true);
        set_position_tag("money_bar", (V2f){sfMouse_getPositionRenderWindow(engine.win_settings.window).x - get_size_tag("money_bar").x/2,sfMouse_getPositionRenderWindow(engine.win_settings.window).y - 50});
        set_visible_tag("money_bar", true);
        if (mouse_pressed(sfMouseLeft))
            set_exits_tag("wall_3", true);
        *action += 1;
    } else
        set_shape_tag("btn_wall_3",(sfIntRect){0, 0, get_size_tag("btn_wall_3").x, get_size_tag("btn_wall_3").y}, true);
}

void manage_button(var_t *var)
{
    int action = 0;

    first_wall(var, &action);
    second_wall(var, &action);
    third_wall(var, &action);
    if (action == 0)
        set_visible_tag("money_bar", false);
}
