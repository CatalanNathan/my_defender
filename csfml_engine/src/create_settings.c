/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-guillaume.kucia
** File description:
** create_settings.c
*/

#include "engine.h"
#include "var.h"
#include "my.h"

void set_this_shape(char *s, int x, int y)
{
    set_shape_tag(s, (sfIntRect){0, 0, get_texture_size_tag(
    s).x / 2, get_size_tag(s).y}, true);
    set_position_tag(s, (V2f){x, y});
}

void norming(void)
{
    set_this_shape("30fps", 780, 272);
    create_object("60 fps.png", "60fps", 4);
    set_this_shape("60fps", 952, 272);
    create_object("120 fps.png", "120fps", 4);
    set_this_shape("120fps", 1121, 272);
    create_object("144 fps.png", "144fps", 4);
    set_this_shape("144fps", 1290, 272);
    create_object("fps point.png", "customfps", 4);
    set_position_tag("customfps", (V2f){760 +
    engine.win_settings.framerate, 379});
    create_text(my_itoa(engine.win_settings.framerate, 0), "Settingsfps");
}

void create_settings_m(var_t *var)
{
    create_object("settingsM.png", "settingsM", 5);
    set_text_visible_tag("CastleHP", false);
    create_object("Exit Game.png", "ExitGame", 4);
    set_this_shape("ExitGame", 497, 491);
    create_object("continue.png", "continue", 4);
    set_this_shape("continue", 497, 343);
    create_object("restart.png", "restart", 4);
    set_this_shape("restart", 497, 270);
    create_object("Menu.png", "Menu", 4);
    set_this_shape("Menu", 497, 417);
    create_object("30 fps.png", "30fps", 4);
    norming();
}

void btn_settings(var_t *var)
{
    static char *s = "btn_settings";

    if (mouse_inside_tag(s)) {
        set_shape_tag(s, (sfIntRect){get_texture_size_tag(s).x / 2 - 2,
        0, get_texture_size_tag(s).x / 2, get_size_tag(s).y}, true);
        change_cursor(var, "cursor");
        if (mouse_press(sfMouseLeft)) {
            set_music_play_tag("click", false, 100);
            var->pause = true;
            var->settings_m = true;
            create_settings_m(var);
        }
    } else
        set_shape_tag(s, (sfIntRect){0, 0, get_texture_size_tag(s).x / 2,
        get_size_tag(s).y}, true);
}

void create_settings(var_t *var)
{
    create_object("settings.png", "btn_settings", 9);
    set_position_tag("btn_settings", (V2f){30, 30});
    set_shape_tag("btn_settings", (sfIntRect){0, 0,
    get_size_tag("btn_settings").x/2, get_size_tag("btn_settings").y}, true);
}
