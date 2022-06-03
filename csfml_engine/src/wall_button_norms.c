/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-mydefender-guillaume.kucia
** File description:
** wall_button_norms
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void set_shape_wall(char *tag, int *i)
{
    mouse_pressed(sfMouseLeft, i);
    set_shape_tag(tag, (sfIntRect){0, 0,
    get_size_tag(tag).x, get_size_tag(tag).y}, true);
}
