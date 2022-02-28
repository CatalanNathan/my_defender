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
    var->thor_mod = false;
    var->castle_life = 1000;
    var->nb_enemies = 20;
    var->money = 100000;
    var->price_wall = 5000;
    var->wall.wait_time = 10;
    var->tower.price_tower_1 = 20000;
    var->tower.price_tower_2 = 50000;
    var->tower.price_tower_3 = 90000;
    var->tower.build_time_t1 = 10;
    var->tower.build_time_t2 = 15;
    var->tower.buil_time__t3 = 25;
    var->tower.tower_selected = 0;
}

void create_all_buttons(var_t *var)
{
    create_object("clock_time_wall.png", "clock_wall1", 8);
    set_position_tag("clock_wall1", (V2f){1100, 520});
    create_object("clock_time_wall.png", "clock_wall2", 8);
    set_position_tag("clock_wall2", (V2f){760, 525});
    create_object("clock_time_wall.png", "clock_wall3", 8);
    set_position_tag("clock_wall3", (V2f){960, 430});
    set_exits_tag("clock_wall1", false);
    set_exits_tag("clock_wall2", false);
    set_exits_tag("clock_wall3", false);
}