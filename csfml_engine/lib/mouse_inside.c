/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** mouse_inside.c
*/

#include "my.h"
#include "engine.h"

bool mouse_inside_tag(char *tag)
{
    sfVector2i mouse_pos;

    if (sfRenderWindow_isOpen(engine.win_settings.engine))
        mouse_pos = sfMouse_getPositionRenderWindow(
        engine.win_settings.engine);
    else
        mouse_pos = sfMouse_getPositionRenderWindow(
        engine.win_settings.window);
    V2f tag_pos = get_position_tag(tag);
    sfVector2u tag_size = get_size_tag(tag);

    if ((mouse_pos.x >= tag_pos.x && mouse_pos.x <=
    tag_pos.x + tag_size.x) &&
    (mouse_pos.y >= tag_pos.y && mouse_pos.y <=
    tag_pos.y + tag_size.y))
        return true;
    return false;
}

bool mouse_inside_obj(obj_t *obj)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(
    engine.win_settings.window);
    V2f obj_pos = get_position_obj(*obj);
    sfVector2u obj_size = get_size_obj(obj);

    if ((mouse_pos.x >= obj_pos.x && mouse_pos.x <=
    obj_pos.x + obj_size.x) &&
    (mouse_pos.y >= obj_pos.y && mouse_pos.y <=
    obj_pos.y + obj_size.y))
        return true;
    return false;
}
