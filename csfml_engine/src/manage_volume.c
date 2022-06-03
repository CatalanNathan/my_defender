/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-guillaume.kucia
** File description:
** manage_volume.c
*/

#include "engine.h"
#include "var.h"
#include "my.h"

void update_fps_point2(bool selected, var_t *var)
{
    if (selected == true && mouse_press(sfMouseLeft)) {
        add_info_more(var, my_strcat("FPS : ",
        my_itoa(engine.win_settings.framerate, 0)));
        set_position_tag("fpspoint",
        (V2f){sfMouse_getPositionRenderWindow(engine.win_settings.window).x
        - 20, 512});
        sfRenderWindow_setFramerateLimit(engine.win_settings.window,
        GPT("fpspoint").x - 555);
        engine.win_settings.framerate = GPT("fpspoint").x - 555;
        if (engine.win_settings.framerate < 1)
            add_info_more(var, my_strcat_char("FPS : ", '0'));
    }
}

void update_fps_point(var_t *var)
{
    static bool selected = false;

    if (mouse_inside_tag("fpspoint")) {
        change_cursor(var, "cursor");
        if (mouse_press(sfMouseLeft))
            selected = true;
    } else if (selected == true && !mouse_press(sfMouseLeft))
        selected = false;
    update_fps_point2(selected, var);
    if (get_position_tag("fpspoint").x < 555)
        set_position_tag("fpspoint", (V2f){555, 512});
    if (get_position_tag("fpspoint").x > GPT("fpsbar").x +
        get_size_tag("fpsbar").x - 10) {
        set_position_tag("fpspoint", (V2f){GPT("fpsbar").x +
        get_size_tag("fpsbar").x - 10, 512});
        }
}

void update_volume_point2(bool selected, var_t *var)
{
    if (selected == true && mouse_press(sfMouseLeft)) {
        add_info_more(var, my_strcat("Volume : ", my_itoa(var->volume, 0)));
        set_position_tag("VolumePoint",
        (V2f){sfMouse_getPositionRenderWindow(engine.win_settings.window).x -
        20, 683});
        var->volume = (GPT("VolumePoint").x - 555) / 10;
        if (var->volume < 0)
            var->volume = 0;
        if (var->volume < 1)
            add_info_more(var, my_strcat_char("Volume : ", '0'));
        if (var->volume > 120)
            add_info_more(var, my_strcat("Volume : ", "120"));
        set_music_volume_tag(my_strcat_char("music_", var->m),
        (int)(var->volume));
    }
}

void update_volume_point(var_t *var)
{
    static bool selected = false;

    if (mouse_inside_tag("VolumePoint")) {
        change_cursor(var, "cursor");
        if (mouse_press(sfMouseLeft))
            selected = true;
    } else if (selected == true && !mouse_press(sfMouseLeft))
        selected = false;
    update_volume_point2(selected, var);
    if (get_position_tag("VolumePoint").x < 555)
        set_position_tag("VolumePoint", (V2f){555, 683});
    if (get_position_tag("VolumePoint").x > GPT("VolumeBar").x +
        get_size_tag("VolumeBar").x - 10) {
        set_position_tag("VolumePoint", (V2f){GPT("VolumeBar").x +
        get_size_tag("VolumeBar").x - 10, 683});
    }
}
