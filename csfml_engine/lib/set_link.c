/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** set_link.c
*/

#include "engine.h"
#include "var.h"
#include "my.h"

void set_link_tag(char *tag1, char *tag2)
{
    node_t *start = engine.game.list;

    for (;engine.game.list != NULL; engine.game.list =
    engine.game.list->previous)
        if (equal(engine.game.list->settings.tag, tag1))
            engine.game.list->settings.link_tag = tag2;
    engine.game.list = start;
    for (;engine.game.list != NULL; engine.game.list =
    engine.game.list->previous)
        if (equal(engine.game.list->settings.tag, tag2))
            engine.game.list->settings.link_tag = tag1;
    engine.game.list = start;
}
