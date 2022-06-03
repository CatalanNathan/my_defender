/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** random_this.c
*/

#include "engine.h"

sfVector2f *random_this(sfVector2f *value, int n)
{
    sfVector2f *path = malloc(sizeof(sfVector2f) * n);

    for (int i = 0; i < n; i++) {
        path[i].x = (rand() % (((int)value[i].x + 8)
        - ((int)value[i].x - 10) + 1) + ((int)value[i].x - 8));
        path[i].y = (rand() % (((int)value[i].y + 8)
        - ((int)value[i].y - 10) + 1) + ((int)value[i].y - 8));
    }
    return path;
}
