/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** create_interface.c
*/

#include "engine.h"
#include "my.h"
#include "var.h"

void create_interface(var_t *var)
{
    create_object("Warning_build.png", "warning_build", 9);
    set_position_tag("warning_build", (V2f){engine.win_settings.size.x - get_size_tag("warning_build").x - 40, 150});
    set_shape_tag("warning_build", (sfIntRect){220, 0, 220, 52}, true);
    set_visible_tag("warning_build", false);
}
