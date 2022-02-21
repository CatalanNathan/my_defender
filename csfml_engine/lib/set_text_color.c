/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** set_text_color.c
*/

#include "my.h"
#include "engine.h"

void set_text_color_tag(char *tag, sfColor color)
{
    node_text_t *start = engine.game.text;

    while (engine.game.text != NULL) {
        if (equal(engine.game.text->settings.tag, tag) == true) {
            engine.game.text->settings.color = color;
            sfText_setColor(engine.game.text->settings.text, color);
        }
        engine.game.text = engine.game.text->previous;
    }
    engine.game.text = start;
}

void set_text_color_text(text_t *text, sfColor color)
{
    node_text_t *start = engine.game.text;

    text->color = color;
    while (engine.game.text != NULL) {
        if (engine.game.text->settings.id == text->id) {
            engine.game.text->settings.color = color;
            sfText_setColor(engine.game.text->settings.text, color);
        }
        engine.game.text = engine.game.text->previous;
    }
    engine.game.text = start;
}
