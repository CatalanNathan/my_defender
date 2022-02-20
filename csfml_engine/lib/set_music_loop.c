/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** set_music_loop.c
*/

#include "my.h"
#include "engine.h"

void set_loop(bool loop, engine_t *engine)
{
    if (loop == true)
        sfMusic_setLoop(engine->game.music->settings.sound, sfTrue);
    else
        sfMusic_setLoop(engine->game.music->settings.sound, sfFalse);
}

void set_music_loop_tag(char *tag, bool loop, engine_t *engine)
{
    node_music_t *start = engine->game.music;

    while (engine->game.music != NULL) {
        if (equal(engine->game.music->settings.tag, tag) == true) {
            set_loop(loop, engine);
            engine->game.music->settings.loop = loop;
        }
        engine->game.music = engine->game.music->previous;
    }
    engine->game.music = start;
}

void set_music_loop_sfmusic(music_t *sound, bool loop, engine_t *engine)
{
    node_music_t *start = engine->game.music;

    sound->loop = loop;
    while (engine->game.music != NULL) {
        if (engine->game.music->settings.id == sound->id) {
            set_loop(loop, engine);
            engine->game.music->settings.loop = loop;
        }
        engine->game.music = engine->game.music->previous;
    }
    engine->game.music = start;
}
