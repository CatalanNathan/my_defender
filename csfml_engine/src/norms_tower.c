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
    if (*my_pass >= 2 && time < 8) {
        if (i == 1)
            set_shape_tag(my_strcat_char(my_strdup("Tower_1."), c),
            (sfIntRect){get_shape_tag(my_strcat_char(my_strdup("Tower_1."), c))
            .left + 428, 0, 118, get_size_tag(my_strcat_char(
            my_strdup("Tower_1."), c)).y}, true);
        else
            set_visible_tag(my_strcat_char(my_strdup("Tower_1."), c), false);
        if (i == 2)
            set_shape_tag(my_strcat_char(my_strdup("Tower_2."), c), (sfIntRect)
            {get_shape_tag(my_strcat_char(my_strdup("Tower_2."), c)).left + 428
            , 0, 118, get_size_tag(my_strcat_char(my_strdup("Tower_2."), c)).y}
            , true);
        else
            set_visible_tag(my_strcat_char(my_strdup("Tower_2."), c), false);
        fucking_norms(i, c);
        *my_pass = 0;
    }
}

void check_elipse_time(float *increment, float *save, float *time, int *my_pas)
{
    if (elapsed_time_seconds(1, increment, save)) {
        (*time) -= 1;
        (*my_pas)++;
    }
}

void checker_time(float *time, char *tag_clock, char *tag_build, bool *valid_t)
{
    if ((*time) <= 0) {
        set_exits_tag(tag_clock, false);
        set_text_visible_tag(tag_build, false);
        (*time) = 10;
        (*valid_t) = false;
    }
}

void position_tag(char *build_tag, char *clock_tag)
{
    set_text_position_tag(build_tag, (V2f){get_position_tag(clock_tag).x + 
    get_size_tag(clock_tag).x / 2 - 5, get_position_tag(clock_tag).y + 5});
    set_text_visible_tag(build_tag, true);
}
