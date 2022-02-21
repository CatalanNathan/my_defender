/*
** EPITECH PROJECT, 2021
** CSFML engine
** File description:
** create.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void create(var_t *var, engine_t *engine)
{
    set_background("background.png", true, engine);
    create_object("map.png", "map", 10, engine);
    set_fps(true, 20, sfBlack, engine);
}
