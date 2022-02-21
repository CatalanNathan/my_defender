/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** set_visible.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void set_visible_tag(char *tag, bool visible)
{
    node_t *start = engine.game.list;

    while (engine.game.list != NULL) {
        if (equal(engine.game.list->settings.tag, tag) == true)
            engine.game.list->settings.display = visible;
        engine.game.list = engine.game.list->previous;
    }
    engine.game.list = start;
}

void set_visible_obj(obj_t *obj, bool visible)
{
    node_t *start = engine.game.list;

    obj->display = visible;
    while (engine.game.list != NULL) {
        if (engine.game.list->settings.id == obj->id)
            engine.game.list->settings.display = visible;
        engine.game.list = engine.game.list->previous;
    }
    engine.game.list = start;
}
