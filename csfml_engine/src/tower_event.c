/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** tower_event.c
*/

#include "engine.h"
#include "my.h"
#include "var.h"

void tower_event(var_t *var)
{
    obj_t object;
    char *tower = my_strdup("Tower_1.1");
    char e = '1';

    while (e != '6') {
        object = copy_object_tag(tower);
        if (mouse_inside_tag(tower) && var->thor_mod == true)
            sfSprite_setColor(object.sprite, sfYellow);
        else
            sfSprite_setColor(object.sprite, var->color_tower);
        e++;
        tower[8] = e;
    }
}
