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
    set_position_tag("cursor", (V2f){sfMouse_getPositionRenderWindow(engine.win_settings.window).x - 3, sfMouse_getPositionRenderWindow(engine.win_settings.window).y - 3});
}

void update_all_text(var_t *var)
{
    set_text_tag("CastleHP", my_strcat("HP : ", my_itoa(var->castle_life, 0)));
    set_text_position_tag("money", (V2f){get_position_tag("bar_money").x + get_size_tag("bar_money").x/2 - (5 * int_size(var->money)), get_position_tag("bar_money").y + 20});
    set_position_tag("bar_money", (V2f){engine.win_settings.size.x - get_size_tag("bar_money").x - 40, 40});
    if (var->castle_life > 0)
        set_scale_tag("ruby_life", (V2f){((var->castle_life/1000)*100)/100, get_scale_tag("ruby_life").y});
    if (var->money <= 0)
        set_text_tag("money", "0");
    else
        set_text_tag("money", format_number(my_itoa(var->money, 0), var->money));
}

void update(var_t *var)
{
    var->on_button = false;
    event_game(var);
    make_enemies(var);
    manage_enemy(var);
    manage_construct(var);
    manage_button(var);
    update_all_text(var);
    if (var->on_button == false)
        set_shape_tag("cursor", (sfIntRect){0, 0, 173, 177}, true);
}
