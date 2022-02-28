/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** mouse_event.c
*/

#include "engine.h"
#include "var.h"
#include "my.h"

void warning_true(int *e, float time)
{
    if (*e == 0) {
        set_shape_tag("warning_build", (sfIntRect){220, 0, 220, 52}, true);
        set_visible_tag("warning_build", true);
        *e = 1;
    }
    if (get_shape_tag("warning_build").left >= 0) {
        set_shape_tag("warning_build", (sfIntRect){get_shape_tag("warning_build").left - (0.001 * time), 0, get_size_tag("warning_build").x ,get_shape_tag("warning_build").height}, true);
        set_position_tag("warning_build", (V2f){get_position_tag("warning_build").x - (0.0005 * time), get_position_tag("warning_build").y});
    }

}

void warning_false(int *e, float time)
{
    *e = 0;
    if (get_shape_tag("warning_build").left <= (int)get_size_tag("warning_build").x) {
        set_shape_tag("warning_build", (sfIntRect){get_shape_tag("warning_build").left + (0.001 * time), 0, get_size_tag("warning_build").x ,get_shape_tag("warning_build").height}, true);
        set_position_tag("warning_build", (V2f){get_position_tag("warning_build").x + (0.0005 * time), get_position_tag("warning_build").y});
    } else if (get_shape_tag("warning_build").left >= (int)get_size_tag("warning_build").x) {
        set_visible_tag("warning_build", false);
        set_position_tag("warning_build", (V2f){engine.win_settings.size.x - 190, 150});
    }

}

void mouse_event(var_t *var)
{
    static int mouse_right = 0.00;
    static int e = 0;
    static float time = 0.00;
    static float save = 0.00;

    get_elapsed_time(&time, &save);
    if (var->thor_mod == true) {
        set_exits_tag("thor", true);
        set_exits_tag("cursor", false);
        set_position_tag("thor", (V2f){sfMouse_getPositionRenderWindow(engine.win_settings.window).x - 20, sfMouse_getPositionRenderWindow(engine.win_settings.window).y - 20});
        warning_true(&e, time);
    } else {
        set_exits_tag("thor", false);
        set_exits_tag("cursor", true);
        warning_false(&e, time);
    }
    if (mouse_pressed(sfMouseRight, &mouse_right) && get_exits_tag("thor"))
        var->thor_mod = false;
}
