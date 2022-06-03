/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** norms_tower
*/

#include "engine.h"
#include "var.h"
#include "my.h"

void fucking_norms(int i, char c)
{
    if (i == 3)
        set_shape_tag(my_strcat_char(my_strdup("Tower_3."), c), (sfIntRect)
        {get_shape_tag(my_strcat_char(my_strdup("Tower_3."), c)).left + 428
        , 0, 118, get_size_tag(my_strcat_char(my_strdup("Tower_3."), c)).y}
        , true);
    else
        set_visible_tag(my_strcat_char(my_strdup("Tower_3."), c), false);
}

void norms(int *my_pass, int i, int time, char c)
{
    static int guard = 2;
    static int quick = 8;

    guard_and_quick(i, &guard, &quick);
    if (*my_pass >= guard && time < quick) {
        construction_tower(i, c);
        fucking_norms(i, c);
        *my_pass = 0;
    }
}

float check_elipse_time(float *increment, float *save, int *my_pas, var_t *var)
{
    float i = 0;

    if (elapsed_time_seconds(1, increment, save)) {
        if (var->pause)
            return i;
        i = 1;
        (*my_pas)++;
    }
    return i;
}

void checker_time(float *time, char **tags, bool *valid_t, int *i)
{
    if ((*time) <= 0) {
        set_exits_tag(tags[0], false);
        set_text_visible_tag(tags[1], false);
        (*time) = 10;
        (*valid_t) = false;
        *i = 0;
    }
}

void position_tag(char *build_tag, char *clock_tag)
{
    set_text_position_tag(build_tag, (V2f){get_position_tag(clock_tag).x +
    get_size_tag(clock_tag).x / 2 - 5, get_position_tag(clock_tag).y + 5});
    set_text_visible_tag(build_tag, true);
}
