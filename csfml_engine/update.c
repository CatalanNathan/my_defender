/*
** EPITECH PROJECT, 2021
** CSFML engine
** File description:
** update.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void system_function(var_t *var)
{
    if (key_pressed(sfKeyEscape))
        game_end(0);
}

void animation_move_enemies(obj_t *object)
{
    animation_obj(object, (int[4]){0, 48, 240, 100}, &object->anim_ennemie);
    if (elapsed_time_milliseconds(15, &object->move_enemies) != true)
        return;
    if (get_position_obj(*object).x > object->path[object->pos_path].x) {
        set_position_obj(*object, (sfVector2f){get_position_obj(*object).x - 1,get_position_obj(*object).y});
        if (get_scale_obj(*object).x > 0) {
            set_position_obj(*object, (sfVector2f){get_position_obj(*object).x + get_size_obj(object).x, get_position_obj(*object).y});
            set_scale_obj(object, (sfVector2f){get_scale_obj(*object).x * -1, get_scale_obj(*object).y});
        }
    }
    if (get_position_obj(*object).x < object->path[object->pos_path].x) {
        set_position_obj(*object, (sfVector2f){get_position_obj(*object).x + 1,get_position_obj(*object).y});
        if (get_scale_obj(*object).x < 0) {
            set_position_obj(*object, (sfVector2f){get_position_obj(*object).x - get_size_obj(object).x, get_position_obj(*object).y});
            set_scale_obj(object, (sfVector2f){get_scale_obj(*object).x * -1, get_scale_obj(*object).y});
        }
    }
    if (get_position_obj(*object).y > object->path[object->pos_path].y)
        set_position_obj(*object, (sfVector2f){get_position_obj(*object).x,get_position_obj(*object).y - 0.5});
    if (get_position_obj(*object).y < object->path[object->pos_path].y)
        set_position_obj(*object, (sfVector2f){get_position_obj(*object).x,get_position_obj(*object).y + 0.5});
    if (compare_sfvector2f(get_position_obj(*object), object->path[object->pos_path]) && object->pos_path < 6)
        object->pos_path += 1;
    else if (object->pos_path > 5) {
        set_position_obj(*object, (sfVector2f){1060, 750});
        object->pos_path = 0;
    }
}

void update(var_t *var)
{
    node_t *start = engine.game.list;

    system_function(var);
    for (;engine.game.list != NULL; engine.game.list = engine.game.list->previous)
        if (engine.game.list->settings.enemy)
            animation_move_enemies(&engine.game.list->settings);
    engine.game.list = start;
}
