/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** view_fps.c
*/

#include "my.h"
#include "engine.h"

void view_fps()
{
    static int fps = 0;
    int seconds = 0;

    if (engine.win_settings.fps.view_fps == false)
        return;
    engine.win_settings.fps.time = sfClock_getElapsedTime(engine.win_settings.fps.elapsed);
    fps++;
    if (engine.win_settings.fps.time.microseconds / 1000 > 999) {
        engine.win_settings.fps.fps = fps;
        fps = 0;
        sfClock_restart(engine.win_settings.fps.elapsed);
    }
    sfText_setString(engine.win_settings.fps.text, my_strcat("fps : ", my_itoa(engine.win_settings.fps.fps, 0)));
    sfRenderWindow_drawText(engine.win_settings.window, engine.win_settings.fps.text, NULL);
}

void set_fps(bool visible, int font_size, sfColor color)
{
    if (visible == true) {
        engine.win_settings.fps.view_fps = true;
        engine.win_settings.fps.text = sfText_create();
        sfText_setColor(engine.win_settings.fps.text, color);
        sfText_setCharacterSize(engine.win_settings.fps.text, font_size);
        sfText_setFont(engine.win_settings.fps.text, sfFont_createFromFile("csfml_engine/font/Elmono-regular.ttf"));
    } else if (visible == false)
        engine.win_settings.fps.view_fps = false;

}
