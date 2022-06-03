/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-guillaume.kucia
** File description:
** display_lifebar.c
*/

#include "engine.h"
#include "var.h"
#include "my.h"

void check_destroy(node_t *start, obj_t instance)
{
    if (instance.id >= 0)
        destroy_object(instance.id);
    engine.game.list = start;
}

int find_tag(obj_t instance, obj_t target, node_t *start)
{
    if (equal(engine.game.list->settings.tag, "lifebar")) {
        instance = copy_object(engine.game.list->settings.id);
        target = copy_object(instance.link_id);
        if (target.id < 0 || instance.id < 0) {
            check_destroy(start, instance);
            return 1;
        }
        set_position_obj(instance, (V2f){get_position_obj(target).x,
        get_position_obj(target).y});
        set_scale_obj(&instance, (V2f){(((float)target.enemy.pv * 100) /
        (float)target.enemy.max_pv) / 100, 1});
        if ((get_scale_obj(target).x > 0 && get_scale_obj(instance).x < 0) ||
        (get_scale_obj(target).x < 0 && get_scale_obj(instance).x > 0))
        set_scale_obj(&instance, (V2f){get_scale_obj(instance).x * (-1), 1});
    }
    return 0;
}

void display_lifebar(var_t *var)
{
    node_t *start = engine.game.list;
    obj_t instance;
    obj_t target;

    for (;engine.game.list != NULL; engine.game.list =
    engine.game.list->previous)
        if (find_tag(instance, target, start) == 1)
            return;
    engine.game.list = start;
}
