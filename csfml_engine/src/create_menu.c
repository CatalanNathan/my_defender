/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-guillaume.kucia
** File description:
** create_menu.c
*/

#include "engine.h"
#include "var.h"
#include "my.h"

void background_event(var_t *var)
{
    static char *s = "GlobalMenu";
    static float time = 0.00;
    static float save = 0.00;
    static int i = 0;

    get_elapsed_time(&time, &save);
    if (GPT(s).y < 0 && i == 0)
        set_position_tag(s, (V2f){GPT(s).x, GPT(s).y + (0.00007 * time)});
    else if (i == 0) {
        i = 1;
        set_position_tag(s, (V2f){-960, 0});
    }
    if (GPT(s).y > -960 && i == 1)
        set_position_tag(s, (V2f){GPT(s).x, GPT(s).y - (0.00007 * time)});
    else if (i == 1) {
        i = 0;
        set_position_tag(s, (V2f){-960, -960});
    }
    manage_sanim(var, time);
}

void global_menu_event(var_t *var)
{
    set_position_tag("cursor", (V2f){sfMouse_getPositionRenderWindow(
    engine.win_settings.window).x - 3, sfMouse_getPositionRenderWindow(
    engine.win_settings.window).y - 3});
    background_event(var);
    menu_button_event(var);
    h_event(var);
    if (var->on_button == false)
        set_shape_tag("cursor", (sfIntRect){0, 0, 173, 177}, true);
}

void create_music_menu(var_t *var)
{
    create_music("music1.ogg", "music_1");
    create_music("music2.ogg", "music_2");
    create_music("music3.ogg", "music_3");
    create_music("music4.ogg", "music_4");
    create_music("click.ogg", "click");
    set_music_play_tag(my_strcat_char("music_", var->m), 0, var->volume);
}

void create_menu(var_t *var)
{
    set_music_loop_tag("music_default", true);
    create_music_menu(var);
    sfRenderWindow_setMouseCursorVisible(engine.win_settings.window, sfFalse);
    create_object("GlobalMenu.png", "GlobalMenu", 10);
    set_position_tag("GlobalMenu", (V2f){-960, -540});
    create_object("cursor.png", "cursor", 0);
    set_scale_tag("cursor", (V2f){0.2, 0.2});
    set_shape_tag("cursor", (sfIntRect){0, 0, 173, 177}, true);
    create_object("ToolMenu.png", "ToolMenu", 9);
    set_position_tag("ToolMenu", (V2f){60, 60});
    create_text("information", "info+");
    set_text_visible_tag("info+", false);
    create_info(var);
    create_button_menu(var);
}

// https://grabify.link/track/JC0T2R
