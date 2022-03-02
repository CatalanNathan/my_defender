/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** checker_normes
*/

#include "my.h"
#include "engine.h"
#include "var.h"

bool check_collision_id(sfVector2f pos_1, sfVector2u size_1);

int check_collision_obj_norms(V2f p1, sfVector2u size_1, char *obstacles_tag)
{
    if (equal(engine.game.list->settings.tag, obstacles_tag))
        if (check_collision_id(p1, size_1) == true)
            return engine.game.list->settings.id;
    return 0;
}

int menfou(char *obstacles_tag, V2f pos_1, sfVector2u size_1)
{
    if (equal(engine.game.list->settings.tag, obstacles_tag))
        if (check_collision_id(pos_1, size_1) == true)
            return engine.game.list->settings.id;
    return 0;
}
