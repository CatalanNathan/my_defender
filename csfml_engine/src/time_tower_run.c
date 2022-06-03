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
float check_elipse_time(float *increment, float *save,
int *my_pas, var_t *var);
void checker_time(float *time, char **tags, bool *valid_t, int *i);
void position_tag(char *build_tag, char *clock_tag);

void time_tower_run_one(var_t *var, char **tags, int *i)
{
    static float increment = 0.00;
    static float save = 0.00;
    static float time = 10;
    static int my_pass = 0;

    if (*i == 0 && get_exits_tag("clock_build1"))
        set_timer_build(i, &time, var);
    if (!var->tower.valide_position_1)
        return;
    if (get_exits_tag("clock_build1") && !get_text_visible_tag("build_text1"))
        position_tag("build_text1", "clock_build1");
    else if (get_exits_tag("clock_build1")) {
        set_text_tag("build_text1", my_itoa(time, 0));
        time -= check_elipse_time(&increment, &save, &my_pass, var);
        if (var->pause)
            return;
        tags[0] = my_strdup("clock_build1");
        tags[1] = my_strdup("build_text1");
        checker_time(&time, tags, &var->tower.valide_position_1, i);
    }
    norms(&my_pass, (*i), time, '1');
}

void time_tower_run_two(var_t *var, char **tags, int *i)
{
    static float increment = 0.00;
    static float save = 0.00;
    static float time = 10;
    static int my_pass = 0;

    if (*i == 0 && get_exits_tag("clock_build2"))
        set_timer_build(i, &time, var);
    if (!var->tower.valide_position_2)
        return;
    if (get_exits_tag("clock_build2") && !get_text_visible_tag("build_text2"))
        position_tag("build_text2", "clock_build2");
    else if (get_text_visible_tag("build_text2")) {
        set_text_tag("build_text2", my_itoa(time, 0));
        time -= check_elipse_time(&increment, &save, &my_pass, var);
        if (var->pause)
            return;
        tags[0] = my_strdup("clock_build2");
        tags[1] = my_strdup("build_text2");
        checker_time(&time, tags, &var->tower.valide_position_2, i);
    }
    norms(&my_pass, (*i), time, '2');
}

void time_tower_run_three(var_t *var, char **tags, int *i)
{
    static float increment = 0.00;
    static float save = 0.00;
    static float time = 10;
    static int my_pass = 0;

    if (*i == 0 && get_exits_tag("clock_build3"))
        set_timer_build(i, &time, var);
    if (!var->tower.valide_position_3)
        return;
    if (get_exits_tag("clock_build3") && !get_text_visible_tag("build_text3"))
            position_tag("build_text3", "clock_build3");
    else if (get_text_visible_tag("build_text3")) {
        set_text_tag("build_text3", my_itoa(time, 0));
        time -= check_elipse_time(&increment, &save, &my_pass, var);
        tags[0] = my_strdup("clock_build3");
        tags[1] = my_strdup("build_text3");
        checker_time(&time, tags, &var->tower.valide_position_3, i);
    }
    norms(&my_pass, (*i), time, '3');
}

void time_tower_run_four(var_t *var, char **tags, int *i)
{
    static float increment = 0.00;
    static float save = 0.00;
    static float time = 10;
    static int my_pass = 0;

    if (*i == 0 && get_exits_tag("clock_build4"))
        set_timer_build(i, &time, var);
    if (!var->tower.valide_position_4)
        return;
    if (get_exits_tag("clock_build4") && !get_text_visible_tag("build_text4"))
        position_tag("build_text4", "clock_build4");
    else if (get_text_visible_tag("build_text4")) {
        set_text_tag("build_text4", my_itoa(time, 0));
        time -= check_elipse_time(&increment, &save, &my_pass, var);
        if (var->pause)
            return;
        tags[0] = my_strdup("clock_build4");
        tags[1] = my_strdup("build_text4");
        checker_time(&time, tags, &var->tower.valide_position_4, i);
    }
    norms(&my_pass, (*i), time, '4');
}

void time_tower_run_five(var_t *var, char **tags, int *i)
{
    static float increment = 0.00;
    static float save = 0.00;
    static float time = 10;
    static int my_pass = 0;

    if (*i == 0 && get_exits_tag("clock_build5"))
        set_timer_build(i, &time, var);
    if (!var->tower.valide_position_5)
        return;
    if (get_exits_tag("clock_build5") && !get_text_visible_tag("build_text5"))
        position_tag("build_text5", "clock_build5");
    else if (get_text_visible_tag("build_text5")) {
        set_text_tag("build_text5", my_itoa(time, 0));
        time -= check_elipse_time(&increment, &save, &my_pass, var);
        if (var->pause)
            return;
        tags[0] = my_strdup("clock_build5");
        tags[1] = my_strdup("build_text5");
        checker_time(&time, tags, &var->tower.valide_position_5, i);
    }
    norms(&my_pass, (*i), time, '5');
}
