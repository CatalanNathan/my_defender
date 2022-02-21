/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** set_parrallax.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"


void initialise_enemy_par(obj_t *enemy)
{
    enemy->enemy = false;
    enemy->path = NULL;
    enemy->pos_path = 0;
    enemy->anim_ennemie = 0.00;
    enemy->move_enemies = 0.00;
}

obj_t resize_parallax(obj_t obj, engine_t *engine)
{
    while (obj.size.x > engine->win_settings.size.x) {
        sfSprite_setScale(obj.sprite, (sfVector2f){sfSprite_getScale(obj.sprite).x - 0.01, 1});
        obj.size.x = sfTexture_getSize(obj.texture).x * sfSprite_getScale(obj.sprite).x;
    }
    while (obj.size.y > engine->win_settings.size.y) {
        sfSprite_setScale(obj.sprite, (sfVector2f){sfSprite_getScale(obj.sprite).x, sfSprite_getScale(obj.sprite).y - 0.01});
        obj.size.y = sfTexture_getSize(obj.texture).y * sfSprite_getScale(obj.sprite).y;
    }
    while (obj.size.x < engine->win_settings.size.x) {
        sfSprite_setScale(obj.sprite, (sfVector2f){sfSprite_getScale(obj.sprite).x + 0.01, 1});
        obj.size.x = sfTexture_getSize(obj.texture).x * sfSprite_getScale(obj.sprite).x;
    }
    while (obj.size.y < engine->win_settings.size.y) {
        sfSprite_setScale(obj.sprite, (sfVector2f){sfSprite_getScale(obj.sprite).x, sfSprite_getScale(obj.sprite).y + 0.01});
        obj.size.y = sfTexture_getSize(obj.texture).y * sfSprite_getScale(obj.sprite).y;
    }
    return obj;
}

obj_t initiate_paralax(char *src_img, char *tag, float speed, engine_t *engine)
{
    static int id = 0;
    obj_t object;

    object.display = true;
    object.exist = true;
    object.tag = tag;
    object.texture = sfTexture_createFromFile(my_strcat("csfml_engine/img_src/", src_img), NULL);
    object.sprite = sfSprite_create();
    sfSprite_setTexture(object.sprite, object.texture, sfTrue);
    object.size = sfTexture_getSize(object.texture);
    object.display_order = 0;
    object.id = id;
    object.gravity = false;
    object.ishape = false;
    object.shape = (sfIntRect){0, 0, object.size.x, object.size.y};
    object.speed = speed;
    object.angle = 0;
    object.mouse_inside = false;
    id += 1;
    initialise_enemy_par(&object);
    object = resize_parallax(object, engine);
    return object;
}

obj_t add_parallax(char *src_img, char *tag, float speed, engine_t *engine)
{
    node_t *new_node = malloc(sizeof(node_t));
    obj_t object = initiate_paralax(src_img, tag, speed, engine);

    if (engine->win_settings.parallax != NULL) {
        new_node->previous = engine->win_settings.parallax;
        engine->win_settings.parallax->next = new_node;
        new_node->next = NULL;
        new_node->settings = object;
        engine->win_settings.parallax = new_node;
    } else {
        new_node->previous = NULL;
        new_node->next = NULL;
        new_node->settings = object;
        engine->win_settings.parallax = new_node;
    }
    return object;
}

void set_parallax(char **src_img, float speed, float multiplicator, engine_t *engine)
{
    obj_t object;
    float original_speed = speed;

    for (int i = 0; src_img[i] != NULL; i++) {
        original_speed = speed;
        object = add_parallax(src_img[i], "parallax", speed /= multiplicator, engine);
        sfSprite_setPosition(object.sprite, (sfVector2f){engine->win_settings.size.x, sfSprite_getPosition(object.sprite).y});
        speed = original_speed;
        add_parallax(src_img[i], "parallax", speed /= multiplicator, engine);
    }
}
