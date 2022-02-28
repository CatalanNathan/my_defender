/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** set_gravity.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void set_gravity_tag(char *tag, bool gravity)
{
    node_t *start = engine.game.list;

    while (engine.game.list != NULL) {
        if (equal(engine.game.list->settings.tag, tag) == true)
            engine.game.list->settings.gravity = gravity;
        engine.game.list = engine.game.list->previous;
    }
    engine.game.list = start;
}

void set_gravity_obj(obj_t *obj, bool gravity)
{
    node_t *start = engine.game.list;

    while (engine.game.list != NULL) {
        if (obj->id == engine.game.list->settings.id) {
            engine.game.list->settings.gravity = gravity;
            obj->gravity = gravity;
        }
        engine.game.list = engine.game.list->previous;
    }
    engine.game.list = start;
}
