/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** set_shape.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void set_shape_tag(char *tag, sfIntRect shape, bool ishape)
{
    node_t *start = engine.game.list;

    while (engine.game.list != NULL) {
        if (equal(engine.game.list->settings.tag, tag) == true) {
            engine.game.list->settings.ishape = ishape;
            engine.game.list->settings.shape = shape;
        }
        engine.game.list = engine.game.list->previous;
    }
    engine.game.list = start;
}

void set_shape_obj(obj_t *obj, sfIntRect shape, bool ishape)
{
    node_t *start = engine.game.list;

    obj->ishape = ishape;
    obj->shape = shape;
    while (engine.game.list != NULL) {
        if (engine.game.list->settings.id == obj->id) {
            engine.game.list->settings.ishape = ishape;
            engine.game.list->settings.shape = shape;
        }
        engine.game.list = engine.game.list->previous;
    }
    engine.game.list = start;
}
