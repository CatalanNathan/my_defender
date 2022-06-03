/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-guillaume.kucia
** File description:
** get_rotation.c
*/

#include "engine.h"
#include "var.h"
#include "my.h"

float get_rotation_tag(char *tag)
{
    node_t *start = engine.game.list;
    float rotation;

    while (engine.game.list != NULL) {
        if (equal(engine.game.list->settings.tag, tag) == true) {
            rotation = sfSprite_getRotation(engine.game.list->settings.sprite);
            engine.game.list = start;
            return rotation;
        }
        engine.game.list = engine.game.list->previous;
    }
    engine.game.list = start;
    return 0.00;
}
