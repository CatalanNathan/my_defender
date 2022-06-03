/*
** EPITECH PROJECT, 2021
** CSFML engine
** File description:
** create_object.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void initialise_enemy(obj_t *object)
{
    object->enemy.it_is = false;
    object->enemy.path = NULL;
    object->enemy.pos_path = 0;
    object->enemy.move_enemies = 0.00;
    object->enemy.anim_ennemie = 0.00;
    object->enemy.n_path = 0;
    object->enemy.pv = 0;
    object->enemy.is_touch = false;
}

void init_bool(obj_t *object)
{
    object->mouse_inside = false;
    object->gravity = false;
    object->ishape = false;
    object->display = true;
    object->exist = true;
}

obj_t initiate_object(char *src_img, char *tag, int display_order)
{
    static int id = 1;
    obj_t object;

    init_bool(&object);
    object.tag = my_strdup(tag);
    object.texture = sfTexture_createFromFile(my_strcat("csfml_eng"
    "ine/img_src/", src_img), NULL);
    object.sprite = sfSprite_create();
    sfSprite_setTexture(object.sprite, object.texture, sfTrue);
    object.size = sfTexture_getSize(object.texture);
    object.display_order = display_order;
    object.id = id;
    object.shape = (sfIntRect){0, 0, object.size.x, object.size.y};
    object.speed = 0.00;
    object.angle = 0.00;
    object.link_id = 0;
    object.link_tag = "null";
    initialise_enemy(&object);
    id += 1;
    return object;
}

obj_t create_object(char *src_img, char *tag, int display_order)
{
    node_t *new_node = malloc(sizeof(node_t));
    obj_t object = initiate_object(src_img, tag, display_order);

    if (engine.game.list != NULL) {
        new_node->previous = engine.game.list;
        engine.game.list->next = new_node;
        new_node->next = NULL;
        new_node->settings = object;
        engine.game.list = new_node;
    } else {
        new_node->previous = NULL;
        new_node->next = NULL;
        new_node->settings = object;
        engine.game.list = new_node;
    }
    return object;
}
