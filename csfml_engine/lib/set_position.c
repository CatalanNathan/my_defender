/*
** EPITECH PROJECT, 2021
** CSFML engine
** File description:
** set_position.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void set_position_tag(char *tag, sfVector2f offset, engine_t *engine)
{
    node_t *start = engine->game.list;

    while (engine->game.list != NULL) {
        if (equal(engine->game.list->settings.tag, tag) == true)
            sfSprite_setPosition(engine->game.list->settings.sprite, offset);
        engine->game.list = engine->game.list->previous;
    }
    engine->game.list = start;
}

void set_position_obj(obj_t obj, sfVector2f offset, engine_t *engine)
{
    sfSprite_setPosition(obj.sprite, offset);
}
