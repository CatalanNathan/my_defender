/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** set_music_pause.c
*/

#include "my.h"
#include "engine.h"

void set_music_pause_tag(char *tag)
{
    node_music_t *start = engine.game.music;

    while (engine.game.music != NULL) {
        if (equal(engine.game.music->settings.tag, tag) == true) {
            sfMusic_pause(engine.game.music->settings.sound);
            engine.game.music->settings.playing = false;
        }
        engine.game.music = engine.game.music->previous;
    }
    engine.game.music = start;
}

void set_music_pause_sfmusic(music_t *sound)
{
    node_music_t *start = engine.game.music;

    sound->playing = false;
    while (engine.game.music != NULL) {
        if (engine.game.music->settings.id == sound->id) {
            sfMusic_pause(engine.game.music->settings.sound);
            engine.game.music->settings.playing = false;
        }
        engine.game.music = engine.game.music->previous;
    }
    engine.game.music = start;
}
