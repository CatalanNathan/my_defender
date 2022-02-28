/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** time_tower_run.c
*/

#include "engine.h"
#include "var.h"
#include "my.h"

void time_tower_run_one(var_t *var)
{
    static float increment = 0.00;
    static float save = 0.00;
    static float time = 10;
    static int my_pass = 0;
    static int i = 0;

    if (i == 0 && get_exits_tag("clock_build1"))
        i = var->tower.tower_selected;
    if (var->tower.valide_position_1 == false)
        return;

    if (get_exits_tag("clock_build1") && get_text_visible_tag("build_text1") == false) {
        set_text_position_tag("build_text1", (V2f){get_position_tag("clock_build1").x + get_size_tag("clock_build1").x/2 - 5, get_position_tag("clock_build1").y + 5});
        set_text_visible_tag("build_text1", true);
    } else if (get_text_visible_tag("build_text1")) {
        set_text_tag("build_text1", my_itoa(time, 0));
        if (elapsed_time_seconds(1, &increment, &save)) {
            time -= 1;
            my_pass++;
        }
        if (time <= 0) {
            set_exits_tag("clock_build1", false);
            set_text_visible_tag("build_text1", false);
            time = 10;
            var->tower.valide_position_1 = false;
        }
    }
    if (my_pass >= 2 && time < 8) {
        if (i == 1)
            set_shape_tag("Tower_1.1", (sfIntRect){get_shape_tag("Tower_1.1").left + 428, 0, 118, get_size_tag("Tower_1.1").y}, true);
        else
            set_visible_tag("Tower_1.1", false);
        if (i == 2)
            set_shape_tag("Tower_2.1", (sfIntRect){get_shape_tag("Tower_2.1").left + 428, 0, 118, get_size_tag("Tower_2.1").y}, true);
        else
            set_visible_tag("Tower_2.1", false);
        if (i == 3)
            set_shape_tag("Tower_3.1", (sfIntRect){get_shape_tag("Tower_3.1").left + 428, 0, 118, get_size_tag("Tower_3.1").y}, true);
        else
            set_visible_tag("Tower_3.1", false);
        my_pass = 0;
    }
}

void time_tower_run_two(var_t *var)
{
    static float increment = 0.00;
    static float save = 0.00;
    static float time = 10;
    static int my_pass = 0;
    static int i = 0;

    if (i == 0 && get_exits_tag("clock_build2"))
        i = var->tower.tower_selected;
    if (var->tower.valide_position_2 == false)
        return;

    if (get_exits_tag("clock_build2") && get_text_visible_tag("build_text2") == false) {
        set_text_position_tag("build_text2", (V2f){get_position_tag("clock_build2").x + get_size_tag("clock_build2").x/2 - 5, get_position_tag("clock_build2").y + 5});
        set_text_visible_tag("build_text2", true);
    } else if (get_text_visible_tag("build_text2")) {
        set_text_tag("build_text2", my_itoa(time, 0));
        if (elapsed_time_seconds(1, &increment, &save)) {
            time -= 1;
            my_pass++;
        }
        if (time <= 0) {
            set_exits_tag("clock_build2", false);
            set_text_visible_tag("build_text2", false);
            time = 10;
            var->tower.valide_position_2 = false;
        }
    }
    if (my_pass >= 2 && time < 8) {
        if (i == 1)
            set_shape_tag("Tower_1.2", (sfIntRect){get_shape_tag("Tower_1.2").left + 428, 0, 118, get_size_tag("Tower_1.2").y}, true);
        else
            set_visible_tag("Tower_1.2", false);
        if (i == 2)
            set_shape_tag("Tower_2.2", (sfIntRect){get_shape_tag("Tower_2.2").left + 428, 0, 118, get_size_tag("Tower_2.2").y}, true);
        else
            set_visible_tag("Tower_2.2", false);
        if (i == 3)
            set_shape_tag("Tower_3.2", (sfIntRect){get_shape_tag("Tower_3.2").left + 428, 0, 118, get_size_tag("Tower_3.2").y}, true);
        else
            set_visible_tag("Tower_3.2", false);
        my_pass = 0;
    }
}

void time_tower_run_three(var_t *var)
{
    static float increment = 0.00;
    static float save = 0.00;
    static float time = 10;
    static int my_pass = 0;
    static int i = 0;

    if (i == 0 && get_exits_tag("clock_build3"))
        i = var->tower.tower_selected;
    if (var->tower.valide_position_3 == false)
        return;

    if (get_exits_tag("clock_build3") && get_text_visible_tag("build_text3") == false) {
        set_text_position_tag("build_text3", (V2f){get_position_tag("clock_build3").x + get_size_tag("clock_build3").x/2 - 5, get_position_tag("clock_build3").y + 5});
        set_text_visible_tag("build_text3", true);
    } else if (get_text_visible_tag("build_text3")) {
        set_text_tag("build_text3", my_itoa(time, 0));
        if (elapsed_time_seconds(1, &increment, &save)) {
            time -= 1;
            my_pass++;
        }
        if (time <= 0) {
            set_exits_tag("clock_build3", false);
            set_text_visible_tag("build_text3", false);
            time = 10;
            var->tower.valide_position_3 = false;
        }
    }
    if (my_pass >= 2 && time < 8) {
        if (i == 1)
            set_shape_tag("Tower_1.3", (sfIntRect){get_shape_tag("Tower_1.3").left + 428, 0, 118, get_size_tag("Tower_1.3").y}, true);
        else
            set_visible_tag("Tower_1.3", false);
        if (i == 2)
            set_shape_tag("Tower_2.3", (sfIntRect){get_shape_tag("Tower_2.3").left + 428, 0, 118, get_size_tag("Tower_2.3").y}, true);
        else
            set_visible_tag("Tower_2.3", false);
        if (i == 3)
            set_shape_tag("Tower_3.3", (sfIntRect){get_shape_tag("Tower_3.3").left + 428, 0, 118, get_size_tag("Tower_3.3").y}, true);
        else
            set_visible_tag("Tower_3.3", false);
        my_pass = 0;
    }
}

void time_tower_run_four(var_t *var)
{
    static float increment = 0.00;
    static float save = 0.00;
    static float time = 10;
    static int my_pass = 0;
    static int i = 0;

    if (i == 0 && get_exits_tag("clock_build4"))
        i = var->tower.tower_selected;
    if (var->tower.valide_position_4 == false)
        return;

    if (get_exits_tag("clock_build4") && get_text_visible_tag("build_text4") == false) {
        set_text_position_tag("build_text4", (V2f){get_position_tag("clock_build4").x + get_size_tag("clock_build4").x/2 - 5, get_position_tag("clock_build4").y + 5});
        set_text_visible_tag("build_text4", true);
    } else if (get_text_visible_tag("build_text4")) {
        set_text_tag("build_text4", my_itoa(time, 0));
        if (elapsed_time_seconds(1, &increment, &save)) {
            time -= 1;
            my_pass++;
        }
        if (time <= 0) {
            set_exits_tag("clock_build4", false);
            set_text_visible_tag("build_text4", false);
            time = 10;
            var->tower.valide_position_4 = false;
        }
    }
    if (my_pass >= 2 && time < 8) {
        if (i == 1)
            set_shape_tag("Tower_1.4", (sfIntRect){get_shape_tag("Tower_1.4").left + 428, 0, 118, get_size_tag("Tower_1.4").y}, true);
        else
            set_visible_tag("Tower_1.4", false);
        if (i == 2)
            set_shape_tag("Tower_2.4", (sfIntRect){get_shape_tag("Tower_2.4").left + 428, 0, 118, get_size_tag("Tower_2.4").y}, true);
        else
            set_visible_tag("Tower_2.4", false);
        if (i == 3)
            set_shape_tag("Tower_3.4", (sfIntRect){get_shape_tag("Tower_3.4").left + 428, 0, 118, get_size_tag("Tower_3.4").y}, true);
        else
            set_visible_tag("Tower_3.4", false);
        my_pass = 0;
    }
}

void time_tower_run_five(var_t *var)
{
    static float increment = 0.00;
    static float save = 0.00;
    static float time = 10;
    static int my_pass = 0;
    static int i = 0;

    if (i == 0 && get_exits_tag("clock_build5"))
        i = var->tower.tower_selected;
    if (var->tower.valide_position_5 == false)
        return;

    if (get_exits_tag("clock_build5") && get_text_visible_tag("build_text5") == false) {
        set_text_position_tag("build_text5", (V2f){get_position_tag("clock_build5").x + get_size_tag("clock_build5").x/2 - 5, get_position_tag("clock_build5").y + 5});
        set_text_visible_tag("build_text5", true);
    } else if (get_text_visible_tag("build_text5")) {
        set_text_tag("build_text5", my_itoa(time, 0));
        if (elapsed_time_seconds(1, &increment, &save)) {
            time -= 1;
            my_pass++;
        }
        if (time <= 0) {
            set_exits_tag("clock_build5", false);
            set_text_visible_tag("build_text5", false);
            time = 10;
            var->tower.valide_position_5 = false;
        }
    }
    if (my_pass >= 2 && time < 8) {
        if (i == 1)
            set_shape_tag("Tower_1.5", (sfIntRect){get_shape_tag("Tower_1.5").left + 428, 0, 118, get_size_tag("Tower_1.5").y}, true);
        else
            set_visible_tag("Tower_1.5", false);
        if (i == 2)
            set_shape_tag("Tower_2.5", (sfIntRect){get_shape_tag("Tower_2.5").left + 428, 0, 118, get_size_tag("Tower_2.5").y}, true);
        else
            set_visible_tag("Tower_2.5", false);
        if (i == 3)
            set_shape_tag("Tower_3.5", (sfIntRect){get_shape_tag("Tower_3.5").left + 428, 0, 118, get_size_tag("Tower_3.5").y}, true);
        else
            set_visible_tag("Tower_3.5", false);
        my_pass = 0;
    }
}
