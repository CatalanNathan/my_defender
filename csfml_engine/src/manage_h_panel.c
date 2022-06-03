/*
** EPITECH PROJECT, 2021
** my_defender_epitech
** File description:
** manage_h_panel.c
*/

#include "engine.h"
#include "var.h"
#include "my.h"

void h_event(var_t *var)
{
    static char *s = "HowToPlayPdf";
    static float time = 0.00;
    static float save = 0.00;

    get_elapsed_time(&time, &save);
    if (!mouse_inside_tag(s))
        return;
    if (mouse_scroll() < 0 && get_shape_tag(s).top +
        (int)get_shape_tag(s).height < (int)get_texture_size_tag(s).y) {
        set_shape_tag(s, (sfIntRect){0, get_shape_tag(s).top +
        (0.001 * time), get_size_tag(s).x, get_size_tag("HBorder").y}, true);
        }
    else if (mouse_scroll() == 1 && get_shape_tag(s).top > 0) {
        set_shape_tag(s, (sfIntRect){0, get_shape_tag(s).top -
        (0.001 * time), get_size_tag(s).x, get_size_tag("HBorder").y}, true);
    }
}

void create_h_panel(var_t *var)
{
    static char *s = "HowToPlayPdf";

    create_object("HBorder.png", "HBorder", 9);
    set_position_tag("HBorder", (V2f){400, 60});
    create_object("HowToPlayPdf.png", "HowToPlayPdf", 9);
    set_position_tag("HowToPlayPdf", (V2f){374, 60});
    set_shape_tag(s, (sfIntRect){0, 0, get_size_tag(s).x,
    get_size_tag("HBorder").y}, true);
}

void destroy_h_panel(var_t *var)
{
    destroy_object_tag("HBorder");
    destroy_object_tag("HowToPlayPdf");
    destroy_object_tag("ScrollBug");
}

void manage_h_panel(var_t *var)
{
    if (!get_exits_tag("HBorder")) {
        create_h_panel(var);
        if (get_exits_tag("SPanel"))
            destroy_settings_panels(var);
    } else {
        destroy_h_panel(var);
    }
}
