/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** update_text_and_buttons
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

void update_button_exists(char *tag_obj, char *tag_button, float *incrementation, float *save)
{
    if (get_exits_tag(tag_obj) && elapsed_time_seconds(5, incrementation, save)) {
        set_exits_tag(tag_obj, false);
        set_exits_tag(tag_button, true);
        if (!get_exits_tag("wall_1")) {
            set_text_visible_tag("text_clock_timer1", false);
            set_exits_tag("clock_wall1", false);
        }
        if (!get_exits_tag("wall_2")) {
            set_text_visible_tag("text_clock_timer2", false);
            set_exits_tag("clock_wall2", false);
        }
        if (!get_exits_tag("wall_3")) {
            set_text_visible_tag("text_clock_timer3", false);
            set_exits_tag("clock_wall3", false);
        }
        return;
    }
    if (get_exits_tag("wall_1") && equal(tag_obj, "wall_1")) {
        set_text_visible_tag("text_clock_timer1", true);
        set_text_tag("text_clock_timer1", my_strcat(my_itoa(5 - ((int)(*incrementation) / 1000000), 0), "s"));
        set_text_position_tag("text_clock_timer1", (V2f){1136, 525});
    }
    if (get_exits_tag("wall_2") && equal(tag_obj, "wall_2")) {
        set_text_visible_tag("text_clock_timer2", true);
        set_text_tag("text_clock_timer2", my_strcat(my_itoa(5 - ((int)(*incrementation) / 1000000), 0), "s"));
        set_text_position_tag("text_clock_timer2", (V2f){795, 530});
    }
    if (get_exits_tag("wall_3") && equal(tag_obj, "wall_3")) {
        set_text_visible_tag("text_clock_timer3", true);
        set_text_tag("text_clock_timer3", my_strcat(my_itoa(5 - ((int)(*incrementation) / 1000000), 0), "s"));
        set_text_position_tag("text_clock_timer3", (V2f){993, 436});
    }
}
