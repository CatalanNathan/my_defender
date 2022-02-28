/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** window_set_position.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void window_set_position(sfVector2i offset)
{
    if (sfRenderWindow_isOpen(engine.win_settings.engine)) {
        sfRenderWindow_setPosition(engine.win_settings.engine, offset);
        return;
    }
    sfRenderWindow_setPosition(engine.win_settings.window, offset);
}
