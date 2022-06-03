/*
** EPITECH PROJECT, 2021
** CSFML engine
** File description:
** create.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void init_menu(var_t *var)
{
    static int i = 0;

    if (i == 1)
        return;
    var->global_menu = true;
    var->m =     '1';
    var->volume = 100;
    i = 1;
}

void create(var_t *var)
{
    int e = 0;
    long int a = (long int)&e;

    init_menu(var);
    if (!var->global_menu) {
        srand(a);
        init_system(var);
        create_loop_game(var);
    } else {
        create_menu(var);
    }
}
