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
void set_all_bar(var_t *var);

void create_all_towers(var_t *var)
{
    create_tower("Tower_lv1.png", (V2f){815, 480}, var, "Tower_1.1");
    create_tower("Tower_lv1.png", (V2f){1140, 350}, var, "Tower_1.2");
    create_tower("Tower_lv1.png", (V2f){1030, 538}, var, "Tower_1.3");
    create_tower("Tower_lv1.png", (V2f){620, 310}, var, "Tower_1.4");
    create_tower("Tower_lv1.png", (V2f){900, 210}, var, "Tower_1.5");
    create_tower("Tower_lv2.png", (V2f){815, 482}, var, "Tower_2.1");
    create_tower("Tower_lv2.png", (V2f){1140, 352}, var, "Tower_2.2");
    create_tower("Tower_lv2.png", (V2f){1030, 535}, var, "Tower_2.3");
    create_tower("Tower_lv2.png", (V2f){620, 307}, var, "Tower_2.4");
    create_tower("Tower_lv2.png", (V2f){900, 207}, var, "Tower_2.5");
    create_tower("Tower_lv3.png", (V2f){820, 470}, var, "Tower_3.1");
    create_tower("Tower_lv3.png", (V2f){1146, 340}, var, "Tower_3.2");
    create_tower("Tower_lv3.png", (V2f){1036, 525}, var, "Tower_3.3");
    create_tower("Tower_lv3.png", (V2f){626, 297}, var, "Tower_3.4");
    create_tower("Tower_lv3.png", (V2f){906, 197}, var, "Tower_3.5");
}

static void create_all_tower_and_wall(var_t *var)
{
    create_all_towers(var);
    create_wall("brick-wall.png", (V2f){1190, 600}, var, "btn_wall_1");
    create_wall("brick-wall.png", (V2f){680, 605}, var, "btn_wall_2");
    create_wall("brick-wall.png", (V2f){980, 440}, var, "btn_wall_3");
    create_build_time(var);
    create_object("wall.png", "wall_1", 9);
    set_position_tag("wall_1", (V2f){1150, 535});
    create_object("wall.png", "wall_2", 9);
    set_position_tag("wall_2", (V2f){get_position_tag("btn_wall_2").x +
    55, get_position_tag("btn_wall_2").y - 63});
    create_object("wall.png", "wall_3", 9);
    set_position_tag("wall_3", (V2f){get_position_tag("btn_wall_3").x -
    48, get_position_tag("btn_wall_3").y + 10});
    set_exits_tag("wall_1", false);
    set_exits_tag("wall_2", false);
    set_exits_tag("wall_3", false);
    create_all_buttons(var);
    var->color_tower = get_sprite_color_tag("Tower_1.1");
}

static void create_all_bar(var_t *var)
{
    var->b_constructor = create_object("bconstructor.png",
    "constructMenu", 10);
    set_position_obj(var->b_constructor, (V2f){50, 965});
    set_shape_obj(&var->b_constructor, (sfIntRect){0, 0, 83, 85}, true);
    var->hearth = create_object("heart-attack.png", "hearth", 8);
    set_all_bar(var);
    create_selected_tower(var);
    create_interface(var);
    create_tools(var);
    create_info(var);
    create_settings(var);
    create_object("monster.png", "bar_monster", 8);
    set_position_tag("bar_monster", (V2f){(1890 -
    get_size_tag("bar_monster").x), (1050 - get_size_tag("bar_monster").y)});

}

static void create_all_text(var_t *var)
{
    create_text(my_strcat("HP : ", my_itoa(var->castle_life, 0)), "CastleHP");
    set_text_position_tag("CastleHP", (V2f){935, 220});
    create_text(format_number(my_itoa(var->money, 0), var->money), "money");
    set_text_size_tag("money", 30);
    set_text_position_tag("money", (V2f){get_position_tag("bar_money").x +
    get_size_tag("bar_money").x/2 - (5 * int_size(var->money)),
    get_position_tag("bar_money").y + 20});
    create_text(format_number(my_itoa(var->price_wall, 0),
    var->price_wall), "price_wall");
    set_text_visible_tag("price_wall", false);
    create_text(" ", "text_clock_timer1");
    create_text(" ", "text_clock_timer2");
    create_text(" ", "text_clock_timer3");
    create_text_build_time();
    create_text("information", "info+");
    set_text_visible_tag("info+", false);
    create_text(my_itoa(var->nb_enemies, 0), "text_enemies");
    set_text_position_tag("text_enemies", (V2f){GPT("bar_monster").x +
    (get_size_tag("bar_monster").x / 2), GPT("bar_monster").y + 15});
    set_text_size_tag("text_enemies", 15);
}

void create_loop_game(var_t *var)
{
    create_music_game(var);
    create_all_game_value(var);
    create_all_tower_and_wall(var);
    create_all_bar(var);
    create_all_text(var);
    create_cursor(var);
}
