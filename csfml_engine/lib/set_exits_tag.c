/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** set_exits_tag.c
*/

#include "engine.h"
#include "my.h"
#include "var.h"

void set_exits_tag(char *tag, bool exits)
{
    node_t *start = engine.game.list;

    while (engine.game.list != NULL) {
        if (equal(engine.game.list->settings.tag, tag))
            engine.game.list->settings.exist = exits;
        engine.game.list = engine.game.list->previous;
    }
    engine.game.list = start;
}
