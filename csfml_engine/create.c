/*
** EPITECH PROJECT, 2021
** CSFML engine
** File description:
** create.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void create_enemies(var_t *var, engine_t *engine)
{
    static int i = 1020;
    sfVector2f *path = random_this((sfVector2f[6]){{860, 640}, {1135, 480}, {1110, 445}, {1310, 315}, {1040, 170}, {470, 440}}, 6);

    var->enemies = create_object("player.png", "enemies", 9, engine);
    set_shape_obj(&var->enemies, (sfIntRect){0, 48, 48, 48}, true, engine);
    set_position_obj(var->enemies, (sfVector2f){i, 750}, engine);
    set_enemy_obj(&var->enemies, path, engine);
}

void create(var_t *var, engine_t *engine)
{
    set_background("background.png", true, engine);
    create_object("map.png", "map", 10, engine);
    set_fps(true, 15, sfBlack, engine);
    for (int i = 0; i != 15; i++)
        create_enemies(var, engine);
}
