/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-guillaume.kucia
** File description:
** projectiles_move.c
*/

#include "engine.h"
#include "var.h"
#include "my.h"

void spears_touch(char *spears, obj_t copy, var_t *var)
{
    obj_t spears_o;

    spears_o = copy_object_tag(spears);
    destroy_object(spears_o.id);
    if (spears[7] == '1')
        set_pv_obj(&copy, get_pv_obj(&copy) - 50, get_pv_max_obj(&copy));
    if (spears[7] == '2')
        set_pv_obj(&copy, get_pv_obj(&copy) - 25, get_pv_max_obj(&copy));
    if (spears[7] == '3') {
        set_pv_obj(&copy, get_pv_obj(&copy) - 10, get_pv_max_obj(&copy));
        set_touch_object(&copy);
    }
    if (get_pv_obj(&copy) <= 0) {
        destroy_object(copy.link_id);
        destroy_object(copy.id);
        var->nb_enemies -= 1;
        var->money += 500 + (5 * var->enemies_kill);
        var->enemies_kill++;
    }
}

void projectiles_move2(var_t *var, char *spears, obj_t copy, float time)
{
    static float v = 0.00023;
    static int a = 0;

    if (get_scale_obj(copy).x > 0)
        a = get_size_obj(&copy).x;
    else
        a = 0;
    if (GPT(spears).y < GPO(copy).y)
        SPT(spears, (V2f){GPT(spears).x, GPT(spears).y + (v * time)});
    if (GPT(spears).y > GPO(copy).y)
        SPT(spears, (V2f){GPT(spears).x, GPT(spears).y - (v * time)});
    if (compare_sfvector2f(GPT(spears), (V2f){GPO(copy).x + a, GPO(copy).y}))
        spears_touch(spears, copy, var);
}

void checker(obj_t copy, int a, float time, char *spears)
{
    if (GPT(spears).x < GPO(copy).x + a) {
        SPT(spears, (V2f){GPT(spears).x + (0.00023 * time), GPT(spears).y});
        if (GRT(spears) < 180)
            set_rotation_tag(spears, 2);
    }
    if (GPT(spears).x > GPO(copy).x + a) {
        SPT(spears, (V2f){GPT(spears).x - (0.00023 * time), GPT(spears).y});
        if (GRT(spears) > 180 || GRT(spears) == 0)
            set_rotation_tag(spears, -5);
    }
}

void projectiles_move(char *spears, obj_t copy, float time, var_t *var)
{
    static float v = 0.00023;
    obj_t linked = copy_object_tag(spears);
    static int a = 0;

    copy = copy_object(linked.link_id);
    if (copy.id < 0) {
        destroy_object(linked.id);
        return;
    }
    if (get_scale_obj(copy).x > 0)
        a = get_size_obj(&copy).x;
    else
        a = 0;
    checker(copy, a, time, spears);
    projectiles_move2(var, spears, copy, time);
}
