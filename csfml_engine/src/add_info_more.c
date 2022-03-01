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
    // if (*i == 0) {
    //     set_scale_tag("info+", (V2f){1, 0});
    //     *i = 1;
    // }
    // var->info_more = true;
    // set_text_tag("info+", info);
    // set_text_position_tag("info+", (V2f){get_position_tag("info+").x + get_size_tag("info+").x/2 - (my_strlen(info) * 2.1), get_position_tag("info+").y + get_size_tag("info+").y/3 - 12});
    // set_position_tag("info+", (V2f){sfMouse_getPositionRenderWindow(engine.win_settings.window).x - get_size_tag("info+").x/2 + 5, sfMouse_getPositionRenderWindow(engine.win_settings.window).y - (my_spacelen(info) + 1)*80});
    // set_visible_tag("info+", true);
    // if (get_scale_tag("info+").y < (1 + my_spacelen(info)/2))
    //     set_scale_tag("info+", (V2f){get_scale_tag("info+").x, get_scale_tag("info+").y + (0.000006 * time_pass)});
    // else
    //     set_text_visible_tag("info+", true);
    // set_scale_tag("info+", (V2f){my_strlen(info) * 0.05, get_scale_tag("info+").y});
}
