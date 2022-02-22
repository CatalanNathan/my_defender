/*
** EPITECH PROJECT, 2021
** CSFML engine
** File description:
** create.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void create_menu(var_t *var)
{
    var->b_constructor = create_object("bconstructor.png", "constructMenu", 10);
    set_position_obj(var->b_constructor, (V2f){50, 965});
    set_shape_obj(&var->b_constructor, (sfIntRect){0, 0, 83, 85}, true);
}

void create(var_t *var)
{
    srand(time(NULL));
    var->castle_life = 1000;
    var->nb_enemies = 20;
    set_background("background.png", true);
    set_fps(true, 15, sfBlack);
    create_object("map.png", "map", 10);
    set_position_tag("map", (V2f){engine.win_settings.middle_screen.x/2 - get_size_tag("map").x/2, engine.win_settings.middle_screen.y/2 - get_size_tag("map").y/2});
    create_menu(var);
    create_text(my_strcat("HP : ", my_itoa(var->castle_life, 0)), "CastleHP");
    set_text_position_tag("CastleHP", (V2f){935, 220});
    create_tower("Tower_lv1.png", (V2f){870, 335}, var);
    create_tower("Tower_lv1.png", (V2f){750, 10}, var);
    create_tower("Tower_lv1.png", (V2f){1000, 140}, var);
    create_tower("Tower_lv1.png", (V2f){660, 290}, var);
    create_tower("Tower_lv1.png", (V2f){470, 110}, var);

}
