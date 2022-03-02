/*
** EPITECH PROJECT, 2021
** CSFML engine
** File description:
** object_size.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void shape_selected(engine_t engine)
{
    if (engine.game.list->settings.ishape == false) {
        engine.game.list->settings.size.x = sfTexture_getSize(engine.
        game.list->settings.texture).x * sfSprite_getScale(engine.
        game.list->settings.sprite).x;
        engine.game.list->settings.size.y = sfTexture_getSize(engine.
        game.list->settings.texture).y * sfSprite_getScale(engine.
        game.list->settings.sprite).y;
    } else {
        engine.game.list->settings.size.x = engine.game.list->settings.
        shape.width;
        engine.game.list->settings.size.y = engine.game.list->settings.
        shape.height;
    }
}

sfVector2u get_size_tag(char *tag)
{
    node_t *start = engine.game.list;
    sfVector2u size;

    while (engine.game.list != NULL) {
        if (equal(engine.game.list->settings.tag, tag)) {
            shape_selected(engine);
            size = engine.game.list->settings.size;
            engine.game.list = start;
            return size;
        }
        engine.game.list = engine.game.list->previous;
    }
    engine.game.list = start;
    return (sfVector2u){0, 0};
}

sfVector2u get_size_obj(obj_t *obj)
{
    if (obj->ishape == false) {
        obj->size.x = sfTexture_getSize(obj->texture).x *
        sfSprite_getScale(obj->sprite).x;
        obj->size.y = sfTexture_getSize(obj->texture).y *
        sfSprite_getScale(obj->sprite).y;
    } else {
        obj->size.x = obj->shape.width;
        obj->size.y = obj->shape.height;
    }
    return obj->size;
}
