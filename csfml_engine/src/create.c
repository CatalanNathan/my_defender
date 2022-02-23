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
    init_system(var);
    create_loop_game(var);
}
