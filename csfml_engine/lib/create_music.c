/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** create_music.c
*/

#include "my.h"
#include "engine.h"

music_t initiate_sound(char *src_sound, char *tag)
{
    static int id = 0;
    music_t sound;

    sound.playing = false;
    sound.loop = false;
    sound.tag = tag;
    sound.sound = sfMusic_createFromFile(my_strcat("csfml_en"
    "gine/sound/", src_sound));
    sound.id = id;
    sound.volume = 0;
    id += 1;
    return sound;
}

music_t create_music(char *src_sound, char *tag)
{
    node_music_t *new_node = malloc(sizeof(node_music_t));
    music_t sound = initiate_sound(src_sound, tag);

    if (engine.game.music != NULL) {
        new_node->previous = engine.game.music;
        engine.game.music->next = new_node;
        new_node->next = NULL;
        new_node->settings = sound;
        engine.game.music = new_node;
    } else {
        new_node->previous = NULL;
        new_node->next = NULL;
        new_node->settings = sound;
        engine.game.music = new_node;
    }
    return sound;
}
