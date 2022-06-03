/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-guillaume.kucia
** File description:
** get_visible.c
*/

#include "engine.h"
#include "my.h"
#include "var.h"

bool get_visible_tag(char *tag)
{
    node_t *start = engine.game.list;
    bool visible;

    while (engine.game.list != NULL) {
        if (equal(engine.game.list->settings.tag, tag) == true) {
            visible = engine.game.list->settings.display;
            engine.game.list = start;
            return visible;
        }
        engine.game.list = engine.game.list->previous;
    }
    engine.game.list = start;
    return false;
}
