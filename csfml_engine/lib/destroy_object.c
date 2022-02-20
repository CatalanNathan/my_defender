/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** destroy_object.c
*/

#include "my.h"
#include "engine.h"

void destroy_this(engine_t *engine, node_t *save)
{
    if (save != NULL && engine->game.list->previous != NULL) {
        save->previous = engine->game.list->previous;
        engine->game.list->previous->next = save;
    } else if (save == NULL && engine->game.list->previous != NULL)
        engine->game.list->previous->next = NULL;
    else if (save != NULL && engine->game.list->previous == NULL)
        save->previous = NULL;

    sfSprite_destroy(engine->game.list->settings.sprite);
    sfTexture_destroy(engine->game.list->settings.texture);
    engine->game.list = NULL;
    return;
}

void destroy_object(int id, engine_t *engine)
{
    node_t *start = engine->game.list;
    node_t *save = engine->game.list;

    while (engine->game.list != NULL) {
        if (engine->game.list->settings.id == id) {
            destroy_this(engine, save);
            return;
        }
        save = engine->game.list;
        engine->game.list = engine->game.list->previous;
    }
    engine->game.list = start;
}
