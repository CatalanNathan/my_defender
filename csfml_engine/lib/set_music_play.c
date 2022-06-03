/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** set_music_play.c
*/

#include "my.h"
#include "engine.h"

void old_coding_style_epitech(bool loop)
{
    if (loop == true)
        sfMusic_setLoop(engine.game.music->settings.sound, sfTrue);
}

void set_music_play_tag(char *tag, bool loop, float volume)
{
    node_music_t *start = engine.game.music;

    while (engine.game.music != NULL) {
        if (equal(engine.game.music->settings.tag, tag) == true) {
            sfMusic_stop(engine.game.music->settings.sound);
            sfMusic_play(engine.game.music->settings.sound);
            engine.game.music->settings.loop = loop;
            engine.game.music->settings.volume = volume;
            engine.game.music->settings.playing = true;
            sfMusic_setVolume(engine.game.music->settings.sound, volume);
            old_coding_style_epitech(loop);
        }
        engine.game.music = engine.game.music->previous;
    }
    engine.game.music = start;
}

void set_music_play_sfmusic(music_t *sound, bool loop, float volume)
{
    node_music_t *start = engine.game.music;

    while (engine.game.music != NULL) {
        if (engine.game.music->settings.id == sound->id) {
            sfMusic_play(engine.game.music->settings.sound);
            engine.game.music->settings.loop = loop;
            engine.game.music->settings.volume = volume;
            engine.game.music->settings.playing = true;
            sfMusic_setVolume(engine.game.music->settings.sound, volume);
            old_coding_style_epitech(loop);
            *sound = engine.game.music->settings;
        }
        engine.game.music = engine.game.music->previous;
    }
    engine.game.music = start;
}
