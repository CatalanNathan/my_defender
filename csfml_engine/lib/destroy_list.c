/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** destroy_list.c
*/

#include "my.h"
#include "engine.h"

void destroy_list(void)
{
    while (engine.game.list != NULL) {
        sfSprite_destroy(engine.game.list->settings.sprite);
        sfTexture_destroy(engine.game.list->settings.texture);
        if (engine.game.list->previous != NULL) {
            engine.game.list->previous->next = engine.game.list;
            engine.game.list = engine.game.list->previous;
            engine.game.list->next = NULL;
        } else {
            engine.game.list = NULL;
            return;
        }
    }
}

void destroy_music(void)
{
    while (engine.game.music != NULL) {
        sfMusic_destroy(engine.game.music->settings.sound);
        if (engine.game.music->previous != NULL) {
            engine.game.music->previous->next = engine.game.music;
            engine.game.music = engine.game.music->previous;
            engine.game.music->next = NULL;
        } else {
            engine.game.music = NULL;
            return;
        }
    }
}

void destroy_text(void)
{
    while (engine.game.text != NULL) {
        sfText_destroy(engine.game.text->settings.text);
        if (engine.game.text->previous != NULL) {
            engine.game.text->previous->next = engine.game.text;
            engine.game.text = engine.game.text->previous;
            engine.game.text->next = NULL;
        } else {
            engine.game.text = NULL;
            return;
        }
    }
}
