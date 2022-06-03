/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-guillaume.kucia
** File description:
** create_music_game.c
*/

#include "var.h"
#include "my.h"
#include "engine.h"

void create_music_game(var_t *var)
{
    create_music("music1.ogg", "music_1");
    create_music("music2.ogg", "music_2");
    create_music("music3.ogg", "music_3");
    create_music("music4.ogg", "music_4");
    create_music("click.ogg", "click");
    create_music("arrow.ogg", "arrow");
    create_music("rock.ogg", "rock");
    create_music("fire.ogg", "fire");
    set_music_play_tag(my_strcat_char("music_",
    var->m), true, var->volume);
}
