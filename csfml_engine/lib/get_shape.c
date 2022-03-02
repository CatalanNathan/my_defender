/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** get_shape.c
*/

#include "my.h"
#include "engine.h"

sfIntRect get_shape_tag(char *tag)
{
    node_t *start = engine.game.list;
    sfIntRect rect;

    while (engine.game.list != NULL) {
        if (equal(engine.game.list->settings.tag, tag) == true) {
            rect = sfSprite_getTextureRect(engine.game.list->settings.sprite);
            engine.game.list = start;
            return rect;
        }
        engine.game.list = engine.game.list->previous;
    }
    engine.game.list = start;
    return (sfIntRect){0, 0, 0, 0};
}

sfIntRect get_shape_obj(obj_t *obj)
{
    node_t *start = engine.game.list;

    while (engine.game.list != NULL) {
        if (engine.game.list->settings.id == obj->id) {
            obj->shape = sfSprite_getTextureRect(
            engine.game.list->settings.sprite);
            engine.game.list = start;
            return obj->shape;
        }
        engine.game.list = engine.game.list->previous;
    }
    engine.game.list = start;
    return (sfIntRect){0, 0, 0, 0};
}
