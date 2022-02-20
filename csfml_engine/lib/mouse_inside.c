/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** mouse_inside.c
*/

#include "my.h"
#include "engine.h"

bool mouse_inside_tag(char *tag, engine_t *engine)
{
    sfVector2i mouse_pos;

    if (sfRenderWindow_isOpen(engine->win_settings.engine))
        mouse_pos = sfMouse_getPositionRenderWindow(engine->win_settings.engine);
    else
        mouse_pos = sfMouse_getPositionRenderWindow(engine->win_settings.window);
    sfVector2f tag_pos = get_position_tag(tag, engine);
    sfVector2u tag_size = get_size_tag(tag, engine);

    if ((mouse_pos.x >= tag_pos.x && mouse_pos.x <= tag_pos.x + tag_size.x) &&
    (mouse_pos.y >= tag_pos.y && mouse_pos.y <= tag_pos.y + tag_size.y))
        return true;
    return false;
}

bool mouse_inside_obj(obj_t *obj, engine_t *engine)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(engine->win_settings.window);
    sfVector2f obj_pos = get_position_obj(*obj, engine);
    sfVector2u obj_size = get_size_obj(obj, engine);

    if ((mouse_pos.x >= obj_pos.x && mouse_pos.x <= obj_pos.x + obj_size.x) &&
    (mouse_pos.y >= obj_pos.y && mouse_pos.y <= obj_pos.y + obj_size.y))
        return true;
    return false;
}
