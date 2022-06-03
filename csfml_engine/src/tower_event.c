/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** tower_event.c
*/

#include "engine.h"
#include "my.h"
#include "var.h"

void check_time(obj_t object, var_t *var)
{
    bool paiement = false;

    if (var->tower.tower_selected == 1 && var->money - 20000 >= 0) {
        var->money -= 20000;
        paiement = true;
    }
    if (var->tower.tower_selected == 2 && var->money - 50000 >= 0) {
        var->money -= 50000;
        paiement = true;
    }
    if (var->tower.tower_selected == 3 && var->money - 90000 >= 0) {
        var->money -= 90000;
        paiement = true;
    }
    if (paiement == true)
        set_exits_tag(object.link_tag, true);
}

void time_tower(var_t *var)
{
    char **tags = malloc(sizeof(char *) * 2);
    static int a = 0;
    static int b = 0;
    static int c = 0;
    static int d = 0;
    static int e = 0;

    time_tower_run_one(var, tags, &a);
    time_tower_run_two(var, tags, &b);
    time_tower_run_three(var, tags, &c);
    time_tower_run_four(var, tags, &d);
    time_tower_run_five(var, tags, &e);
    free(tags);
}

void tower_event2(char *tower, var_t *var, obj_t object, int i)
{
    if (mouse_inside_tag(tower) && var->thor_mod == true) {
        sfSprite_setColor(object.sprite, sfYellow);
        if (mouse_pressed(sfMouseLeft, &i)) {
            check_time(object, var);
            var->thor_mod = false;
        }
    } else
        sfSprite_setColor(object.sprite, var->color_tower);
}

void tower_event(var_t *var)
{
    obj_t object;
    char *tower = my_strdup("Tower_1.1");
    char e = '1';
    static int i = 0;

    time_tower(var);
    while (e != '6') {
        object = copy_object_tag(tower);
        tower_event2(tower, var, object, i);
        e++;
        tower[8] = e;
    }
    mouse_pressed(sfMouseLeft, &i);
    update_spears(var);
}
