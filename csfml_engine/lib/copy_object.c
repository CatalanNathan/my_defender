/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** copy_object.c
*/

#include "my.h"
#include "engine.h"

obj_t copy_object(int id, engine_t *engine)
{
    int new_id = -1;
    node_t *start = engine->game.list;
    obj_t object;

    object.id = new_id;
    while (engine->game.list != NULL) {
        if (engine->game.list->settings.id == id) {
            object = engine->game.list->settings;
            engine->game.list = start;
            return object;
        }
        engine->game.list = engine->game.list->previous;
    }
    engine->game.list = start;
    return object;
}
