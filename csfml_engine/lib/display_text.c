/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** display_text.c
*/

#include "my.h"
#include "engine.h"

void display_text(void)
{
    node_text_t *start = engine.game.text;

    while (engine.game.text != NULL) {
        if (engine.game.text->settings.display == true &&
        engine.game.text->settings.exist == true)
            sfRenderWindow_drawText(engine.win_settings.window,
            engine.game.text->settings.text, NULL);
        engine.game.text = engine.game.text->previous;
    }
    engine.game.text = start;
}
