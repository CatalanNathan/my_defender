/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** selected_tower.c
*/

#include "engine.h"
#include "my.h"
#include "var.h"

// le 6 janvier 1988
// tacos 4 viandes 2 poulet de kebab algerien barbecue
// Boite de nuggets
// enceinte de poche
// arizona
// gente voiture
// shapooing peliculaire
// joint du culas
// my_runner
// 30% de chez tesla
// menthe à la religion

void first_btn_tower(var_t *var)
{
    float calc_shape;
    static int mouse = 0.00;
    static float time = 0.00;
    static float save = 0.00;
    static int i = 0;

    get_elapsed_time(&time, &save);
    if (get_position_tag("constructMenu").x + get_size_tag("constructMenu").x <  get_position_tag("selecte_tower_1").x + get_texture_size_tag("selecte_tower_1").x/2)
        calc_shape = (get_position_tag("constructMenu").x + get_size_tag("constructMenu").x) - get_position_tag("selecte_tower_1").x;
    else
        calc_shape = get_texture_size_tag("selecte_tower_1").x/2;

    if (get_position_tag("constructMenu").x + get_size_tag("constructMenu").x > get_position_tag("selecte_tower_1").x) {
        set_exits_tag("selecte_tower_1", true);
        set_shape_tag("selete_tower_1", (sfIntRect){0, 0, calc_shape, get_size_tag("selecte_tower_1").y}, true);
    } else
        set_exits_tag("selecte_tower_1", false);

    if (mouse_inside_tag("selecte_tower_1") && get_exits_tag("selecte_tower_1")) {
        add_info_more(var, time, &i, "Brick tower :\n\nHP :");
        if (mouse_pressed(sfMouseLeft, &mouse)) {
            var->thor_mod = true;
            var->tower.tower_selected = 1;
        }
        set_shape_tag("selecte_tower_1", (sfIntRect){get_size_tag("selecte_tower_1").x, 0, get_size_tag("selecte_tower_1").x, get_size_tag("selecte_tower_1").y}, true);
        change_cursor(var);
    } else {
        set_shape_tag("selecte_tower_1", (sfIntRect){0, 0, calc_shape, get_size_tag("selecte_tower_1").y}, true);
        i = 0;
    }
}

void second_btn_tower(var_t *var)
{
    float calc_shape;
    static int mouse = 0.00;

    if (get_position_tag("constructMenu").x + get_size_tag("constructMenu").x <  get_position_tag("selecte_tower_2").x + get_texture_size_tag("selecte_tower_2").x/2)
        calc_shape = (get_position_tag("constructMenu").x + get_size_tag("constructMenu").x) - get_position_tag("selecte_tower_2").x;
    else
        calc_shape = get_texture_size_tag("selecte_tower_2").x/2;

    if (get_position_tag("constructMenu").x + get_size_tag("constructMenu").x > get_position_tag("selecte_tower_2").x) {
        set_exits_tag("selecte_tower_2", true);
        set_shape_tag("selete_tower_1", (sfIntRect){0, 0, calc_shape, get_size_tag("selecte_tower_2").y}, true);
    } else
        set_exits_tag("selecte_tower_2", false);

    if (mouse_inside_tag("selecte_tower_2") && get_exits_tag("selecte_tower_2")) {
        if (mouse_pressed(sfMouseLeft, &mouse)) {
            var->thor_mod = true;
            var->tower.tower_selected = 2;
        }
        set_shape_tag("selecte_tower_2", (sfIntRect){get_size_tag("selecte_tower_2").x, 0, get_size_tag("selecte_tower_2").x, get_size_tag("selecte_tower_2").y}, true);
        change_cursor(var);
    } else
        set_shape_tag("selecte_tower_2", (sfIntRect){0, 0, calc_shape, get_size_tag("selecte_tower_2").y}, true);
}

void third_btn_tower(var_t *var)
{
    float calc_shape;
    static int mouse = 0.00;

    if (get_position_tag("constructMenu").x + get_size_tag("constructMenu").x <  get_position_tag("selecte_tower_3").x + get_texture_size_tag("selecte_tower_3").x/2)
        calc_shape = (get_position_tag("constructMenu").x + get_size_tag("constructMenu").x) - get_position_tag("selecte_tower_3").x;
    else
        calc_shape = get_texture_size_tag("selecte_tower_3").x/2;

    if (get_position_tag("constructMenu").x + get_size_tag("constructMenu").x > get_position_tag("selecte_tower_3").x) {
        set_exits_tag("selecte_tower_3", true);
        set_shape_tag("selete_tower_1", (sfIntRect){0, 0, calc_shape, get_size_tag("selecte_tower_3").y}, true);
    } else
        set_exits_tag("selecte_tower_3", false);

    if (mouse_inside_tag("selecte_tower_3") && get_exits_tag("selecte_tower_3")) {
        if (mouse_pressed(sfMouseLeft, &mouse)) {
            var->thor_mod = true;
            var->tower.tower_selected = 3;
        }
        set_shape_tag("selecte_tower_3", (sfIntRect){get_size_tag("selecte_tower_3").x, 0, get_size_tag("selecte_tower_3").x, get_size_tag("selecte_tower_3").y}, true);
        change_cursor(var);
    } else
        set_shape_tag("selecte_tower_3", (sfIntRect){0, 0, calc_shape, get_size_tag("selecte_tower_3").y}, true);
}

void selected_button_tower(var_t *var)
{
    first_btn_tower(var);
    second_btn_tower(var);
    third_btn_tower(var);
}

void create_selected_tower(var_t *var)
{
    create_object("selecte_tower_1.png", "selecte_tower_1", 7);
    set_shape_tag("selecte_tower_1", (sfIntRect){ 0, 0, get_size_tag("selecte_tower_1").x/2, get_size_tag("selecte_tower_1").y}, true);
    set_position_tag("selecte_tower_1", (V2f){get_position_tag("constructMenu").x + 110, get_position_tag("constructMenu").y + 6});

    create_object("selecte_tower_2.png", "selecte_tower_2", 7);
    set_shape_tag("selecte_tower_2", (sfIntRect){ 0, 0, get_size_tag("selecte_tower_2").x/2, get_size_tag("selecte_tower_2").y}, true);
    set_position_tag("selecte_tower_2", (V2f){get_position_tag("constructMenu").x + 195, get_position_tag("constructMenu").y + 6});

    create_object("selecte_tower_3.png", "selecte_tower_3", 7);
    set_shape_tag("selecte_tower_3", (sfIntRect){ 0, 0, get_size_tag("selecte_tower_3").x/2, get_size_tag("selecte_tower_3").y}, true);
    set_position_tag("selecte_tower_3", (V2f){get_position_tag("constructMenu").x + 280, get_position_tag("constructMenu").y + 6});

    create_their_text(var);
}
