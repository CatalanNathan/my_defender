/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** display_obj.c
*/

#include "my.h"
#include "engine.h"

void display_obj(engine_t *engine)
{
    node_t *start = engine->game.list;
    int order = 10;

    while (order >= 0 && engine->game.list != NULL) {
        if (engine->game.list->settings.display == true && engine->game.list->settings.exist == true && engine->game.list->settings.display_order == order)
            sfRenderWindow_drawSprite(engine->win_settings.window, engine->game.list->settings.sprite, NULL);
        if (engine->game.list->previous != NULL)
            engine->game.list = engine->game.list->previous;
        else {
            engine->game.list = start;
            order -= 1;;
        }
    }
    engine->game.list = start;
}
