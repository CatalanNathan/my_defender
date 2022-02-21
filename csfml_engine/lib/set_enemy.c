/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** set_enemy.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void initiate_vector2f(obj_t *obj, sfVector2f *path)
{
    obj->path = malloc(sizeof(sfVector2f[6]));
    for (int i = 0; i != 6; i++) {
        obj->path[i].x = path[i].x;
        obj->path[i].y = path[i].y;
    }
}

void set_enemy_tag(char *tag, sfVector2f *path, engine_t *engine)
{
    node_t *start = engine->game.list;

    while (engine->game.list != NULL) {
        if (equal(engine->game.list->settings.tag, tag) == true) {
            engine->game.list->settings.enemy = true;
            engine->game.list->settings.anim_ennemie = 0.00;
            engine->game.list->settings.move_enemies = 0.00;
            engine->game.list->settings.pos_path = 0;
            engine->game.list->settings.path = path;
        }
        engine->game.list = engine->game.list->previous;
    }
    engine->game.list = start;
}

void set_enemy_obj(obj_t *obj, sfVector2f *path, engine_t *engine)
{
    node_t *start = engine->game.list;

    obj->enemy = true;
    obj->anim_ennemie = 0.00;
    obj->move_enemies = 0.00;
    initiate_vector2f(obj, path);
    obj->pos_path = 0;
    while (engine->game.list != NULL) {
        if (obj->id == engine->game.list->settings.id) {
            engine->game.list->settings.enemy = true;
            engine->game.list->settings.anim_ennemie = 0.00;
            engine->game.list->settings.move_enemies = 0.00;
            engine->game.list->settings.pos_path = 0;
            initiate_vector2f(&engine->game.list->settings, path);
        }
        engine->game.list = engine->game.list->previous;
    }
    engine->game.list = start;
}
