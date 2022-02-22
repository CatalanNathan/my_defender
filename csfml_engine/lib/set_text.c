/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** set_text.c
*/

#include "my.h"
#include "engine.h"

void set_text_tag(char *tag, char *text)
{
    node_text_t *start = engine.game.text;

    while (engine.game.text != NULL) {
        if (equal(engine.game.text->settings.tag, tag) == true)
            sfText_setString(engine.game.text->settings.text, text);
        engine.game.text = engine.game.text->previous;
    }
    engine.game.text = start;
}

void set_text_text(text_t *text, char *str)
{
    node_text_t *start = engine.game.text;

    while (engine.game.text != NULL) {
        if (engine.game.text->settings.id == text->id) {
            sfText_setString(engine.game.text->settings.text, str);
            text->text = engine.game.text->settings.text;
        }
        engine.game.text = engine.game.text->previous;
    }
    engine.game.text = start;
}
