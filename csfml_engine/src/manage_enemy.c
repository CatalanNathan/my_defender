/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** manage_enemy.c
*/

#include "engine.h"
#include "my.h"
#include "var.h"

void create_enemies(var_t *var, int possibility)
{
    int x_start = 0;
    int y_start = 0;
    int n = 0;
    V2f *path;

    if (possibility % 2 == 0) {
        x_start = 1090;
        y_start = 730;
        path = random_this((V2f[4]){{1015, 640}, {1290, 450}, {1000, 290}, {x_start, y_start}}, 4);
        n = 4;
    } else {
        x_start = 400;
        y_start = 540;
        path = random_this((V2f[6]){{555, 470}, {750, 550}, {910, 450}, {790, 370}, {910, 280}, {x_start, y_start}}, 6);
        n = 6;
    }
    var->enemies = create_object("player.png", "enemies", 8);
    set_shape_obj(&var->enemies, (sfIntRect){0, 48, 48, 48}, true);
    set_position_obj(var->enemies, (V2f){x_start, y_start});
    set_enemy_obj(&var->enemies, path, n);
}

void set_movement(obj_t *object)
{
    if (get_collision_obj(object, "wall_1", 50) || get_collision_obj(object, "wall_2", 50) || get_collision_obj(object, "wall_3", 50))
        return;
    if (get_position_obj(*object).x > object->enemy.path[object->enemy.pos_path].x) {
        set_position_obj(*object, (V2f){get_position_obj(*object).x - 1, get_position_obj(*object).y});
        if (get_scale_obj(*object).x > 0) {
            set_position_obj(*object, (V2f){get_position_obj(*object).x + get_size_obj(object).x, get_position_obj(*object).y});
            set_scale_obj(object, (V2f){get_scale_obj(*object).x * -1, get_scale_obj(*object).y});
        }
    }
    if (get_position_obj(*object).x < object->enemy.path[object->enemy.pos_path].x) {
        set_position_obj(*object, (V2f){get_position_obj(*object).x + 1, get_position_obj(*object).y});
        if (get_scale_obj(*object).x < 0) {
            set_position_obj(*object, (V2f){get_position_obj(*object).x - get_size_obj(object).x, get_position_obj(*object).y});
            set_scale_obj(object, (V2f){get_scale_obj(*object).x * -1, get_scale_obj(*object).y});
        }
    }
    if (get_position_obj(*object).y > object->enemy.path[object->enemy.pos_path].y)
        set_position_obj(*object, (V2f){get_position_obj(*object).x, get_position_obj(*object).y - 0.5});
    if (get_position_obj(*object).y < object->enemy.path[object->enemy.pos_path].y)
        set_position_obj(*object, (V2f){get_position_obj(*object).x, get_position_obj(*object).y + 0.5});
}

void animation_move_enemies(obj_t *object, var_t *var)
{
    animation_obj(object, (int[4]){0, 48, 240, 100}, &object->enemy.anim_ennemie);
    if (elapsed_time_milliseconds(15, &object->enemy.move_enemies) != true)
        return;
    set_movement(object);
    if (compare_sfvector2f(get_position_obj(*object), object->enemy.path[object->enemy.pos_path]) == true && object->enemy.pos_path < object->enemy.n_path - 1)
        object->enemy.pos_path += 1;
    if (object->enemy.pos_path >= object->enemy.n_path - 1) {
        var->castle_life -= 15.00;
        set_position_obj(*object, object->enemy.path[object->enemy.pos_path]);
        object->enemy.pos_path = 0;
    }
}

void manage_enemy(var_t *var)
{
    node_t *start = engine.game.list;

    for (;engine.game.list != NULL; engine.game.list = engine.game.list->previous)
        if (engine.game.list->settings.enemy.it_is)
            animation_move_enemies(&engine.game.list->settings, var);
    engine.game.list = start;
}

void make_enemies(var_t *var)
{
    static int i = 0;

    for (; i <= var->nb_enemies; i++)
        create_enemies(var, i);
}
