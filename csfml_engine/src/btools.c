/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** btools.c
*/

#include "engine.h"
#include "my.h"
#include "var.h"

void animation_btools(var_t *var, float time_pass)
{
    if (get_shape_tag("btools").width < (int)get_texture_size_tag("btools").x)
        set_shape_tag("btools", (sfIntRect){0, 85,
        get_shape_tag("btools").width + (0.001 * time_pass), 85}, true);
}

void animation_btools_exept(var_t *var, int *retract, float time_pass)
{
    if (get_shape_tag("btools").width > 87)
        set_shape_tag("btools", (sfIntRect){0, 85,
        get_shape_tag("btools").width - (0.001 * time_pass), 85}, true);
    else if (get_shape_tag("btools").width <= 87) {
        *retract = 0;
        set_shape_tag("btools", (sfIntRect){0, 0, 87, 85}, true);
    }
}

void btools3(var_t *var, int *retract, int time_pass, int *MB_pressed)
{
    if (get_shape_tag("btools").top != 0 && (*retract) != 1)
        animation_btools(var, time_pass);
    if (mouse_inside_tag("btools") && get_shape_tag("btools").width > 83) {
        if (mouse_pressed(sfMouseLeft, MB_pressed))
            (*retract) = 1;
    }
    if ((*retract) == 1)
        animation_btools_exept(var, retract, time_pass);
}

void btools2(var_t *var, int *MB_pressed, int *i)
{
    if (mouse_inside_tag("btools") && get_shape_tag("btools").top == 0) {
        set_shape_tag("btools", (sfIntRect){87, 0, 84, 85}, true);
        change_cursor(var, "cursor");
        if (mouse_pressed(sfMouseLeft, MB_pressed) &&
            get_shape_tag("btools").top == 0)
            set_shape_tag("btools", (sfIntRect){0, 85, 83, 85}, true);
    } else if (get_shape_tag("btools").top == 0) {
        set_shape_tag("btools", (sfIntRect){0, 0, 87, 85}, true);
        (*i) = 0;
    }
}

void btools(var_t *var)
{
    static int retract = 0;
    static int MB_pressed = 0;
    static float time_pass = 0.00;
    static float save = 0.00;
    static int i = 0;

    get_elapsed_time(&time_pass, &save);
    btools2(var, &MB_pressed, &i);
    btools3(var, &retract, time_pass, &MB_pressed);
}
