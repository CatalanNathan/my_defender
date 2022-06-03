/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-guillaume.kucia
** File description:
** destroy_text.c
*/

#include "engine.h"
#include "var.h"
#include "my.h"

void destroy_this2_text(void)
{
    if (engine.game.text->next != NULL && engine.game.text->previous == NULL)
        engine.game.text->next->previous = NULL;
    sfText_destroy(engine.game.text->settings.text);
    engine.game.text = NULL;
}

void destroy_this_text(node_text_t *start)
{
    if (engine.game.text->next != NULL && engine.game.text->previous != NULL) {
        engine.game.text->next->previous = engine.game.text->previous;
        engine.game.text->previous->next = engine.game.text->next;
        sfText_destroy(engine.game.text->settings.text);
        engine.game.text = start;
        return;
    } else if (engine.game.text->next == NULL &&
        engine.game.text->previous != NULL) {
        engine.game.text->previous->next = NULL;
        sfText_destroy(engine.game.text->settings.text);
        engine.game.text = engine.game.text->previous;
        return;
    }
    destroy_this2_text();
}

void destroy_text_tag(char *tag)
{
    node_text_t *start = engine.game.text;

    while (engine.game.text != NULL) {
        if (equal(engine.game.text->settings.tag, tag)) {
            destroy_this_text(start);
            return;
        }
        engine.game.text = engine.game.text->previous;
    }
    engine.game.text = start;
}
