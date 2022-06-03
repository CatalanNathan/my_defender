/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-guillaume.kucia
** File description:
** set_pv.c
*/

#include "engine.h"
#include "var.h"
#include "my.h"

void set_pv_tag(char *tag, int pv, int max_pv)
{
    node_t *start = engine.game.list;

    while (engine.game.list != NULL) {
        if (equal(engine.game.list->settings.tag, tag)) {
            engine.game.list->settings.enemy.pv = pv;
            engine.game.list->settings.enemy.max_pv = max_pv;
        }
        engine.game.list = engine.game.list->previous;
    }
    engine.game.list = start;
}

void set_pv_obj(obj_t *obj, int pv, int max_pv)
{
    node_t *start = engine.game.list;

    obj->enemy.pv = pv;
    while (engine.game.list != NULL) {
        if (engine.game.list->settings.id == obj->id) {
            engine.game.list->settings.enemy.pv = pv;
            engine.game.list->settings.enemy.max_pv = max_pv;
        }
        engine.game.list = engine.game.list->previous;
    }
    engine.game.list = start;
}

int get_pv_tag(char *tag)
{
    node_t *start = engine.game.list;
    int pv = 0;

    while (engine.game.list != NULL) {
        if (equal(engine.game.list->settings.tag, tag)) {
            pv = engine.game.list->settings.enemy.pv;
            engine.game.list = start;
            return pv;
        }
        engine.game.list = engine.game.list->previous;
    }
    engine.game.list = start;
    return pv;
}

int get_pv_obj(obj_t *obj)
{
    node_t *start = engine.game.list;
    int pv = 0;

    while (engine.game.list != NULL) {
        if (engine.game.list->settings.id == obj->id) {
            pv = engine.game.list->settings.enemy.pv;
            engine.game.list = start;
            obj->enemy.pv = pv;
            return pv;
        }
        engine.game.list = engine.game.list->previous;
    }
    engine.game.list = start;
    return pv;
}

int get_pv_max_obj(obj_t *obj)
{
    node_t *start = engine.game.list;
    int pv = 0;

    while (engine.game.list != NULL) {
        if (engine.game.list->settings.id == obj->id) {
            pv = engine.game.list->settings.enemy.max_pv;
            engine.game.list = start;
            obj->enemy.max_pv = pv;
            return pv;
        }
        engine.game.list = engine.game.list->previous;
    }
    engine.game.list = start;
    return pv;
}
