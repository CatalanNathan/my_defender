/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** set_enemy.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void initiate_vector2f(enemy_t *enemy, V2f *path, int n)
{
    enemy->path = malloc(sizeof(V2f[n]));
    for (int i = 0; i < n; i++) {
        enemy->path[i].x = path[i].x;
        enemy->path[i].y = path[i].y;
    }
}

void set_enemy_tag(char *tag, V2f *path, int n)
{
    node_t *start = engine.game.list;

    while (engine.game.list != NULL) {
        if (equal(engine.game.list->settings.tag, tag) == true) {
            engine.game.list->settings.enemy.it_is = true;
            engine.game.list->settings.enemy.anim_ennemie = 0.00;
            engine.game.list->settings.enemy.move_enemies = 0.00;
            engine.game.list->settings.enemy.pos_path = 0;
            engine.game.list->settings.enemy.n_path = n;
            initiate_vector2f(&engine.game.list->settings.enemy, path, n);
        }
        engine.game.list = engine.game.list->previous;
    }
    engine.game.list = start;
}

void set_enemy_obj(obj_t *obj, V2f *path, int n)
{
    node_t *start = engine.game.list;

    obj->enemy.it_is = true;
    obj->enemy.anim_ennemie = 0.00;
    obj->enemy.move_enemies = 0.00;
    initiate_vector2f(&obj->enemy, path, n);
    obj->enemy.n_path = n;
    obj->enemy.pos_path = 0;
    while (engine.game.list != NULL) {
        if (obj->id == engine.game.list->settings.id) {
            engine.game.list->settings.enemy.it_is = true;
            engine.game.list->settings.enemy.anim_ennemie = 0.00;
            engine.game.list->settings.enemy.move_enemies = 0.00;
            engine.game.list->settings.enemy.pos_path = 0;
            engine.game.list->settings.enemy.n_path = n;
            initiate_vector2f(&engine.game.list->settings.enemy, path, n);
        }
        engine.game.list = engine.game.list->previous;
    }
    engine.game.list = start;
}
