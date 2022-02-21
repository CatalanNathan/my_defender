/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** set_text_position.c
*/

#include "my.h"
#include "engine.h"

void set_text_position_tag(char *tag, V2f position)
{
    node_text_t *start = engine.game.text;

    while (engine.game.text != NULL) {
        if (equal(engine.game.text->settings.tag, tag) == true) {
            sfText_setPosition(engine.game.text->settings.text, position);
        }
        engine.game.text = engine.game.text->previous;
    }
    engine.game.text = start;
}

void set_text_position_text(text_t text, V2f position)
{
    node_text_t *start = engine.game.text;

    while (engine.game.text != NULL) {
        if (engine.game.text->settings.id == text.id) {
            sfText_setPosition(engine.game.text->settings.text, position);
        }
        engine.game.text = engine.game.text->previous;
    }
    engine.game.text = start;
}
