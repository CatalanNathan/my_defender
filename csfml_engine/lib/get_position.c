/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** get_position.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"

V2f get_position_tag(char *tag)
{
    node_t *start = engine.game.list;
    V2f pos;

    while (engine.game.list != NULL) {
        if (equal(engine.game.list->settings.tag, tag) == true) {
            pos = sfSprite_getPosition(engine.game.list->settings.sprite);
            engine.game.list = start;
            return pos;
        }
        engine.game.list = engine.game.list->previous;
    }
    engine.game.list = start;
    return (V2f){0, 0};
}

V2f get_position_obj(obj_t obj)
{
    return sfSprite_getPosition(obj.sprite);
}
