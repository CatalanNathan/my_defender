/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-guillaume.kucia
** File description:
** create_button_menu.c
*/

#include "engine.h"
#include "my.h"
#include "var.h"

void music_action(char *s, var_t *var)
{
    if (equal(s, "Music1")) {
        set_music_stop_tags((char *[3]){"music_2", "music_3", "music_4"}, 3);
        set_music_play_tag("music_1", true, var->volume);
        var->m = '1';
    }
    if (equal(s, "Music2")) {
        set_music_stop_tags((char *[3]){"music_1", "music_3", "music_4"}, 3);
        set_music_play_tag("music_2", true, var->volume);
        var->m = '2';
    }
    if (equal(s, "Music3")) {
        set_music_stop_tags((char *[3]){"music_2", "music_1", "music_4"}, 3);
        set_music_play_tag("music_3", true, var->volume);
        var->m = '3';
    }
    if (equal(s, "Music4")) {
        set_music_stop_tags((char *[3]){"music_2", "music_3", "music_1"}, 3);
        set_music_play_tag("music_4", true, var->volume);
        var->m = '4';
    }
}

void menu_action(char *s, var_t *var)
{
    if (equal(s, "ExitMenu"))
        game_end(0);
    if (equal(s, "PlayMenu")) {
        destroy_all();
        var->global_menu = false;
        create(var);
    }
    if (equal(s, "SettingsM"))
        manage_settings_panel(var);
    if (equal(s, "HowToPlay"))
        manage_h_panel(var);
    music_action(s, var);
}

void update_menu_event(var_t *var, char *s)
{
    static int i = 0;

    if (mouse_inside_tag(s)) {
        set_shape_tag(s, (sfIntRect){get_size_tag(s).x, 0,
        get_texture_size_tag(s).x / 2, get_size_tag(s).y}, true);
        change_cursor(var, "cursor");
        if (mouse_pressed(sfMouseLeft, &i)) {
            set_music_play_tag("click", false, 100);
            menu_action(s, var);
        }
    } else {
        set_shape_tag(s, (sfIntRect){0, 0, get_texture_size_tag(s).x
        / 2, get_size_tag(s).y}, true);
    }
}

void menu_button_event(var_t *var)
{
    update_menu_event(var, "ExitMenu");
    update_menu_event(var, "PlayMenu");
    update_menu_event(var, "SettingsM");
    update_menu_event(var, "HowToPlay");
    update_settings_btn(var, "opt30fps");
    update_settings_btn(var, "opt60fps");
    update_settings_btn(var, "opt120fps");
    update_settings_btn(var, "opt144fps");
    update_menu_event(var, "Music1");
    update_menu_event(var, "Music2");
    update_menu_event(var, "Music3");
    update_menu_event(var, "Music4");
    update_volume_point(var);
    update_fps_point(var);
}

void create_button_menu(var_t *var)
{
    create_object("ExitMenu.png", "ExitMenu", 8);
    set_this_shape("ExitMenu", 60, 928);
    create_object("PlayMenu.png", "PlayMenu", 8);
    set_this_shape("PlayMenu", 60, 60);
    create_object("SettingsM.png", "SettingsM", 8);
    set_this_shape("SettingsM", 60, 60 + get_size_tag("SettingsM").y);
    create_object("HowToPlay.png", "HowToPlay", 7);
    set_this_shape("HowToPlay", 60, GPT("SettingsM").y +
    get_size_tag("SettingsM").y);
}
