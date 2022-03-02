/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** selected_tower2
*/

#include "engine.h"
#include "my.h"
#include "var.h"

void frist_btn_tower_norms(var_t *var, int mouse, float calc_shape)
{
    if (mouse_inside_tag("selecte_tower_1") &&
    get_exits_tag("selecte_tower_1")) {
        add_info_more(var, "\t\t\t\t\tSlingshot Tower\n\nAttack"
        ": 50\nBuild : 10s\nRange : 10\n\n"
        "Description :\nThrows wooden spears at\n enemies within "
        "its perimeter\n (Smaller perimeter than archers)");
        if (mouse_pressed(sfMouseLeft, &mouse)) {
            var->thor_mod = true;
            var->tower.tower_selected = 1;
        }
        set_shape_tag("selecte_tower_1", (sfIntRect){
        get_size_tag("selecte_tower_1").x, 0,
        get_size_tag("selecte_tower_1").x, 
        get_size_tag("selecte_tower_1").y}, true);
        change_cursor(var);
    } else
        set_shape_tag("selecte_tower_1", (sfIntRect){0, 0,
        calc_shape, get_size_tag("selecte_tower_1").y}, true);
}

void second_btn_tower_norms(var_t *var, int mouse, float calc_shape)
{
    if (mouse_inside_tag("selecte_tower_2") &&
    get_exits_tag("selecte_tower_2")) {
        add_info_more(var, "\t\t\tArchers Tower\n\nAttack : 25\n"
        "Build : 15s\nRange : 40\n\n"
        "Description :\nWith archers, this tower is\n capable of "
        "hitting enemies\n from a long distance!");
        if (mouse_pressed(sfMouseLeft, &mouse)) {
            var->thor_mod = true;
            var->tower.tower_selected = 2;
        }
        set_shape_tag("selecte_tower_2", (sfIntRect){
        get_size_tag("selecte_tower_2").x, 0, 
        get_size_tag("selecte_tower_2").x,
        get_size_tag("selecte_tower_2").y}, true);
        change_cursor(var);
    } else
        set_shape_tag("selecte_tower_2", (sfIntRect){0, 0,
        calc_shape, get_size_tag("selecte_tower_2").y}, true);
}

void third_btn_tower_norms(var_t *var, int mouse, float calc_shape)
{
    if (mouse_inside_tag("selecte_tower_3") &&
    get_exits_tag("selecte_tower_3")) {
        add_info_more(var, "\t\t\t\t\t  Fire Tower\n\nAttack : 10/s\n"
        "Build : 25s\nRange : 20\n\n"
        "Description :\nThe fire tower doesn't do a lot\n of damage immediatel"
        "y but\n does damage over a long period\n of time.");
        if (mouse_pressed(sfMouseLeft, &mouse)) {
            var->thor_mod = true;
            var->tower.tower_selected = 3;
        }
        set_shape_tag("selecte_tower_3", (sfIntRect){
        get_size_tag("selecte_tower_3").x, 0,
        get_size_tag("selecte_tower_3").x, get_size_tag("selecte_tower_3").y},
        true);
        change_cursor(var);
    } else
        set_shape_tag("selecte_tower_3", (sfIntRect){0, 0,
        calc_shape, get_size_tag("selecte_tower_3").y}, true);
}
