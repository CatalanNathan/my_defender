/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** create_all_instances
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void create_all_game_value(var_t *var)
{
    var->money = 10000;
    var->price_wall = 5000;
}

void create_all_buttons(var_t *var)
{
    create_object("clock_time_wall.png", "clock_wall", 8);
    set_position_tag("clock_wall", (V2f){500, 300});
    set_scale_tag("clock_wall", (V2f){1, 1});
}