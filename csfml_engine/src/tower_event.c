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
    static float i_text1 = 0.00;
    static float save_text1 = 0.00;

    if (get_exits_tag("clock_build1") && get_text_visible_tag("build_text1") == false) {
        set_text_position_tag("build_text1", (V2f){get_position_tag("clock_build1").x + get_size_tag("clock_build1").x/2 - 5, get_position_tag("clock_build1").y + 5});
        set_text_visible_tag("build_text1", true);
    } else if (get_text_visible_tag("build_text1")) {
        set_text_tag("build_text1", my_itoa(var->tower.build_time_t1, 0));
        if (elapsed_time_seconds(1, &i_text1, &save_text1))
            var->tower.build_time_t1 -= 1;
        if (var->tower.build_time_t1 <= 0) {
            set_exits_tag("clock_build1", false);
            set_text_visible_tag("build_text1", false);
            var->tower.build_time_t1 = 10;
        }
    }
    // if (get_exits_tag("clock_build2"))
    // if (get_exits_tag("clock_build3"))
    // if (get_exits_tag("clock_build4"))
    // if (get_exits_tag("clock_build5"))
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
            }
        }
        else
            sfSprite_setColor(object.sprite, var->color_tower);
        e++;
        tower[8] = e;
    }
}
