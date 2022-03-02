/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** set_music_volume.c
*/

#include "my.h"
#include "engine.h"

void set_music_volume_tag(char *tag, float volume)
{
    node_music_t *start = engine.game.music;

    while (engine.game.music != NULL) {
        if (equal(engine.game.music->settings.tag, tag)) {
            sfMusic_setVolume(engine.game.music->settings.sound, volume);
            engine.game.music->settings.volume = volume;
        }
        engine.game.music = engine.game.music->previous;
    }
    engine.game.music = start;
}

void set_music_volume_sfmusic(music_t *sound, float volume)
{
    node_music_t *start = engine.game.music;

    sound->volume = volume;
    while (engine.game.music != NULL) {
        if (engine.game.music->settings.id == sound->id) {
            sfMusic_setVolume(engine.game.music->settings.sound, volume);
            engine.game.music->settings.volume = volume;
        }
        engine.game.music = engine.game.music->previous;
    }
    engine.game.music = start;
}
