/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** tower_event.c
*/

#include "engine.h"
#include "my.h"
#include "var.h"

void check_time(obj_t object)
{
    set_exits_tag(object.link_tag, true);
}

void time_tower(var_t *var)
{
    time_tower_run_one(var);
    time_tower_run_two(var);
    time_tower_run_three(var);
    time_tower_run_four(var);
    time_tower_run_five(var);
}

void check_upgrade_tower(char *tag, var_t *var)
{
    if (equal(tag, "Tower_1.1")) {
        if (var->tower.tower_active == 1)
            set_shape_tag(tag, (sfIntRect){580, 0, 120, get_size_obj(&var->tower.tower).y}, true);
        // } else if (var->tower.tower_active == 2) {

        // } else {

        // }
    }
    // if (equal(tag, "Tower_1.2")) {
    //     if (var->tower.tower_active == 1) {

    //     } else if (var->tower.tower_active == 2) {

    //     } else {

    //     }
    // }
    // if (equal(tag, "Tower_1.3")) {
    //     if (var->tower.tower_active == 1) {

    //     } else if (var->tower.tower_active == 2) {

    //     } else {

    //     }
    // }
    // if (equal(tag, "Tower_1.4")) {
    //     if (var->tower.tower_active == 1) {

    //     } else if (var->tower.tower_active == 2) {

    //     } else {

    //     }
    // }
    // if (equal(tag, "Tower_1.5")) {
    //     if (var->tower.tower_active == 1) {

    //     } else if (var->tower.tower_active == 2) {

    //     } else {

    //     }
    // }
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
        if (mouse_inside_tag(tower) && var->thor_mod == true) {
            sfSprite_setColor(object.sprite, sfYellow);
            if (mouse_pressed(sfMouseLeft, &i)) {
                check_time(object);
                check_upgrade_tower(tower, var);
                break;
            }
        } else
            sfSprite_setColor(object.sprite, var->color_tower);
        e++;
        tower[8] = e;
    }
}
