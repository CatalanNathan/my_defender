/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** exit_program.c
*/

#include "my.h"
#include "engine.h"

void exit_program(float time)
{
    static int i = 0;

    if (mouse_inside_tag("engineExit") == false) {
        if (get_shape_tag("engineExit").width > 30)
            set_shape_tag("engineExit", (sfIntRect){0, 0, get_shape_tag(
            "engineExit").width - (0.001 * time), get_size_tag("engineEx"
            "it").y}, true);
        else if (get_shape_tag("engineExit").width == 30)
            set_shape_tag("engineExit", (sfIntRect){152, 0, 30, get_size_tag(
            "engineExit").y}, true);
    } else {
        if (get_shape_tag("engineExit").width < 76)
            set_shape_tag("engineExit", (sfIntRect){76, 0, get_shape_tag(
            "engineExit").width + (0.002 * time), get_size_tag("engineExi"
            "t").y}, true);
        if (mouse_pressed(sfMouseLeft, &i))
            game_end(0);
    }
}
