/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** resize_parallax_hg.c
*/

#include "engine.h"
#include "var.h"
#include "my.h"

void resize_parallax_hg(obj_t *obj)
{
    while (obj->size.x < engine.win_settings.size.x) {
        sfSprite_setScale(obj->sprite, (V2f){sfSprite_getScale(obj->sprite).x
        + 0.01, 1});
        obj->size.x = sfTexture_getSize(obj->texture).x *
        sfSprite_getScale(obj->sprite).x;
    }
    while (obj->size.y < engine.win_settings.size.y) {
        sfSprite_setScale(obj->sprite, (V2f){sfSprite_getScale(obj->sprite).x,
        sfSprite_getScale(obj->sprite).y + 0.01});
        obj->size.y = sfTexture_getSize(obj->texture).y *
        sfSprite_getScale(obj->sprite).y;
    }
}
