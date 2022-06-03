/*
** EPITECH PROJECT, 2021
** CSFML engine
** File description:
** add_background.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void resize_x(sfTexture *texture, sfSprite *sprite, sfVector2u size)
{
    while (size.x < engine.win_settings.size.x) {
        sfSprite_setScale(sprite, (V2f){sfSprite_getScale(
        sprite).x + 0.01, 1});
        size.x = sfTexture_getSize(texture).x * sfSprite_getScale(sprite).x;
    }
    while (size.y < engine.win_settings.size.y) {
        sfSprite_setScale(sprite, (V2f){sfSprite_getScale(sprite).x,
        sfSprite_getScale(sprite).y + 0.01});
        size.y = sfTexture_getSize(texture).y * sfSprite_getScale(sprite).y;
    }
}

void resize_img(void)
{
    sfSprite *sprite = engine.win_settings.background.sprite;
    sfTexture *texture = engine.win_settings.background.texture;
    sfVector2u size = engine.win_settings.background.size;

    while (size.x > engine.win_settings.size.x) {
        sfSprite_setScale(sprite, (V2f){sfSprite_getScale(sprite).x
        - 0.01, 1});
        size.x = sfTexture_getSize(texture).x * sfSprite_getScale(sprite).x;
    }
    while (size.y > engine.win_settings.size.y) {
        sfSprite_setScale(sprite, (V2f){sfSprite_getScale(sprite).x,
        sfSprite_getScale(sprite).y - 0.01});
        size.y = sfTexture_getSize(texture).y * sfSprite_getScale(sprite).y;
    }
    resize_x(texture, sprite, size);
}

void set_background(char *src_img, bool auto_resize)
{
    engine.win_settings.background.texture = sfTexture_createFromFile(
    my_strcat("csfml_engine/img_src/", src_img), NULL);
    engine.win_settings.background.sprite = sfSprite_create();
    sfSprite_setTexture(engine.win_settings.background.sprite,
    engine.win_settings.background.texture, sfTrue);
    engine.win_settings.background.size = sfTexture_getSize(
    engine.win_settings.background.texture);
    engine.win_settings.background.display = true;
    engine.win_settings.background.exist = true;
    engine.win_settings.background.tag = "background";
    engine.win_settings.background.id = -1;
    if (auto_resize == true)
        resize_img();
}

void resize_x_img(sfTexture *texture, sfSprite *sprite,
sfVector2u size, V2f new_size)
{
    while (size.x < new_size.x) {
        sfSprite_setScale(sprite, (V2f){sfSprite_getScale(
        sprite).x + 0.01, 1});
        size.x = sfTexture_getSize(texture).x * sfSprite_getScale(sprite).x;
    }
    while (size.y < new_size.y) {
        sfSprite_setScale(sprite, (V2f){sfSprite_getScale(sprite).x,
        sfSprite_getScale(sprite).y + 0.01});
        size.y = sfTexture_getSize(texture).y * sfSprite_getScale(sprite).y;
    }
}

void resize_my_img(obj_t *obj, V2f new_size)
{
    sfSprite *sprite = obj->sprite;
    sfTexture *texture = obj->texture;
    sfVector2u size = get_size_obj(obj);

    while (size.x > new_size.x) {
        sfSprite_setScale(sprite, (V2f){sfSprite_getScale(sprite).x
        - 0.01, 1});
        size.x = sfTexture_getSize(texture).x * sfSprite_getScale(sprite).x;
    }
    while (size.y > new_size.y) {
        sfSprite_setScale(sprite, (V2f){sfSprite_getScale(sprite).x,
        sfSprite_getScale(sprite).y - 0.01});
        size.y = sfTexture_getSize(texture).y * sfSprite_getScale(sprite).y;
    }
    resize_x_img(texture, sprite, size, new_size);
}
