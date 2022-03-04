/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** get_collisions.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void shape_selected_col(int decrement)
{
    if (engine.game.list->settings.ishape == false) {
        engine.game.list->settings.size.x = sfTexture_getSize(engine.game.
        list->settings.texture).x * sfSprite_getScale(engine.game.list->
        settings.sprite).x - decrement;
        engine.game.list->settings.size.y = sfTexture_getSize(engine.game.
        list->settings.texture).y * sfSprite_getScale(engine.game.list->
        settings.sprite).y;
    } else {
        engine.game.list->settings.size.x = engine.game.list->settings.
        shape.width - decrement;
        engine.game.list->settings.size.y = engine.game.list->settings.
        shape.height;
    }
}

sfVector2u get_size_col(int decrement)
{
    shape_selected_col(decrement);
    return engine.game.list->settings.size;
}

bool check_collision(sfVector2f pos_1, sfVector2u size_1, int decrement)
{
    sfVector2f pos_2 = sfSprite_getPosition(engine.game.list->settings.sprite);
    sfVector2u size_2 = get_size_col(decrement);

    if (((pos_1.x >= pos_2.x && pos_1.x <= pos_2.x + size_2.x) || (pos_1.x
    + size_1.x >= pos_2.x && pos_1.x + size_1.x <= pos_2.x + size_2.x)) &&
    ((pos_1.y >= pos_2.y && pos_1.y <= pos_2.y + size_2.y) || (pos_1.y +
    size_1.y >= pos_2.y && pos_1.y + size_1.y <= pos_2.y + size_2.y)))
        return true;
    return false;
}

bool get_collision_tag(char *obj_tag, char *obstacles_tag)
{
    node_t *start = engine.game.list;
    sfVector2f pos_1 = get_position_tag(obj_tag);
    sfVector2u size_1 = get_size_tag(obj_tag);

    while (engine.game.list != NULL) {
        if (get_collision_tag_norms(obstacles_tag, pos_1, size_1) == 0) {
            engine.game.list = start;
            return true;
        }
        engine.game.list = engine.game.list->previous;
    }
    engine.game.list = start;
    return false;
}

bool get_collision_obj(obj_t *obj, char *obstacles_tag, int decrement)
{
    node_t *start = engine.game.list;
    sfVector2f pos_1 = get_position_obj(*obj);
    sfVector2u size_1 = get_size_obj(obj);

    while (engine.game.list != NULL) {
        if (get_collision_obj_norms(obstacles_tag, pos_1,
            size_1, decrement) == 0) {
            engine.game.list = start;
            return true;
        }
        engine.game.list = engine.game.list->previous;
    }
    engine.game.list = start;
    return false;
}
