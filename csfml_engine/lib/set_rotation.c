/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** set_rotation.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void set_rotation_tag(char *tag, float angle)
{
    node_t *start = engine.game.list;

    while (engine.game.list != NULL) {
        if (equal(engine.game.list->settings.tag, tag) == true)
            sfSprite_rotate(engine.game.list->settings.sprite, angle);
        engine.game.list = engine.game.list->previous;
    }
    engine.game.list = start;
}

void set_rotation_obj(obj_t *obj, float angle)
{
    node_t *start = engine.game.list;

    obj->angle = angle;
    while (engine.game.list != NULL) {
        if (engine.game.list->settings.id == obj->id)
            sfSprite_rotate(engine.game.list->settings.sprite, angle);
        engine.game.list = engine.game.list->previous;
    }
    engine.game.list = start;
}
