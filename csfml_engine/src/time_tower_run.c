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

    if (get_exits_tag("clock_build1") && get_text_visible_tag("build_text1") == false) {
        set_text_position_tag("build_text1", (V2f){get_position_tag("clock_build1").x + get_size_tag("clock_build1").x/2 - 5, get_position_tag("clock_build1").y + 5});
        set_text_visible_tag("build_text1", true);
    } else if (get_text_visible_tag("build_text1")) {
        set_text_tag("build_text1", my_itoa(time, 0));
        if (elapsed_time_seconds(1, &increment, &save))
            time -= 1;
        if (time <= 0) {
            set_exits_tag("clock_build1", false);
            set_text_visible_tag("build_text1", false);
            time = 10;
        }
    }
}

void time_tower_run_two(var_t *var)
{
    static float increment = 0.00;
    static float save = 0.00;
    static float time = 10;

    if (get_exits_tag("clock_build2") && get_text_visible_tag("build_text2") == false) {
        set_text_position_tag("build_text2", (V2f){get_position_tag("clock_build2").x + get_size_tag("clock_build2").x/2 - 5, get_position_tag("clock_build2").y + 5});
        set_text_visible_tag("build_text2", true);
    } else if (get_text_visible_tag("build_text2")) {
        set_text_tag("build_text2", my_itoa(time, 0));
        if (elapsed_time_seconds(1, &increment, &save))
            time -= 1;
        if (time <= 0) {
            set_exits_tag("clock_build2", false);
            set_text_visible_tag("build_text2", false);
            time = 10;
        }
    }
}

void time_tower_run_three(var_t *var)
{
    static float increment = 0.00;
    static float save = 0.00;
    static float time = 10;

    if (get_exits_tag("clock_build3") && get_text_visible_tag("build_text3") == false) {
        set_text_position_tag("build_text3", (V2f){get_position_tag("clock_build3").x + get_size_tag("clock_build3").x/2 - 5, get_position_tag("clock_build3").y + 5});
        set_text_visible_tag("build_text3", true);
    } else if (get_text_visible_tag("build_text3")) {
        set_text_tag("build_text3", my_itoa(time, 0));
        if (elapsed_time_seconds(1, &increment, &save))
            time -= 1;
        if (time <= 0) {
            set_exits_tag("clock_build3", false);
            set_text_visible_tag("build_text3", false);
            time = 10;
        }
    }
}

void time_tower_run_four(var_t *var)
{
    static float increment = 0.00;
    static float save = 0.00;
    static float time = 10;

    if (get_exits_tag("clock_build4") && get_text_visible_tag("build_text4") == false) {
        set_text_position_tag("build_text4", (V2f){get_position_tag("clock_build4").x + get_size_tag("clock_build4").x/2 - 5, get_position_tag("clock_build4").y + 5});
        set_text_visible_tag("build_text4", true);
    } else if (get_text_visible_tag("build_text4")) {
        set_text_tag("build_text4", my_itoa(time, 0));
        if (elapsed_time_seconds(1, &increment, &save))
            time -= 1;
        if (time <= 0) {
            set_exits_tag("clock_build4", false);
            set_text_visible_tag("build_text4", false);
            time = 10;
        }
    }
}

void time_tower_run_five(var_t *var)
{
    static float increment = 0.00;
    static float save = 0.00;
    static float time = 10;

    if (get_exits_tag("clock_build5") && get_text_visible_tag("build_text5") == false) {
        set_text_position_tag("build_text5", (V2f){get_position_tag("clock_build5").x + get_size_tag("clock_build5").x/2 - 5, get_position_tag("clock_build5").y + 5});
        set_text_visible_tag("build_text5", true);
    } else if (get_text_visible_tag("build_text5")) {
        set_text_tag("build_text5", my_itoa(time, 0));
        if (elapsed_time_seconds(1, &increment, &save))
            time -= 1;
        if (time <= 0) {
            set_exits_tag("clock_build5", false);
            set_text_visible_tag("build_text5", false);
            time = 10;
        }
    }
}
