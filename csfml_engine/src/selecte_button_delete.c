/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** selecte_button_delete.c
*/

#include "engine.h"
#include "var.h"
#include "my.h"

void btn_deleted(var_t *var, float calc_shape)
{
    if (mouse_inside_tag("delete") && get_exits_tag("delete")) {
        // if (mouse_pressed(sfMouseLeft, &mouse))
            //RIEN POUR LE MOMENT
        set_shape_tag("delete", (sfIntRect){get_size_tag("delete").x,
        0, get_size_tag("delete").x, get_size_tag("delete").y}, true);
        change_cursor(var);
    } else
        set_shape_tag("delete", (sfIntRect){0, 0,
        calc_shape, get_size_tag("delete").y}, true);
}

void btn_delete(var_t *var)
{
    float calc_shape = 0.00;
    static int mouse = 0;

    if (get_position_tag("btools").x + get_size_tag("btools").x < 
    get_position_tag("delete").x + get_texture_size_tag("delete").x / 2)
        calc_shape = (get_position_tag("btools").x + get_size_tag("btools").x)
        - get_position_tag("delete").x;
    else
        calc_shape = get_texture_size_tag("delete").x / 2;
    if (get_position_tag("btools").x + get_size_tag("btools").x >
    get_position_tag("delete").x) {
        set_exits_tag("delete", true);
        set_shape_tag("selete_tower_1", (sfIntRect){0, 0,
        calc_shape, get_size_tag("delete").y}, true);
    } else
        set_exits_tag("delete", false);
    btn_deleted(var, calc_shape);
}

void selecte_button_delete(var_t *var)
{
    btn_delete(var);
}
