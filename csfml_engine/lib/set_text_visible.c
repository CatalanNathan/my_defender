/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** set_text_visible.c
*/

#include "my.h"
#include "engine.h"

void set_text_visible_tag(char *tag, bool visible)
{
    node_text_t *start = engine.game.text;

    while (engine.game.text != NULL) {
        if (equal(engine.game.text->settings.tag, tag) == true) {
            engine.game.text->settings.display = visible;
        }
        engine.game.text = engine.game.text->previous;
    }
    engine.game.text = start;
}

void set_text_visible_text(text_t *text, bool visible)
{
    node_text_t *start = engine.game.text;

    text->display = visible;
    while (engine.game.text != NULL) {
        if (engine.game.text->settings.id == text->id) {
            engine.game.text->settings.display = visible;
        }
        engine.game.text = engine.game.text->previous;
    }
    engine.game.text = start;
}
