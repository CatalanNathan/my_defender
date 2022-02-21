/*
** EPITECH PROJECT, 2021
** CSFML engine
** File description:
** update.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void system_function(var_t *var, engine_t *engine)
{
    if (key_pressed(sfKeyEscape, engine))
        game_end(0, engine);
}

void animation_move_enemies(obj_t *object, engine_t *engine)
{
    animation_obj(object, (int[4]){0, 48, 240, 100}, &object->anim_ennemie, engine);
    if (elapsed_time_milliseconds(15, &object->move_enemies , engine) != true)
        return;
    if (get_position_obj(*object, engine).x > object->path[object->pos_path].x) {
        set_position_obj(*object, (sfVector2f){get_position_obj(*object, engine).x - 1,get_position_obj(*object, engine).y}, engine);
        if (get_scale_obj(*object, engine).x > 0) {
            set_position_obj(*object, (sfVector2f){get_position_obj(*object, engine).x + get_size_obj(object, engine).x, get_position_obj(*object, engine).y}, engine);
            set_scale_obj(object, (sfVector2f){get_scale_obj(*object, engine).x * -1, get_scale_obj(*object, engine).y}, engine);
        }
    }
    if (get_position_obj(*object, engine).x < object->path[object->pos_path].x) {
        set_position_obj(*object, (sfVector2f){get_position_obj(*object, engine).x + 1,get_position_obj(*object, engine).y}, engine);
        if (get_scale_obj(*object, engine).x < 0) {
            set_position_obj(*object, (sfVector2f){get_position_obj(*object, engine).x - get_size_obj(object, engine).x, get_position_obj(*object, engine).y}, engine);
            set_scale_obj(object, (sfVector2f){get_scale_obj(*object, engine).x * -1, get_scale_obj(*object, engine).y}, engine);
        }
    }
    if (get_position_obj(*object, engine).y > object->path[object->pos_path].y)
        set_position_obj(*object, (sfVector2f){get_position_obj(*object, engine).x,get_position_obj(*object, engine).y - 0.5}, engine);
    if (get_position_obj(*object, engine).y < object->path[object->pos_path].y)
        set_position_obj(*object, (sfVector2f){get_position_obj(*object, engine).x,get_position_obj(*object, engine).y + 0.5}, engine);
    if (compare_sfvector2f(get_position_obj(*object, engine), object->path[object->pos_path]) && object->pos_path < 6)
        object->pos_path += 1;
    else if (object->pos_path > 5) {
        set_position_obj(*object, (sfVector2f){1060, 750}, engine);
        object->pos_path = 0;
    }
}

void update(var_t *var, engine_t *engine)
{
    node_t *start = engine->game.list;

    system_function(var, engine);
    for (;engine->game.list != NULL; engine->game.list = engine->game.list->previous)
        if (engine->game.list->settings.enemy)
            animation_move_enemies(&engine->game.list->settings, engine);
    engine->game.list = start;
}
