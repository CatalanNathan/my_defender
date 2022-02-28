/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** get_text_visible.c
*/

#include "engine.h"
#include "var.h"
#include "my.h"

bool get_text_visible_tag(char *tag)
{
    node_text_t *start = engine.game.text;
    bool visible;

    while (engine.game.text != NULL) {
        if (equal(engine.game.text->settings.tag, tag) == true) {
            visible = engine.game.text->settings.display;
            engine.game.text = start;
            return visible;
        }
        engine.game.text = engine.game.text->previous;
    }
    engine.game.text = start;
    return false;
}
