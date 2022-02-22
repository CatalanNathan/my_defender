/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** manage_button
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void manage_button(var_t *var)
{
    obj_t button = mouse_inside_more("button_wall");
    if (button.id < 0) {
        set_shape_tag("button_wall",(sfIntRect){0, 0, get_size_tag("button_wall").x, get_size_tag("button_wall").y}, true);
        set_visible_tag("money_bar", false);
        return;
    }
    set_shape_obj(&button, (sfIntRect){get_size_obj(&button).x, 0, get_size_obj(&button).x, get_size_obj(&button).y}, true);
    set_position_tag("money_bar", (V2f){sfMouse_getPositionRenderWindow(engine.win_settings.window).x - get_size_tag("money_bar").x/2,sfMouse_getPositionRenderWindow(engine.win_settings.window).y - 50});
    set_visible_tag("money_bar", true);
}
