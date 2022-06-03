/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-guillaume.kucia
** File description:
** get_collisions_zone.c
*/

#include "engine.h"
#include "var.h"
#include "my.h"

int check_collision_obj_norms(V2f p1, sfVector2u size_1, char *obstacles_tag);
int menfou(char *obstacles_tag, V2f pos_1, sfVector2u size_1);

int get_collision_zone_tag_id(char *obj_tag, char *obstacles_tag, int zone)
{
    node_t *start = engine.game.list;
    sfVector2f pos_1 = get_position_tag(obj_tag);
    sfVector2u size_1 = get_size_tag(obj_tag);
    pos_1.x -= (zone / 2);
    pos_1.y -= (zone / 2);
    size_1.x += zone;
    size_1.y += zone;

    while (engine.game.list != NULL) {
        if (menfou(obstacles_tag, pos_1, size_1) != 0) {
            engine.game.list = start;
            return menfou(obstacles_tag, pos_1, size_1);
        }
        engine.game.list = engine.game.list->previous;
    }
    engine.game.list = start;
    return 0;
}

void change_pos(sfVector2f *pos_1, int zone, obj_t *obj)
{
    (*pos_1).x -= (zone / 2);
    (*pos_1).x += get_size_obj(obj).x / 2;
    (*pos_1).y -= (zone / 2);
    (*pos_1).y += get_size_obj(obj).y / 2;
}

int get_collision_zone_obj_id(obj_t *obj, char *obstacles_tag, int zone)
{
    node_t *start = engine.game.list;
    sfVector2f pos_1 = get_position_obj(*obj);
    sfVector2u size_1 = {zone, zone};
    obj_t kl;
    int r = 0;

    change_pos(&pos_1, zone, obj);
    for (;engine.game.list->previous != NULL;
    engine.game.list = engine.game.list->previous);
    while (engine.game.list != NULL) {
        r = check_collision_obj_norms(pos_1, size_1, obstacles_tag);
        if (r != 0) {
            engine.game.list = start;
            return r;
        }
        engine.game.list = engine.game.list->next;
    }
    engine.game.list = start;
    return 0;
}
