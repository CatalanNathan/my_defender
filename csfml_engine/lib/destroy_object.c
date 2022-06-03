/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** destroy_object.c
*/

#include "my.h"
#include "engine.h"

void destroy_this2(void)
{
    if (engine.game.list->next != NULL && engine.game.list->previous == NULL)
        engine.game.list->next->previous = NULL;
    sfSprite_destroy(engine.game.list->settings.sprite);
    sfTexture_destroy(engine.game.list->settings.texture);
    engine.game.list = NULL;
}

void destroy_this(node_t *start)
{
    if (engine.game.list->next != NULL && engine.game.list->previous != NULL) {
        engine.game.list->next->previous = engine.game.list->previous;
        engine.game.list->previous->next = engine.game.list->next;
        sfSprite_destroy(engine.game.list->settings.sprite);
        sfTexture_destroy(engine.game.list->settings.texture);
        engine.game.list = start;
        return;
    } else if (engine.game.list->next == NULL &&
        engine.game.list->previous != NULL) {
        engine.game.list->previous->next = NULL;
        sfSprite_destroy(engine.game.list->settings.sprite);
        sfTexture_destroy(engine.game.list->settings.texture);
        engine.game.list = engine.game.list->previous;
        return;
    }
    destroy_this2();
}

void destroy_object(int id)
{
    node_t *start = engine.game.list;

    while (engine.game.list != NULL) {
        if (engine.game.list->settings.id == id) {
            destroy_this(start);
            return;
        }
        engine.game.list = engine.game.list->previous;
    }
    engine.game.list = start;
}

void destroy_object_tag(char *tag)
{
    node_t *start = engine.game.list;

    while (engine.game.list != NULL) {
        if (equal(engine.game.list->settings.tag, tag)) {
            destroy_this(start);
            return;
        }
        engine.game.list = engine.game.list->previous;
    }
    engine.game.list = start;
}
