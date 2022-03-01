/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** mconstruct.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void animation_construct(var_t *var, float time_pass)
{
    if (get_shape_obj(&var->b_constructor).width < (int)get_texture_size_obj(&var->b_constructor).x) {
        set_shape_obj(&var->b_constructor, (sfIntRect){0, 85, get_shape_obj(&var->b_constructor).width + (0.001 * time_pass), 85}, true);
        set_position_tag("btools", (V2f){get_position_tag("btools").x + (0.00094 * time_pass), get_position_tag("btools").y});
    }
}

void animation_construct_return(var_t *var, int *retract, float time_pass)
{
    if (get_shape_obj(&var->b_constructor).width > 83) {
        set_shape_obj(&var->b_constructor, (sfIntRect){0, 85, get_shape_obj(&var->b_constructor).width - (0.001 * time_pass), 85}, true);
        set_position_tag("btools", (V2f){get_position_tag("btools").x - (0.001 * time_pass), get_position_tag("btools").y});
    }
    else if (get_shape_obj(&var->b_constructor).width <= 83) {
        *retract = 0;
        set_shape_obj(&var->b_constructor, (sfIntRect){0, 0, 83, 85}, true);
        set_position_tag("btools", (V2f){150, get_position_tag("constructMenu").y - 5});
    }
}

void manage_construct(var_t *var)
{
    static int retract = 0;
    static int MB_pressed = 0;
    static float time_pass = 0.00;
    static float save = 0.00;
    static int i = 0;

    get_elapsed_time(&time_pass, &save);
    if (mouse_inside_obj(&var->b_constructor) && get_shape_obj(&var->b_constructor).top == 0) {
        set_shape_obj(&var->b_constructor, (sfIntRect){83, 0, 83, 85}, true);
        add_info_more(var, time_pass, &i, "Build");
        change_cursor(var);
        if (mouse_pressed(sfMouseLeft, &MB_pressed) && get_shape_obj(&var->b_constructor).top == 0)
            set_shape_obj(&var->b_constructor, (sfIntRect){0, 85, 83, 85}, true);
    } else if (get_shape_obj(&var->b_constructor).top == 0) {
        set_shape_obj(&var->b_constructor, (sfIntRect){0, 0, 83, 85}, true);
        i = 0;
    }
    if (get_shape_obj(&var->b_constructor).top != 0 && retract != 1)
        animation_construct(var, time_pass);
    if (mouse_inside_obj(&var->b_constructor) && get_shape_obj(&var->b_constructor).width > 83) {
        if (mouse_pressed(sfMouseLeft, &MB_pressed))
            retract = 1;
    }
    if (retract == 1)
        animation_construct_return(var, &retract, time_pass);
    btools(var);
}
