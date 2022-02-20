/*
** EPITECH PROJECT, 2021
** CSFML engine
** File description:
** update.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void update(var_t *var, engine_t *engine)
{
    if (key_pressed(sfKeyEscape, engine))
        game_end(0, engine);
}
