/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** get_scale_tag.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"

sfVector2f get_scale_tag(char *tag, engine_t *engine)
{
    node_t *start = engine->game.list;
    sfVector2f scale;

    while (engine->game.list != NULL) {
        if (equal(engine->game.list->settings.tag, tag) == true) {
            scale = sfSprite_getScale(engine->game.list->settings.sprite);
            engine->game.list = start;
            return scale;
        }
        engine->game.list = engine->game.list->previous;
    }
    engine->game.list = start;
    return (sfVector2f){0, 0};
}
