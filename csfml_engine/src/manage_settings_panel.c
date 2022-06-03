/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-guillaume.kucia
** File description:
** manage_settings_panel.c
*/

#include "engine.h"
#include "my.h"
#include "var.h"

void create_settings_ptwo(var_t *var)
{
    create_object("FpsBar.png", "fpsbar", 7);
    set_position_tag("fpsbar", (V2f){468, 500});
    create_object("SettingsInfo.png", "settingsinfo", 7);
    set_position_tag("settingsinfo", (V2f){468, 120});
    create_object("opt30fps.png", "opt30fps", 7);
    set_this_shape("opt30fps", 570, 560);
    create_object("opt60fps.png", "opt60fps", 7);
    set_this_shape("opt60fps", 730, 560);
    create_object("opt120fps.png", "opt120fps", 7);
    set_this_shape("opt120fps", 890, 560);
    create_object("opt144fps.png", "opt144fps", 7);
    set_this_shape("opt144fps", 1050, 560);
    create_object("VolumePoint.png", "fpspoint", 7);
    set_position_tag("fpspoint", (V2f){555 +
    engine.win_settings.framerate, 512});
}

void create_settings_panel(var_t *var)
{
    create_object("SettingsPanel.png", "SPanel", 9);
    set_position_tag("SPanel", (V2f){400, 60});
    create_object("SettingsAnim.png", "SAnim", 8);
    set_position_tag("SAnim", (V2f){410, 70});
    create_object("Music1.png", "Music1", 8);
    set_this_shape("Music1", 470, 780);
    create_object("Music2.png", "Music2", 8);
    set_this_shape("Music2", 810, 780);
    create_object("Music3.png", "Music3", 8);
    set_this_shape("Music3", 1150, 780);
    create_object("Music4.png", "Music4", 8);
    set_this_shape("Music4", 1490, 780);
    create_object("VolumeBar.png", "VolumeBar", 7);
    set_position_tag("VolumeBar", (V2f){468, 670});
    create_object("VolumePoint.png", "VolumePoint", 7);
    set_position_tag("VolumePoint", (V2f){555 +
    (var->volume * 10), 683});
    create_settings_ptwo(var);
}

void manage_sanim(var_t *var, float time)
{
    if (!get_exits_tag("SAnim"))
        return;
    if (get_shape_tag("SAnim").left <
        (int)get_texture_size_tag("SAnim").x / 2) {
        set_shape_tag("SAnim", (sfIntRect){get_shape_tag("SAnim").left
        + (0.0002 * time), 0, get_size_tag("SPanel").x - 10,
        get_size_tag("SPanel").y - 10}, true);
    }
    else {
        set_shape_tag("SAnim", (sfIntRect){0, 0,
        get_size_tag("SPanel").x - 10, get_size_tag("SPanel").y - 10}, true);
    }
}

void destroy_settings_panels(var_t *var)
{
    destroy_object_tag("SPanel");
    destroy_object_tag("SAnim");
    destroy_object_tag("Music1");
    destroy_object_tag("Music2");
    destroy_object_tag("Music3");
    destroy_object_tag("Music4");
    destroy_object_tag("VolumeBar");
    destroy_object_tag("VolumePoint");
    destroy_object_tag("fpsbar");
    destroy_object_tag("settingsinfo");
    destroy_object_tag("opt30fps");
    destroy_object_tag("opt60fps");
    destroy_object_tag("opt120fps");
    destroy_object_tag("opt144fps");
    destroy_object_tag("fpspoint");
}

void manage_settings_panel(var_t *var)
{
    if (!get_exits_tag("SPanel")) {
        create_settings_panel(var);
        if (get_exits_tag("HBorder"))
            destroy_h_panel(var);
    } else {
        destroy_settings_panels(var);
    }
}
