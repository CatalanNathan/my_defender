/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** copy_object.c
*/

#include "my.h"
#include "engine.h"

obj_t copy_object(int id)
{
    int new_id = -1;
    node_t *start = engine.game.list;
    obj_t object;

    object.id = new_id;
    while (engine.game.list != NULL) {
        if (engine.game.list->settings.id == id) {
            object = engine.game.list->settings;
            engine.game.list = start;
            return object;
        }
        engine.game.list = engine.game.list->previous;
    }
    engine.game.list = start;
    return object;
}

obj_t copy_object_tag(char *tag)
{
    node_t *start = engine.game.list;
    obj_t object;

    while (engine.game.list != NULL) {
        if (equal(engine.game.list->settings.tag, tag)) {
            object = engine.game.list->settings;
            engine.game.list = start;
            return object;
        }
        engine.game.list = engine.game.list->previous;
    }
    engine.game.list = start;
    object.id = -1;
    return object;
}
