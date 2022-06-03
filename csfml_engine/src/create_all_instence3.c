/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-mydefender-guillaume.kucia
** File description:
** create_all_instence3
*/

#include "engine.h"
#include "my.h"
#include "var.h"

void set_all_bar(var_t *var)
{
    set_scale_obj(&var->hearth, (sfVector2f){0.05, 0.05});
    set_position_obj(var->hearth, (sfVector2f){954, 194});
    create_object("Money_bar.png", "money_bar", 0);
    set_visible_tag("money_bar", false);
    create_object("global_money.png", "bar_money", 9);
    set_position_tag("bar_money", (V2f){engine.win_settings.size.x -
    get_size_tag("bar_money").x - 40, 40});
    create_object("Ruby_life.png", "ruby_life", 7);
    set_position_tag("ruby_life", (V2f){(get_position_tag("hearth").x +
    get_size_tag("hearth").x/2) - get_size_tag("ruby_life").x/2,
    get_position_tag("hearth").y + 50});
    create_object("white_life.png", "white_life", 8);
    set_position_tag("white_life", (V2f){(get_position_tag("hearth").x +
    get_size_tag("hearth").x/2) - get_size_tag("white_life").x/2,
    get_position_tag("hearth").y + 50});
}
