/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** get_sprite_color.c
*/

#include "engine.h"
#include "var.h"
#include "my.h"

sfColor get_sprite_color_tag(char *tag)
{
    node_t *start = engine.game.list;
    sfColor color;

    while (engine.game.list != NULL) {
        if (equal(engine.game.list->settings.tag, tag)) {
            color = sfSprite_getColor(engine.game.list->settings.sprite);
            engine.game.list = start;
            return color;
        }
        engine.game.list = engine.game.list->previous;
    }
    engine.game.list = start;
    return sfTransparent;
}
