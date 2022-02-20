/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** mouse_pressed.c
*/

#include "my.h"
#include "engine.h"

bool mouse_pressed(sfMouseButton button, engine_t *engine)
{
    static int i = 0;

    if (sfMouse_isButtonPressed(button) && i != 1) {
        i = 1;
        return true;
    } else if (i == 1 && engine->event.type == sfEvtMouseButtonReleased && engine->event.mouseButton.button == button)
        i = 0;
    return false;
}

bool mouse_press(sfMouseButton button, engine_t *engine)
{
    if (sfMouse_isButtonPressed(button))
        return true;
    return false;
}
