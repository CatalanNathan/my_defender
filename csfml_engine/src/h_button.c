/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-guillaume.kucia
** File description:
** h_button.c
*/

#include "engine.h"
#include "var.h"
#include "my.h"

void h_action(char *s, var_t *var)
{

}

void update_h_event(var_t *var, char *s)
{
    static int i = 0;

    if (!get_exits_tag("HBorder"))
        return;
    if (mouse_inside_tag(s)) {
        set_shape_tag(s, (sfIntRect){get_size_tag(s).x, 0,
        get_texture_size_tag(s).x / 2, get_size_tag(s).y}, true);
        change_cursor(var, "cursor");
        if (mouse_pressed(sfMouseLeft, &i)) {
            h_action(s, var);
        }
    } else {
        set_shape_tag(s, (sfIntRect){0, 0,
        get_texture_size_tag(s).x / 2, get_size_tag(s).y}, true);
    }
}
