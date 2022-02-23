/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** create_all_instance
*/

#include "engine.h"
#include "my.h"
#include "var.h"

void create_all_game_value(var_t *var);
void create_all_buttons(var_t *var);

static void create_all_tower_and_wall(var_t *var)
{
    create_tower("Tower_lv1.png", (V2f){870, 335}, var, "Tower_1");
    create_tower("Tower_lv1.png", (V2f){750, 10}, var, "Tower_2");
    create_tower("Tower_lv1.png", (V2f){1000, 140}, var, "Tower_3");
    create_tower("Tower_lv1.png", (V2f){660, 290}, var, "Tower_4");
    create_tower("Tower_lv1.png", (V2f){470, 110}, var, "Tower_5");
    create_wall("brick-wall.png", (V2f){1190, 600}, var, "btn_wall_1");
    create_wall("brick-wall.png", (V2f){680, 605}, var, "btn_wall_2");
    create_wall("brick-wall.png", (V2f){980, 440}, var, "btn_wall_3");
    create_object("wall.png", "wall_1", 9);
    set_position_tag("wall_1", (V2f){1150, 535});
    create_object("wall.png", "wall_2", 9);
    set_position_tag("wall_2", (V2f){get_position_tag("btn_wall_2").x + 55, get_position_tag("btn_wall_2").y - 63});
    create_object("wall.png", "wall_3", 9);
    set_position_tag("wall_3", (V2f){get_position_tag("btn_wall_3").x - 48, get_position_tag("btn_wall_3").y + 10});
    set_exits_tag("wall_1", false);
    set_exits_tag("wall_2", false);
    set_exits_tag("wall_3", false);
    create_all_buttons(var);
    var->color_tower = get_sprite_color_tag("Tower_1");
}

static void create_all_bar(var_t *var)
{
    var->b_constructor = create_object("bconstructor.png", "constructMenu", 10);
    set_position_obj(var->b_constructor, (V2f){50, 965});
    set_shape_obj(&var->b_constructor, (sfIntRect){0, 0, 83, 85}, true);
    var->hearth = create_object("heart-attack.png", "hearth", 8);
    set_scale_obj(&var->hearth, (sfVector2f){0.05, 0.05});
    set_position_obj(var->hearth, (sfVector2f){954, 194});
    create_object("Money_bar.png", "money_bar", 0);
    set_visible_tag("money_bar", false);
    create_object("global_money.png", "bar_money", 9);
    set_position_tag("bar_money", (V2f){engine.win_settings.size.x - get_size_tag("bar_money").x - 40, 40});
    create_object("Ruby_life.png", "ruby_life", 7);
    set_position_tag("ruby_life", (V2f){(get_position_tag("hearth").x + get_size_tag("hearth").x/2) - get_size_tag("ruby_life").x/2, get_position_tag("hearth").y + 50});
    create_object("white_life.png", "white_life", 8);
    set_position_tag("white_life", (V2f){(get_position_tag("hearth").x + get_size_tag("hearth").x/2) - get_size_tag("white_life").x/2, get_position_tag("hearth").y + 50});
    create_selected_tower(var);
}

static void create_all_text(var_t *var)
{
    create_text(my_strcat("HP : ", my_itoa(var->castle_life, 0)), "CastleHP");
    set_text_position_tag("CastleHP", (V2f){935, 220});
    create_text(format_number(my_itoa(var->money, 0), var->money), "money");
    set_text_size_tag("money", 30);
    set_text_position_tag("money", (V2f){get_position_tag("bar_money").x + get_size_tag("bar_money").x/2 - (5 * int_size(var->money)), get_position_tag("bar_money").y + 20});
    create_text(format_number(my_itoa(var->price_wall, 0), var->price_wall), "price_wall");
    set_text_visible_tag("price_wall", false);

}

void create_loop_game(var_t *var)
{
    create_all_game_value(var);
    create_all_text(var);
    create_all_tower_and_wall(var);
    create_all_bar(var);
}
