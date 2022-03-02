/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** time_tower_run.c
*/

#include "engine.h"
#include "var.h"
#include "my.h"

void fucking_norms(int i, char c);
void norms(int *my_pass, int i, int time, char c);
void check_elipse_time(float *increment, float *save, float *time, int *my_pas);
void checker_time(float *time, char *tag_clock, char *tag_build, bool *valid_t);
void position_tag(char *build_tag, char *clock_tag);

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
    if (get_exits_tag("clock_build1") &&
    get_text_visible_tag("build_text1") == false)
        position_tag("build_text1", "clock_build1");
    else if (get_text_visible_tag("build_text1")) {
        set_text_tag("build_text1", my_itoa(time, 0));
        check_elipse_time(&increment, &save, &time, &my_pass);
        checker_time(&time, "clock_build1", "build_text1", &var->tower.valide_position_1);
    }
    norms(&my_pass, i, time, '1');
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
    if (get_exits_tag("clock_build2") &&
    get_text_visible_tag("build_text2") == false)
        position_tag("build_text2", "clock_build2");
    else if (get_text_visible_tag("build_text2")) {
        set_text_tag("build_text2", my_itoa(time, 0));
        check_elipse_time(&increment, &save, &time, &my_pass);
        checker_time(&time, "clock_build2", "build_text2", &var->tower.valide_position_2);
    }
    norms(&my_pass, i, time, '2');
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
    if (get_exits_tag("clock_build3") &&
    get_text_visible_tag("build_text3") == false)
            position_tag("build_text3", "clock_build3");
    else if (get_text_visible_tag("build_text3")) {
        set_text_tag("build_text3", my_itoa(time, 0));
        check_elipse_time(&increment, &save, &time, &my_pass);
        checker_time(&time, "clock_build3", "build_text3", &var->tower.valide_position_3);
    }
    norms(&my_pass, i, time, '3');
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
    if (get_exits_tag("clock_build4") &&
    get_text_visible_tag("build_text4") == false)
        position_tag("build_text4", "clock_build4");
    else if (get_text_visible_tag("build_text4")) {
        set_text_tag("build_text4", my_itoa(time, 0));
        check_elipse_time(&increment, &save, &time, &my_pass);
        checker_time(&time, "clock_build4", "build_text4", &var->tower.valide_position_4);
    }
    norms(&my_pass, i, time, '4');
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
    if (get_exits_tag("clock_build5") &&
    get_text_visible_tag("build_text5") == false)
        position_tag("build_text5", "clock_build5");
    else if (get_text_visible_tag("build_text5")) {
        set_text_tag("build_text5", my_itoa(time, 0));
        check_elipse_time(&increment, &save, &time, &my_pass);
        checker_time(&time, "clock_build5", "build_text5", &var->tower.valide_position_5);
    }
    norms(&my_pass, i, time, '5');
}
