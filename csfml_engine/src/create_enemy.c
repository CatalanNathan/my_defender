/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** create_enemy
*/

#include "engine.h"
#include "my.h"
#include "var.h"

void respect_norms2(obj_t *object, float time)
{
    if (get_position_obj(*object).x <
        object->enemy.path[object->enemy.pos_path].x) {
        set_position_obj(*object, (V2f){get_position_obj(*object).x +
        (0.00005 * time), get_position_obj(*object).y});
        if (get_scale_obj(*object).x < 0) {
            set_position_obj(*object, (V2f){get_position_obj(*object).x -
            get_size_obj(object).x, get_position_obj(*object).y});
            set_scale_obj(object, (V2f){get_scale_obj(*object).x * -1,
            get_scale_obj(*object).y});
        }
    }
}

void respect_norms(obj_t *object, float time)
{
    if (get_position_obj(*object).x >
        object->enemy.path[object->enemy.pos_path].x) {
        set_position_obj(*object, (V2f){get_position_obj(*object).x -
        (0.00005 * time), get_position_obj(*object).y});
        if (get_scale_obj(*object).x > 0) {
            set_position_obj(*object, (V2f){get_position_obj(*object).x
            + get_size_obj(object).x, get_position_obj(*object).y});
            set_scale_obj(object, (V2f){get_scale_obj(*object).x * -1,
            get_scale_obj(*object).y});
        }
    }
    respect_norms2(object, time);
}

int make_position(int *x_start, int *y_start, V2f **path)
{
    static int i = 0;

    if (i == 0) {
        (*x_start) = 1090;
        (*y_start) = 730;
        (*path) = random_this((V2f[4]){{1000, 635}, {1295, 450}, {1000, 290},
        {(*x_start), (*y_start)}}, 4);
        i = 1;
        return 4;
    } else if (i == 1) {
        (*x_start) = 400;
        (*y_start) = 540;
        (*path) = random_this((V2f[6]){{555, 470}, {750, 550}, {910, 450},
        {790, 370}, {910, 280}, {(*x_start), (*y_start)}}, 6);
        i = 0;
        return 6;
    }
    return 0;
}

void create_enemies(var_t *var)
{
    int x_start = 0;
    int y_start = 0;
    V2f *path;
    int n = make_position(&x_start, &y_start, &path);
    obj_t life_bar;
    obj_t enemies;
    static float time = 0.00;
    static float save = 0.00;

    if (!elapsed_time_seconds(1, &time, &save) || var->pause)
        return;
    enemies = create_object("player.png", "enemies", 8);
    life_bar = create_object("life_bar.png", "lifebar", 7);
    set_shape_obj(&enemies, (sfIntRect){0, 48, 48, 48}, true);
    set_position_obj(enemies, (V2f){x_start, y_start});
    set_enemy_obj(&enemies, path, n);
    set_pv_obj(&enemies, (20 * (var->nb_enemies_max - var->nb_enemies))
    + var->enemies_kill, (20 * (var->nb_enemies_max - var->nb_enemies))
    + var->enemies_kill);
    set_link_id(&life_bar, &enemies);
    var->nb_enemies++;
}
