/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** tower_attack
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void create_new_spears(char **st, obj_t copy, obj_t linked, var_t *var)
{
    if (st[0][7] == '1') {
        create_object("rock.png", st[0], 7);
        set_music_play_tag("rock", false, var->volume);
    } else if (st[0][7] == '2') {
        create_object("WoodenSpears.png", st[0], 7);
        set_music_play_tag("arrow", false, var->volume);
    } else {
        create_object("fire.png", st[0], 7);
        set_music_play_tag("fire", false, var->volume);
    }
    set_scale_tag(st[0], (V2f){0.1, 0.1});
    if (st[0][7] == '3')
        set_scale_tag(st[0], (V2f){0.05, 0.05});
    set_position_tag(st[0], (V2f){GPT(st[1]).x +
    get_size_tag(st[1]).x/2, GPT(st[1]).y});
    if (GPO(copy).x > GPT(st[0]).x)
        set_rotation_tag(st[0], 60);
    linked = copy_object_tag(st[0]);
    set_link_id(&copy, &linked);
}

void attack(var_t *var, int id, char *tower, float time)
{
    static char *spears;
    static int i = 0;
    obj_t copy;
    obj_t linked;

    if (i == 0)
        spears = my_strdup("spears_1.1");
    i = 1;
    spears[7] = tower[6];
    spears[9] = tower[8];
    copy = copy_object(id);
    if (get_exits_tag(spears))
        projectiles_move(spears, copy, time, var);
    else if (id > 0 && spears[7] < '4' && spears[9] < '6'
    && get_shape_tag(tower).left > 1500 &&
    !get_exits_tag(spears))
        create_new_spears((char *[2]){spears, tower}, copy, linked, var);
}

void set_range_attack(char *tower, float time, var_t *var)
{
    obj_t instance;

    instance = copy_object_tag(tower);
    if (tower[6] == '1')
        attack(var, get_collision_zone_obj_id(&instance,
        "enemies", 300), tower, time);
    if (tower[6] == '2')
        attack(var, get_collision_zone_obj_id(&instance,
        "enemies", 600), tower, time);
    if (tower[6] == '3')
        attack(var, get_collision_zone_obj_id(&instance,
        "enemies", 200), tower, time);
}

void tower_attack(var_t *var)
{
    obj_t zone;
    char *tower = my_strdup("Tower_1.1");
    char e = '1';
    char a = '1';
    static float time = 0.00;
    static float save = 0.00;

    get_elapsed_time(&time, &save);
    if (var->pause)
        return;
    while (a != '4') {
        while (e != '6') {
            set_range_attack(tower, time, var);
            e++;
            tower[8] = e;
        }
        e = '1';
        tower[8] = '1';
        a++;
        tower[6] = a;
    }
}
