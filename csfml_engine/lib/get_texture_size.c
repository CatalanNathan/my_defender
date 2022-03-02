/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** get_origin_size.c
*/

#include "my.h"
#include "engine.h"

sfVector2u get_texture_size_tag(char *tag)
{
    node_t *start = engine.game.list;
    sfVector2u size;

    while (engine.game.list != NULL) {
        if (equal(engine.game.list->settings.tag, tag) == true) {
            size.x = sfTexture_getSize(engine.game.list->settings.texture).x *
            sfSprite_getScale(engine.game.list->settings.sprite).x;
            size.y = sfTexture_getSize(engine.game.list->settings.texture).y *
            sfSprite_getScale(engine.game.list->settings.sprite).y;
            engine.game.list->settings.size = size;
            engine.game.list = start;
            return size;
        }
        engine.game.list = engine.game.list->previous;
    }
    engine.game.list = start;
    return (sfVector2u){0, 0};
}

sfVector2u get_texture_size_obj(obj_t *obj)
{
    obj->size.x = sfTexture_getSize(obj->texture).x *
    sfSprite_getScale(obj->sprite).x;
    obj->size.y = sfTexture_getSize(obj->texture).y *
    sfSprite_getScale(obj->sprite).y;
    return obj->size;
}
