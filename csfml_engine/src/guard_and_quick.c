/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-guillaume.kucia
** File description:
** guard_and_quick.c
*/

#include "engine.h"
#include "my.h"
#include "var.h"

void guard_and_quick(int i, int *guard, int *quick)
{
    if (i == 1 || i == 0) {
        *guard = 2;
        *quick = 8;
    }
    if (i == 2) {
        *guard = 3;
        *quick = 12;
    }
    if (i == 3) {
        *guard = 5;
        *quick = 20;
    }
}
