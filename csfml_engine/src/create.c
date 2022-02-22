/*
** EPITECH PROJECT, 2021
** CSFML engine
** File description:
** create.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void create_enemies(var_t *var, int possibility)
{
    int x_start = 0;
    int y_start = 0;
    V2f *path;

    if (possibility % 2 == 0) {
        x_start = 1090;
        y_start = 730;
        path = random_this((V2f[4]){{1015, 640}, {1290, 450}, {850, 250}, {0, 0}}, 4);
    } else {
        x_start = 400;
        y_start = 540;
        path = random_this((V2f[6]){{555, 470}, {750, 550}, {910, 450}, {780, 370}, {940, 250}, {0, 0}}, 6);
    }
    var->enemies = create_object("player.png", "enemies", 9);
    set_shape_obj(&var->enemies, (sfIntRect){0, 48, 48, 48}, true);
    set_position_obj(var->enemies, (V2f){x_start, y_start});
    set_enemy_obj(&var->enemies, path, 5);
}

void create_menu(var_t *var)
{
    var->b_constructor = create_object("bconstructor.png", "constructMenu", 10);
    set_position_obj(var->b_constructor, (V2f){50, 965});
    set_shape_obj(&var->b_constructor, (sfIntRect){0, 0, 83, 85}, true);
}

void create(var_t *var)
{
    set_background("background.png", true);
    set_fps(true, 15, sfBlack);
    create_object("map.png", "map", 10);
    set_position_tag("map", (V2f){engine.win_settings.middle_screen.x/2 - get_size_tag("map").x/2, engine.win_settings.middle_screen.y/2 - get_size_tag("map").y/2});
    create_menu(var);
}
