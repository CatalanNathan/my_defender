/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** change_cursor.c
*/

#include "engine.h"
#include "my.h"
#include "var.h"

void change_cursor(var_t * var, char *tag_new_cursor)
{
    set_shape_tag(tag_new_cursor, (sfIntRect){200, 0, 173, 177}, true);
    var->on_button = true;
}

void set_cursor(var_t *var, char *new_c)
{
    if (get_visible_tag(var->actual_c))
        set_visible_tag(var->actual_c, false);
    var->actual_c = my_strdup(new_c);
    set_visible_tag(new_c, true);
}

void update_cursor(var_t *var)
{
    static int mouse = 0;

    set_position_tag(var->actual_c, (V2f){
    sfMouse_getPositionRenderWindow(engine.win_settings.window).x,
    sfMouse_getPositionRenderWindow(engine.win_settings.window).y});

    if (equal(var->actual_c, "cursor") == false &&
        mouse_pressed(sfMouseRight, &mouse)) {
        set_visible_tag(var->actual_c, false);
        var->actual_c = "cursor";
        var->destroy_mod = false;
        set_visible_tag(var->actual_c, true);
    }
    mouse_pressed(sfMouseRight, &mouse);
}
