/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-guillaume.kucia
** File description:
** destroy_settings_m.c
*/

#include "engine.h"
#include "my.h"
#include "var.h"

void settings_action(char *s, var_t *var)
{
    if (equal("ExitGame", s))
        game_end(0);
    if (equal("continue", s)) {
        var->pause = false;
        var->settings_m = false;
        destroy_settings_m(var);
    }
    if (equal("restart", s)) {
        destroy_all();
        create(var);
    }
    if (equal("30fps", s) || equal("opt30fps", s)) {
        sfRenderWindow_setFramerateLimit(engine.win_settings.window, 30);
        engine.win_settings.framerate = 30;
    }
    if (equal("60fps", s) || equal("opt60fps", s)) {
        sfRenderWindow_setFramerateLimit(engine.win_settings.window, 60);
        engine.win_settings.framerate = 60;
    }
    settings_action2(var, s);
}

void update_settings_btn(var_t *var, char *s)
{
    if (mouse_inside_tag(s)) {
        set_shape_tag(s, (sfIntRect){get_size_tag(s).x, 0,
        get_texture_size_tag(s).x / 2, get_size_tag(s).y}, true);
        change_cursor(var, "cursor");
        if (mouse_press(sfMouseLeft)) {
            set_music_play_tag("click", false, 100);
            settings_action(s, var);
        }
    } else {
        set_shape_tag(s, (sfIntRect){0, 0,
        get_texture_size_tag(s).x / 2, get_size_tag(s).y}, true);
    }
}

void update_fpspoint(var_t *var)
{
    static bool selected = false;

    if (mouse_inside_tag("customfps")) {
        change_cursor(var, "cursor");
        selected = true;
    }
    if (mouse_press(sfMouseLeft) && selected) {
        set_position_tag("customfps",
        (V2f){sfMouse_getPositionRenderWindow(engine.win_settings.window).x,
        get_position_tag("customfps").y});
        sfRenderWindow_setFramerateLimit(engine.win_settings.window,
        get_position_tag("customfps").x - 775);
        engine.win_settings.framerate = get_position_tag("customfps").x - 760;
    } else {
        selected = false;
        set_position_tag("customfps", (V2f){775 +
        engine.win_settings.framerate, 379});
    }
    update_fpspoint2();
}

void settings_update(var_t *var)
{
    if (!var->settings_m)
        return;
    update_settings_btn(var, "ExitGame");
    update_settings_btn(var, "continue");
    update_settings_btn(var, "restart");
    update_settings_btn(var, "30fps");
    update_settings_btn(var, "60fps");
    update_settings_btn(var, "120fps");
    update_settings_btn(var, "144fps");
    if (!var->settings_m)
        return;
    update_fpspoint(var);
    update_settings_btn(var, "Menu");
    set_text_tag("Settingsfps", my_itoa(engine.win_settings.framerate, 0));
    set_text_position_tag("Settingsfps",
    (V2f){get_position_tag("customfps").x, 360});
}

void destroy_settings_m(var_t *var)
{
    destroy_object_tag("settingsM");
    set_text_visible_tag("CastleHP", true);
    destroy_object_tag("ExitGame");
    destroy_object_tag("continue");
    destroy_object_tag("restart");
    destroy_object_tag("Menu");
    destroy_object_tag("30fps");
    destroy_object_tag("60fps");
    destroy_object_tag("120fps");
    destroy_object_tag("144fps");
    destroy_object_tag("customfps");
    destroy_text_tag("Settingsfps");
}
