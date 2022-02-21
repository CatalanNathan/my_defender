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
    var->enemies = create_object("player.png", "enemies", 9, engine);
    set_shape_obj(&var->enemies, (sfIntRect){0, 48, 48, 48}, true, engine);
    set_position_obj(var->enemies, (sfVector2f){1020, 750}, engine);
}

void create(var_t *var, engine_t *engine)
{
    set_background("background.png", true, engine);
    create_object("map.png", "map", 10, engine);
    set_fps(true, 15, sfBlack, engine);
    create_enemies(var, engine);
}
