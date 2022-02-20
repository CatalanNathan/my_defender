/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** get_position.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"

sfVector2f get_position_tag(char *tag, engine_t *engine)
{
    node_t *start = engine->game.list;
    sfVector2f pos;

    while (engine->game.list != NULL) {
        if (equal(engine->game.list->settings.tag, tag) == true) {
            pos = sfSprite_getPosition(engine->game.list->settings.sprite);
            engine->game.list = start;
            return pos;
        }
        engine->game.list = engine->game.list->previous;
    }
    engine->game.list = start;
    return (sfVector2f){0, 0};
}

sfVector2f get_position_obj(obj_t obj, engine_t *engine)
{
    return sfSprite_getPosition(obj.sprite);
}
