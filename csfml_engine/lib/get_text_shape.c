/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** get_text_shape.c
*/

#include "engine.h"
#include "my.h"
#include "var.h"

sfFloatRect get_text_shape_tag(char *tag)
{
    node_text_t *start = engine.game.text;

    while (engine.game.text != NULL) {
        if (equal(engine.game.text->settings.tag, tag) == true)
            return sfText_getLocalBounds(engine.game.text->settings.text);
        engine.game.text = engine.game.text->previous;
    }
    engine.game.text = start;
    return (sfFloatRect){0,0,0,0};
}
