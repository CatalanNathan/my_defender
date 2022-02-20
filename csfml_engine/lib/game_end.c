/*
** EPITECH PROJECT, 2021
** CSFML engine
** File description:
** game_end.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void game_end(int value, engine_t *engine)
{
    engine->game.game_end = true;
    engine->game.end_value = value;
}
