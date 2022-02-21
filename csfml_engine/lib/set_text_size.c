/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** set_text_size.c
*/

#include "my.h"
#include "engine.h"

void set_text_size_tag(char *tag, int size)
{
    node_text_t *start = engine.game.text;

    while (engine.game.text != NULL) {
        if (equal(engine.game.text->settings.tag, tag) == true) {
            sfText_setCharacterSize(engine.game.text->settings.text, size);
            engine.game.text->settings.font_size = size;
        }
        engine.game.text = engine.game.text->previous;
    }
    engine.game.text = start;
}

void set_text_size_text(text_t *text, int size)
{
    node_text_t *start = engine.game.text;

    text->font_size = size;
    while (engine.game.text != NULL) {
        if (engine.game.text->settings.id == text->id) {
            sfText_setCharacterSize(engine.game.text->settings.text, size);
            engine.game.text->settings.font_size = size;
        }
        engine.game.text = engine.game.text->previous;
    }
    engine.game.text = start;
}
