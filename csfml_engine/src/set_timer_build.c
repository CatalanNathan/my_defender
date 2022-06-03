/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-guillaume.kucia
** File description:
** set_timer_build.c
*/

#include "engine.h"
#include "var.h"
#include "my.h"

void set_timer_build(int *i, float *timer, var_t *var)
{
    *i = var->tower.tower_selected;
    if (*i == 1)
        *timer = 10;
    if (*i == 2)
        *timer = 15;
    if (*i == 3)
        *timer = 25;
}
