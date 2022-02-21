/*
** EPITECH PROJECT, 2021
** CSFML engine
** File description:
** update.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void system_function(var_t *var)
{
    if (key_pressed(sfKeyEscape))
        game_end(0);
}

void update(var_t *var)
{
    system_function(var);
    manage_enemy(var);
}
