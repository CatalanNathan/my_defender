/*
** EPITECH PROJECT, 2021
** CSFML engine
** File description:
** key_pressed.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"

bool key_pressed_engine(sfKeyCode key, engine_t *engine)
{
    if (sfRenderWindow_pollEvent(engine->win_settings.engine, &engine->event)) {
        if (engine->event.type == sfEvtKeyPressed && engine->event.key.code == key)
            return true;
    }
    return false;
}

bool key_pressed(sfKeyCode key, engine_t *engine)
{
    static int i = 0;

    if (sfRenderWindow_isOpen(engine->win_settings.engine))
        return key_pressed_engine(key, engine);
    if (sfKeyboard_isKeyPressed(key) && i != 1) {
        i = 1;
        return true;
    } else if (i == 1 && engine->event.type == sfEvtKeyReleased && engine->event.key.code == key)
        i = 0;
    return false;
}

bool key_press(sfKeyCode key, engine_t *engine)
{
    if (sfRenderWindow_isOpen(engine->win_settings.engine))
        return key_pressed_engine(key, engine);
    if (sfKeyboard_isKeyPressed(key))
        return true;
    return false;
}
