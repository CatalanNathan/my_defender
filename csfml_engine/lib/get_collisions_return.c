/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** get_collisions_return.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void shape_selected_col_id(engine_t *engine)
{
    if (engine->game.list->settings.ishape == false) {
        engine->game.list->settings.size.x = sfTexture_getSize(engine->game.list->settings.texture).x * sfSprite_getScale(engine->game.list->settings.sprite).x;
        engine->game.list->settings.size.y = sfTexture_getSize(engine->game.list->settings.texture).y * sfSprite_getScale(engine->game.list->settings.sprite).y;
    } else {
        engine->game.list->settings.size.x = engine->game.list->settings.shape.width;
        engine->game.list->settings.size.y = engine->game.list->settings.shape.height;
    }
}

sfVector2u get_size_col_id(engine_t *engine)
{
    shape_selected_col_id(engine);
    return engine->game.list->settings.size;
}

bool check_collision_id(sfVector2f pos_1, sfVector2u size_1, engine_t *engine)
{
    sfVector2f pos_2 = sfSprite_getPosition(engine->game.list->settings.sprite);
    sfVector2u size_2 = get_size_col_id(engine);

    if (((pos_1.x >= pos_2.x && pos_1.x <= pos_2.x + size_2.x) || (pos_1.x + size_1.x >= pos_2.x && pos_1.x + size_1.x <= pos_2.x + size_2.x)) &&
    ((pos_1.y >= pos_2.y && pos_1.y <= pos_2.y + size_2.y) || (pos_1.y + size_1.y >= pos_2.y && pos_1.y + size_1.y <= pos_2.y + size_2.y))) {
        return true;
    }
    return false;
}

int get_collision_tag_id(char *obj_tag, char *obstacles_tag, engine_t *engine)
{
    node_t *start = engine->game.list;
    sfVector2f pos_1 = get_position_tag(obj_tag, engine);
    sfVector2u size_1 = get_size_tag(obj_tag, engine);

    while (engine->game.list != NULL) {
        if (equal(engine->game.list->settings.tag, obstacles_tag) == true) {
            if (check_collision_id(pos_1, size_1, engine) == true) {
                engine->game.list = start;
                return engine->game.list->settings.id;
            }
        }
        engine->game.list = engine->game.list->previous;
    }
    engine->game.list = start;
    return 0;
}

int get_collision_obj_id(obj_t *obj, char *obstacles_tag, engine_t *engine)
{
    node_t *start = engine->game.list;
    sfVector2f pos_1 = get_position_obj(*obj, engine);
    sfVector2u size_1 = get_size_obj(obj, engine);

    while (engine->game.list != NULL) {
        if (equal(engine->game.list->settings.tag, obstacles_tag) == true) {
            if (check_collision_id(pos_1, size_1, engine) == true) {
                engine->game.list = start;
                return engine->game.list->settings.id;
            }
        }
        engine->game.list = engine->game.list->previous;
    }
    engine->game.list = start;
    return 0;
}
