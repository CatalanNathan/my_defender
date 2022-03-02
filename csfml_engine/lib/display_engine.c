/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** display_engine.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void draw_engine(int *order, node_t *start)
{
    if (engine.game.list->settings.display == true &&
    engine.game.list->settings.exist == true &&
    engine.game.list->settings.display_order == *order)
        sfRenderWindow_drawSprite(engine.win_settings.engine,
        engine.game.list->settings.sprite, NULL);
    if (engine.game.list->previous != NULL)
        engine.game.list = engine.game.list->previous;
    else {
        engine.game.list = start;
        *order += 1;
    }
}

void display_engine(void)
{
    node_t *start = engine.game.list;
    int order = 0;

    if (engine.win_settings.background.display == true &&
    engine.win_settings.background.exist == true)
        sfRenderWindow_drawSprite(engine.win_settings.engine,
        engine.win_settings.background.sprite, NULL);
    while (order != 10 && engine.game.list != NULL)
        draw_engine(&order, start);
}
