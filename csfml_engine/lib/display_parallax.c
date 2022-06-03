/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** display_parallax.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"
#define sprite engine.win_settings.parallax->settings.sprite
#define speed engine.win_settings.parallax->settings.speed

void draw_parallax(float *parallax, float *save)
{
    if (engine.win_settings.parallax->settings.display == true &&
    engine.win_settings.parallax->settings.exist == true &&
    elapsed_time_milliseconds(100, parallax, save)) {
        sfSprite_setPosition(sprite,
        (sfVector2f){sfSprite_getPosition(sprite).x - speed,
        sfSprite_getPosition(sprite).y});
        if (sfSprite_getPosition(sprite).x <=
        engine.win_settings.size.x * (-1))
            sfSprite_setPosition(sprite, (sfVector2f){
            engine.win_settings.size.x, sfSprite_getPosition(sprite).y});
        sfRenderWindow_drawSprite( engine.win_settings.window, sprite, NULL);
    }
    engine.win_settings.parallax = engine.win_settings.parallax->previous;
}

void display_parallax(void)
{
    node_t *start = engine.win_settings.parallax;
    static float parallax = 0.00;
    static float save = 0.00;

    while (engine.win_settings.parallax != NULL)
        draw_parallax(&parallax, &save);
    engine.win_settings.parallax = start;
}
