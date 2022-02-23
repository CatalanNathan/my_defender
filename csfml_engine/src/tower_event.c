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

    object = copy_object_tag("Tower_1");
    if (mouse_inside_tag("Tower_1") && var->thor_mod == true)
        sfSprite_setColor(object.sprite, sfYellow);
    else
        sfSprite_setColor(object.sprite, var->color_tower);
}
