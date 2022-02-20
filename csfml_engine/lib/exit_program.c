/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** exit_program.c
*/

#include "my.h"
#include "engine.h"

void exit_program(engine_t *engine)
{
    static float anime_button = 0.00;

    if (mouse_inside_tag("engineExit", engine) == false) {
        if (get_shape_tag("engineExit", engine).width > 30 && elapsed_time_milliseconds(50, &anime_button, engine))
            set_shape_tag("engineExit", (sfIntRect){0, 0, get_shape_tag("engineExit", engine).width - 1, get_size_tag("engineExit", engine).y}, true, engine);
        else if (get_shape_tag("engineExit", engine).width == 30)
            set_shape_tag("engineExit", (sfIntRect){152, 0, 30, get_size_tag("engineExit", engine).y}, true, engine);
    } else {
        if (get_shape_tag("engineExit", engine).width < 76 && elapsed_time_milliseconds(50, &anime_button, engine))
            set_shape_tag("engineExit", (sfIntRect){76, 0, get_shape_tag("engineExit", engine).width + 1, get_size_tag("engineExit", engine).y}, true, engine);
        if (mouse_pressed(sfMouseLeft, engine))
            game_end(0, engine);
    }

}
