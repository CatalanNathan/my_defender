/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** mouse_inside_more.c
*/

#include "engine.h"
#include "my.h"
#include "var.h"

// sfVector2i v2u_to_v2i(sfVector2u value)
// {
//     sfVector2i vector;
//     vector.x = value.x;
//     vector.y = value.y;
//     return vector;
// }

obj_t mouse_inside_more(char *tag)
{
    sfVector2i mouse_pos;
    node_t *start = engine.game.list;
    obj_t object;
    sfVector2f tag_pos;
    sfVector2u tag_size;

    if (sfRenderWindow_isOpen(engine.win_settings.engine))
        mouse_pos = sfMouse_getPositionRenderWindow(engine.win_settings.engine);
    else
        mouse_pos = sfMouse_getPositionRenderWindow(engine.win_settings.window);
    for (; engine.game.list != NULL; engine.game.list = engine.game.list->previous) {
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
    }
    engine.game.list = start;
    object.id = -99;
    return object;
}