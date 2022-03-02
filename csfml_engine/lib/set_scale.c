/*
** EPITECH PROJECT, 2021
** CSFML engine
** File description:
** set_scale.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void set_scale_tag(char *tag, V2f scale)
{
    node_t *start = engine.game.list;

    while (engine.game.list != NULL) {
        if (equal(engine.game.list->settings.tag, tag) == true) {
            sfSprite_setScale(engine.game.list->settings.sprite, scale);
            engine.game.list->settings.size.x = (sfTexture_getSize(
            engine.game.list->settings.texture).x * scale.x);
            engine.game.list->settings.size.y = (sfTexture_getSize(
            engine.game.list->settings.texture).y * scale.y);
        }
        engine.game.list = engine.game.list->previous;
    }
    engine.game.list = start;
}

void set_scale_obj(obj_t *obj, V2f scale)
{
    node_t *start = engine.game.list;

    sfSprite_setScale(obj->sprite, scale);
    obj->size.x = (sfTexture_getSize(obj->texture).x * scale.x);
    obj->size.y = (sfTexture_getSize(obj->texture).y * scale.y);
    while (engine.game.list != NULL) {
        if (obj->id == engine.game.list->settings.id) {
            sfSprite_setScale(engine.game.list->settings.sprite, scale);
            engine.game.list->settings.size.x = (sfTexture_getSize(
            engine.game.list->settings.texture).x * scale.x);
            engine.game.list->settings.size.y = (sfTexture_getSize(
            engine.game.list->settings.texture).y * scale.y);
        }
        engine.game.list = engine.game.list->previous;
    }
    engine.game.list = start;
}
