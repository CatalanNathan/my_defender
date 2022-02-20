/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** set_animation.c
*/

#include "my.h"
#include "engine.h"

#define shape engine->game.list->settings.shape

void set_animation(char *tag, int *ref, engine_t *engine)
{
    if (shape.left >= ref[2])
        set_shape_tag(tag, (sfIntRect){ref[0], shape.top, shape.width, shape.height}, true, engine);
    else
        set_shape_tag(tag, (sfIntRect){shape.left += ref[1], shape.top, shape.width, shape.height}, true, engine);
}

void set_animation_obj(obj_t *obj, int *ref, engine_t *engine)
{
    if (shape.left >= ref[2])
        set_shape_obj(obj, (sfIntRect){ref[0], shape.top, shape.width, shape.height}, true, engine);
    else
        set_shape_obj(obj, (sfIntRect){shape.left += ref[1], shape.top, shape.width, shape.height}, true, engine);
}

void animation_tag(char *tag, int *shape_start_increment_end_milliseconds, float *increment, engine_t *engine)
{
    node_t *start = engine->game.list;

    if (elapsed_time_milliseconds(shape_start_increment_end_milliseconds[3], increment, engine) == false)
        return;

    while (engine->game.list != NULL) {
        if (equal(engine->game.list->settings.tag, tag) == true) {
            set_animation(tag, shape_start_increment_end_milliseconds, engine);
        }
        engine->game.list = engine->game.list->previous;
    }
    engine->game.list = start;
}

void animation_obj(obj_t *obj, int *shape_start_increment_end_milliseconds, float *increment, engine_t *engine)
{
    node_t *start = engine->game.list;

    if (elapsed_time_milliseconds(shape_start_increment_end_milliseconds[3], increment, engine) == false)
        return;

    while (engine->game.list != NULL) {
        if (engine->game.list->settings.id == obj->id) {
            set_animation_obj(obj, shape_start_increment_end_milliseconds, engine);
        }
        engine->game.list = engine->game.list->previous;
    }
    engine->game.list = start;
}
