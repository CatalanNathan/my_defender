/*
** EPITECH PROJECT, 2021
** CSFML engine
** File description:
** create.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void create(var_t *var)
{
    srand(time(NULL));
    var->castle_life = 1000;
    var->nb_enemies = 20;
    create_loop_game(var);
}
