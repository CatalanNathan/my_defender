/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** mouse_event.c
*/

#include "engine.h"
#include "var.h"
#include "my.h"

void mouse_event(var_t *var)
{
    static int mouse_right = 0.00;

    if (var->thor_mod == true) {
        set_exits_tag("thor", true);
        set_exits_tag("cursor", false);
        set_position_tag("thor", (V2f){sfMouse_getPositionRenderWindow(engine.win_settings.window).x - 20, sfMouse_getPositionRenderWindow(engine.win_settings.window).y - 20});
    } else {
        set_exits_tag("thor", false);
        set_exits_tag("cursor", true);
    }

    if (mouse_pressed(sfMouseRight, &mouse_right) && get_exits_tag("thor"))
        var->thor_mod = false;
}
