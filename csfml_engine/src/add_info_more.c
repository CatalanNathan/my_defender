/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** add_info_more.c
*/

#include "engine.h"
#include "var.h"
#include "my.h"

void add_info_more(var_t *var, float time_pass, int *i, char *info)
{
    var->info_more = true;
    set_text_tag("info+", info);
    set_text_position_tag("info+", (V2f){get_position_tag("info+").x + 5, get_position_tag("info+").y});
    set_position_tag("info+", (V2f){sfMouse_getPositionRenderWindow(engine.win_settings.window).x - get_size_tag("info+").x/2 + 5, sfMouse_getPositionRenderWindow(engine.win_settings.window).y - (get_text_shape_tag("info+").height + 50)});
    set_visible_tag("info+", true);
    for (; (float)get_size_tag("info+").x < get_text_shape_tag("info+").width + 10;)
        set_scale_tag("info+", (V2f){get_scale_tag("info+").x + 0.001, get_scale_tag("info+").y});
    for (; (float)get_size_tag("info+").y < get_text_shape_tag("info+").height + 5;)
        set_scale_tag("info+", (V2f){get_scale_tag("info+").x, get_scale_tag("info+").y + 0.001});
    for (; (float)get_size_tag("info+").x > get_text_shape_tag("info+").width + 10;)
        set_scale_tag("info+", (V2f){get_scale_tag("info+").x - 0.001, get_scale_tag("info+").y});
    for (; (float)get_size_tag("info+").y > get_text_shape_tag("info+").height + 5;)
        set_scale_tag("info+", (V2f){get_scale_tag("info+").x, get_scale_tag("info+").y - 0.001});
    set_text_visible_tag("info+", true);
}
