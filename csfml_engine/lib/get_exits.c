/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** get_exits.c
*/

#include "engine.h"
#include "my.h"
#include "var.h"

bool get_exits_tag(char *tag)
{
    node_t *start = engine.game.list;
    bool exist;

    while (engine.game.list != NULL) {
        if (equal(engine.game.list->settings.tag, tag) == true) {
            exist = engine.game.list->settings.exist;
            engine.game.list = start;
            return exist;
        }
        engine.game.list = engine.game.list->previous;
    }
    engine.game.list = start;
    return false;
}

bool get_exits_obj(obj_t obj)
{
    node_t *start = engine.game.list;
    bool exist;

    while (engine.game.list != NULL) {
        if (engine.game.list->settings.id == obj.id) {
            exist = engine.game.list->settings.exist;
            engine.game.list = start;
            return exist;
        }
        engine.game.list = engine.game.list->previous;
    }
    engine.game.list = start;
    return false;
}
