/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** manage_enemy.c
*/

#include "engine.h"
#include "my.h"
#include "var.h"

void respect_norms(obj_t *object, float time);

void set_movement(obj_t *object, float time, var_t *var)
{
    if (var->pause)
        return;
    if (get_collision_obj(object, "wall_1", 50) ||
    get_collision_obj(object, "wall_2", 50) ||
    get_collision_obj(object, "wall_3", 50))
        return;
    respect_norms(object, time);
    if (get_position_obj(*object).y >
        object->enemy.path[object->enemy.pos_path].y)
        set_position_obj(*object, (V2f){get_position_obj(*object).x,
        get_position_obj(*object).y - (0.000027 * time)});
    if (get_position_obj(*object).y <
        object->enemy.path[object->enemy.pos_path].y)
        set_position_obj(*object, (V2f){get_position_obj(*object).x,
        get_position_obj(*object).y + (0.000027 * time)});
}

void norms2(var_t *var, obj_t *object)
{
    if (object->enemy.pos_path >= object->enemy.n_path - 1) {
        var->castle_life -= 15.00;
        destroy_object(object->link_id);
        destroy_object(object->id);
        var->nb_enemies -= 1;
        var->money += 500;
    }
}

void animation_move_enemies(obj_t *object, var_t *var, float time)
{
    obj_t linked;

    if (object->enemy.is_touch == true && !var->pause)
        set_pv_obj(object, get_pv_obj(object) -
        0.000010 * time, get_pv_max_obj(object));
    if (get_pv_obj(object) <= 0 && !var->pause) {
        destroy_object(object->link_id);
        destroy_object(object->id);
        var->nb_enemies -= 1;
        var->money += 500;
        var->enemies_kill++;
        return;
    }
    set_movement(object, time, var);
    if (compare_sfvector2f(get_position_obj(*object),
        object->enemy.path[object->enemy.pos_path]) == true &&
        object->enemy.pos_path < object->enemy.n_path - 1)
        object->enemy.pos_path += 1;
    norms2(var, object);
}

void manage_enemy(var_t *var)
{
    node_t *start = engine.game.list;
    static float time = 0.00;
    static float save = 0.00;
    static float time2 = 0.00;
    static float save2 = 0.00;

    animation_tag("enemies", (int[4]){0, 48, 240, 100}, &time, &save);
    get_elapsed_time(&time2, &save2);
    while (engine.game.list != NULL) {
        if (engine.game.list->settings.enemy.it_is)
            animation_move_enemies(&engine.game.list->settings, var, time2);
        engine.game.list = engine.game.list->previous;
    }
    engine.game.list = start;
}

void make_enemies(var_t *var)
{
    if (var->nb_enemies < var->nb_enemies_max)
        create_enemies(var);
}
