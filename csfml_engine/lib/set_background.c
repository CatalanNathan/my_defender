/*
** EPITECH PROJECT, 2021
** CSFML engine
** File description:
** add_background.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void resize_img()
{
    while (engine.win_settings.background.size.x > engine.win_settings.size.x) {
        sfSprite_setScale(engine.win_settings.background.sprite, (V2f){sfSprite_getScale(engine.win_settings.background.sprite).x - 0.01, 1});
        engine.win_settings.background.size.x = sfTexture_getSize(engine.win_settings.background.texture).x * sfSprite_getScale(engine.win_settings.background.sprite).x;
    }
    while (engine.win_settings.background.size.y > engine.win_settings.size.y) {
        sfSprite_setScale(engine.win_settings.background.sprite, (V2f){sfSprite_getScale(engine.win_settings.background.sprite).x, sfSprite_getScale(engine.win_settings.background.sprite).y - 0.01});
        engine.win_settings.background.size.y = sfTexture_getSize(engine.win_settings.background.texture).y * sfSprite_getScale(engine.win_settings.background.sprite).y;
    }
    while (engine.win_settings.background.size.x < engine.win_settings.size.x) {
        sfSprite_setScale(engine.win_settings.background.sprite, (V2f){sfSprite_getScale(engine.win_settings.background.sprite).x + 0.01, 1});
        engine.win_settings.background.size.x = sfTexture_getSize(engine.win_settings.background.texture).x * sfSprite_getScale(engine.win_settings.background.sprite).x;
    }
    while (engine.win_settings.background.size.y < engine.win_settings.size.y) {
        sfSprite_setScale(engine.win_settings.background.sprite, (V2f){sfSprite_getScale(engine.win_settings.background.sprite).x, sfSprite_getScale(engine.win_settings.background.sprite).y + 0.01});
        engine.win_settings.background.size.y = sfTexture_getSize(engine.win_settings.background.texture).y * sfSprite_getScale(engine.win_settings.background.sprite).y;
    }
}

void set_background(char *src_img, bool auto_resize)
{
    engine.win_settings.background.texture = sfTexture_createFromFile(my_strcat("csfml_engine/img_src/", src_img), NULL);
    engine.win_settings.background.sprite = sfSprite_create();
    sfSprite_setTexture(engine.win_settings.background.sprite, engine.win_settings.background.texture, sfTrue);
    engine.win_settings.background.size = sfTexture_getSize(engine.win_settings.background.texture);
    engine.win_settings.background.display = true;
    engine.win_settings.background.exist = true;
    engine.win_settings.background.tag = "background";
    engine.win_settings.background.id = -1;
    if (auto_resize == true)
        resize_img(engine);
}
