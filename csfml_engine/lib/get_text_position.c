/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** get_text_position.c
*/

#include "my.h"
#include "engine.h"

sfVector2f get_text_position_tag(char *tag)
{
    node_text_t *start = engine.game.text;
    sfVector2f pos;

    while (engine.game.text != NULL) {
        if (equal(engine.game.text->settings.tag, tag) == true) {
            pos = sfText_getPosition(engine.game.text->settings.text);
            engine.game.text = start;
            return pos;
        }
        engine.game.text = engine.game.text->previous;
    }
    engine.game.text = start;
    return (sfVector2f){ 0, 0};
}

sfVector2f get_text_position_text(text_t text)
{
    node_text_t *start = engine.game.text;
    sfVector2f pos;

    while (engine.game.text != NULL) {
        if (engine.game.text->settings.id == text.id) {
            pos = sfText_getPosition(engine.game.text->settings.text);
            engine.game.text = start;
            return pos;
        }
        engine.game.text = engine.game.text->previous;
    }
    engine.game.text = start;
    return (sfVector2f){ 0, 0};
}
