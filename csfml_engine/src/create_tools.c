/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** create_tools.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void create_tools(var_t *var)
{
    create_object("btools.png", "btools", 9);
    set_position_tag("btools", (V2f){150, get_position_tag("constructMenu").y - 5});
    set_shape_tag("btools", (sfIntRect){0, 0, 87, 85}, true);
}
