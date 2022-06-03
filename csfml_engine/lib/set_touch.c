/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-guillaume.kucia
** File description:
** set_touch.c
*/

#include "my.h"
#include "var.h"
#include "engine.h"

void set_touch_object(obj_t *obj)
{
    node_t *start = engine.game.list;

    obj->enemy.is_touch = true;
    while (engine.game.list != NULL) {
        if (engine.game.list->settings.id == obj->id)
            engine.game.list->settings.enemy.is_touch = true;
        engine.game.list = engine.game.list->previous;
    }
    engine.game.list = start;
}
