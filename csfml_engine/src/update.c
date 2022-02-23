/*
** EPITECH PROJECT, 2021
** CSFML engine
** File description:
** update.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void event_game(var_t *var)
{
    if (key_pressed(sfKeyEscape))
        game_end(0);
}

void update_all_text(var_t *var)
{
    set_text_tag("CastleHP", my_strcat("HP : ", my_itoa(var->castle_life, 0)));
    set_text_position_tag("money", (V2f){get_position_tag("global_money").x + get_size_tag("global_money").x/2 - (5 * int_size(var->money)), get_position_tag("global_money").y + 20});
    set_position_tag("global_money", (V2f){engine.win_settings.size.x - get_size_tag("global_money").x - 40, 40});
    if (var->castle_life > 0)
        set_scale_tag("ruby_life", (V2f){((var->castle_life/1000)*100)/100, get_scale_tag("ruby_life").y});
    if (var->money <= 0)
        set_text_tag("money", "0");
    else
        set_text_tag("money", format_number(my_itoa(var->money, 0), var->money));
}

void update(var_t *var)
{
    event_game(var);
    make_enemies(var);
    manage_enemy(var);
    manage_construct(var);
    manage_button(var);
    update_all_text(var);
}
