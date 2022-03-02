/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** shape_img.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void shape_img(void)
{
    node_t *start = engine.game.list;

    while (engine.game.list != NULL) {
        if (engine.game.list->settings.ishape == true)
            sfSprite_setTextureRect(engine.game.list->settings.sprite,
            engine.game.list->settings.shape);
        engine.game.list = engine.game.list->previous;
    }
    engine.game.list = start;
}
