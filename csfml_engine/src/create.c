/*
** EPITECH PROJECT, 2021
** CSFML engine
** File description:
** create.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void create_enemies(var_t *var)
{
    static int i = 1020;
    V2f *path = random_this((V2f[6]){{860, 640}, {1135, 480}, {1110, 445}, {1310, 315}, {1040, 170}, {470, 440}}, 6);

    var->enemies = create_object("player.png", "enemies", 9);
    set_shape_obj(&var->enemies, (sfIntRect){0, 48, 48, 48}, true);
    set_position_obj(var->enemies, (V2f){i, 750});
    set_enemy_obj(&var->enemies, path);
}

void create(var_t *var)
{
    set_background("background.png", true);
    create_object("map.png", "map", 10);
    set_position_tag("map", (V2f){engine.win_settings.middle_screen.x/2 - get_size_tag("map").x/2, engine.win_settings.middle_screen.y/2 - get_size_tag("map").y/2});
    set_fps(true, 15, sfBlack);
    for (int i = 0; i != 15; i++)
        create_enemies(var);
}
