/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** manage_enemy.c
*/

#include "engine.h"
#include "my.h"
#include "var.h"

void set_movement(obj_t *object)
{
    if (get_position_obj(*object).x > object->enemy.path[object->enemy.pos_path].x) {
        set_position_obj(*object, (V2f){get_position_obj(*object).x - 1,get_position_obj(*object).y});
        if (get_scale_obj(*object).x > 0) {
            set_position_obj(*object, (V2f){get_position_obj(*object).x + get_size_obj(object).x, get_position_obj(*object).y});
            set_scale_obj(object, (V2f){get_scale_obj(*object).x * -1, get_scale_obj(*object).y});
        }
    }
    if (get_position_obj(*object).x < object->enemy.path[object->enemy.pos_path].x) {
        set_position_obj(*object, (V2f){get_position_obj(*object).x + 1,get_position_obj(*object).y});
        if (get_scale_obj(*object).x < 0) {
            set_position_obj(*object, (V2f){get_position_obj(*object).x - get_size_obj(object).x, get_position_obj(*object).y});
            set_scale_obj(object, (V2f){get_scale_obj(*object).x * -1, get_scale_obj(*object).y});
        }
    }
    if (get_position_obj(*object).y > object->enemy.path[object->enemy.pos_path].y)
        set_position_obj(*object, (V2f){get_position_obj(*object).x,get_position_obj(*object).y - 0.5});
    if (get_position_obj(*object).y < object->enemy.path[object->enemy.pos_path].y)
        set_position_obj(*object, (V2f){get_position_obj(*object).x,get_position_obj(*object).y + 0.5});
}

void animation_move_enemies(obj_t *object)
{
    animation_obj(object, (int[4]){0, 48, 240, 100}, &object->enemy.anim_ennemie);
    if (elapsed_time_milliseconds(15, &object->enemy.move_enemies) != true)
        return;
    set_movement(object);
    if (compare_sfvector2f(get_position_obj(*object), object->enemy.path[object->enemy.pos_path]) && object->enemy.pos_path < 6)
        object->enemy.pos_path += 1;
    else if (object->enemy.path[object->enemy.pos_path].x == 0) {
        set_position_obj(*object, (V2f){1060, 750});
        object->enemy.pos_path = 0;
    }
}

void manage_enemy(var_t *var)
{
    node_t *start = engine.game.list;

    for (;engine.game.list != NULL; engine.game.list = engine.game.list->previous)
        if (engine.game.list->settings.enemy.it_is)
            animation_move_enemies(&engine.game.list->settings);
    engine.game.list = start;
}

void make_enemies(var_t *var)
{
    static int i = 0;

    for (; i <= var->nb_enemies; i++)
        create_enemies(var, i);
}
