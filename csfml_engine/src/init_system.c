/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** init_system.c
*/

#include "engine.h"
#include "var.h"
#include "my.h"

void init_system(var_t *var)
{
    set_background("background.png", true);
    set_fps(true, 15, sfBlack);
    create_object("map.png", "map", 10);
    set_position_tag("map", (V2f){engine.win_settings.middle_screen.x/2 - get_size_tag("map").x/2, engine.win_settings.middle_screen.y/2 - get_size_tag("map").y/2});
    create_object("cursor.png", "cursor", 0);
    set_scale_tag("cursor", (V2f){0.2, 0.2});
    set_shape_tag("cursor", (sfIntRect){0, 0, 173, 177}, true);
    sfRenderWindow_setMouseCursorVisible(engine.win_settings.window, sfFalse);
}
