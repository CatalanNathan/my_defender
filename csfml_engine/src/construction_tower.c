/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-guillaume.kucia
** File description:
** construction_tower.c
*/

#include "engine.h"
#include "var.h"
#include "my.h"

void construction_tower(int i, char c)
{
    if (i == 1)
        set_shape_tag(my_strcat_char(my_strdup("Tower_1."), c),
        (sfIntRect){get_shape_tag(my_strcat_char(my_strdup("Tower_1."), c))
        .left + 428, 0, 118, get_size_tag(my_strcat_char(
        my_strdup("Tower_1."), c)).y}, true);
    else
        set_visible_tag(my_strcat_char(my_strdup("Tower_1."), c), false);
    if (i == 2)
        set_shape_tag(my_strcat_char(my_strdup("Tower_2."), c), (sfIntRect)
        {get_shape_tag(my_strcat_char(my_strdup("Tower_2."), c)).left + 428
        , 0, 118, get_size_tag(my_strcat_char(my_strdup("Tower_2."), c)).y}
        , true);
    else
        set_visible_tag(my_strcat_char(my_strdup("Tower_2."), c), false);
}

void settings_action2(var_t *var, char *s)
{
    if (equal("120fps", s) || equal("opt120fps", s)) {
        sfRenderWindow_setFramerateLimit(engine.win_settings.window, 121);
        engine.win_settings.framerate = 120;
    }
    if (equal("144fps", s) || equal("opt144fps", s)) {
        sfRenderWindow_setFramerateLimit(engine.win_settings.window, 145);
        engine.win_settings.framerate = 144;
    }
    if (equal("Menu", s)) {
        destroy_all();
        var->global_menu = true;
        create(var);
    }
    if (get_exits_tag("fpspoint")) {
        set_position_tag("fpspoint", (V2f){555 +
        engine.win_settings.framerate, 512});
    }
}

void update_fpspoint2(void)
{
    if (get_position_tag("customfps").x < 775) {
        set_position_tag("customfps", (V2f){775, 379});
        sfRenderWindow_setFramerateLimit(engine.win_settings.window, 15);
    }
    if (get_position_tag("customfps").x > 1427) {
        set_position_tag("customfps", (V2f){1427, 379});
        sfRenderWindow_setFramerateLimit(engine.win_settings.window, 652);
        engine.win_settings.framerate = 652;
    }
}
