/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** mouse_inside_more.c
*/

#include "engine.h"
#include "my.h"
#include "var.h"

obj_t mouse_loop(sfVector2i mouse_pos, node_t *start, obj_t object, char *tag)
{
    sfVector2f tag_pos;
    sfVector2u tag_size;

    tag_pos = get_position_obj(engine.game.list->settings);
    tag_size = get_size_obj(&engine.game.list->settings);
    if ((mouse_pos.x >= tag_pos.x && mouse_pos.x <= tag_pos.x + tag_size.x) &&
    (mouse_pos.y >= tag_pos.y && mouse_pos.y <= tag_pos.y + tag_size.y)) {
        if (equal(engine.game.list->settings.tag, tag)) {
            object = engine.game.list->settings;
            engine.game.list = start;
            return object;
        }
    }
    object.id = -55;
    return object;
}

obj_t mouse_inside_more(char *tag)
{
    sfVector2i mouse_pos;
    node_t *start = engine.game.list;
    obj_t object;

    if (sfRenderWindow_isOpen(engine.win_settings.engine))
        mouse_pos = sfMouse_getPositionRenderWindow(
        engine.win_settings.engine);
    else
        mouse_pos = sfMouse_getPositionRenderWindow(
        engine.win_settings.window);
    for (; engine.game.list != NULL; engine.game.list
    = engine.game.list->previous) {
        object = mouse_loop(mouse_pos, start, object, tag);
        if (object.id != (-55))
            return object;
    }
    engine.game.list = start;
    object.id = -99;
    return object;
}
