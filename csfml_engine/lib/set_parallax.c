/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** set_parrallax.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void initiate_part(obj_t *object)
{
    object->enemy.it_is = false;
    object->enemy.path = NULL;
    object->enemy.pos_path = 0;
    object->enemy.anim_ennemie = 0.00;
    object->enemy.move_enemies = 0.00;
    object->enemy.n_path = 0;
    object->gravity = false;
    object->ishape = false;
    object->shape = (sfIntRect){0, 0, object->size.x, object->size.y};
    object->angle = 0;
    object->mouse_inside = false;
    object->link_id = 0;
    object->link_tag = "null";
}

obj_t resize_parallax(obj_t obj)
{
    while (obj.size.x > engine.win_settings.size.x) {
        sfSprite_setScale(obj.sprite, (V2f)
        {sfSprite_getScale(obj.sprite).x - 0.01, 1});
        obj.size.x = sfTexture_getSize(obj.texture).x *
        sfSprite_getScale(obj.sprite).x;
    }
    while (obj.size.y > engine.win_settings.size.y) {
        sfSprite_setScale(obj.sprite, (V2f){sfSprite_getScale(obj.sprite).x,
        sfSprite_getScale(obj.sprite).y - 0.01});
        obj.size.y = sfTexture_getSize(obj.texture).y *
        sfSprite_getScale(obj.sprite).y;
    }
    resize_parallax_hg(&obj);
    return obj;
}

obj_t initiate_paralax(char *src_img, char *tag, float speed)
{
    static int id = 0;
    obj_t object;

    object.display = true;
    object.exist = true;
    object.tag = tag;
    object.texture = sfTexture_createFromFile(my_strcat(""
    "csfml_engine/img_src/", src_img), NULL);
    object.sprite = sfSprite_create();
    sfSprite_setTexture(object.sprite, object.texture, sfTrue);
    object.size = sfTexture_getSize(object.texture);
    object.display_order = 0;
    object.id = id;
    object.speed = speed;
    id += 1;
    initiate_part(&object);
    object = resize_parallax(object);
    return object;
}

obj_t add_parallax(char *src_img, char *tag, float speed)
{
    node_t *new_node = malloc(sizeof(node_t));
    obj_t object = initiate_paralax(src_img, tag, speed);

    if (engine.win_settings.parallax != NULL) {
        new_node->previous = engine.win_settings.parallax;
        engine.win_settings.parallax->next = new_node;
        new_node->next = NULL;
        new_node->settings = object;
        engine.win_settings.parallax = new_node;
    } else {
        new_node->previous = NULL;
        new_node->next = NULL;
        new_node->settings = object;
        engine.win_settings.parallax = new_node;
    }
    return object;
}

void set_parallax(char **src_img, float speed, float multiplicator)
{
    obj_t object;
    float original_speed = speed;

    for (int i = 0; src_img[i] != NULL; i++) {
        original_speed = speed;
        object = add_parallax(src_img[i], "parallax", speed /= multiplicator);
        sfSprite_setPosition(object.sprite, (V2f){engine.win_settings.size.x,
        sfSprite_getPosition(object.sprite).y});
        speed = original_speed;
        add_parallax(src_img[i], "parallax", speed /= multiplicator);
    }
}
