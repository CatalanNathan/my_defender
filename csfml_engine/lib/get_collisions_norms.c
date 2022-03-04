/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** get_collisions_norms
*/

#include "my.h"
#include "engine.h"
#include "var.h"

bool check_collision(sfVector2f pos_1, sfVector2u size_1, int decrement);

int get_collision_tag_norms(char *obstacles_tag, sfVector2f pos_1,
sfVector2u size_1)
{
    if (equal(engine.game.list->settings.tag, obstacles_tag))
        if (check_collision(pos_1, size_1, 0) == true)
            return 0;
    return 84;
}

int get_collision_obj_norms(char *obstacles_tag, sfVector2f pos_1,
sfVector2u size_1, int decrement)
{
    if (equal(engine.game.list->settings.tag, obstacles_tag))
        if (check_collision(pos_1, size_1, decrement) == true &&
            engine.game.list->settings.exist == true)
            return 0;
    return 84;
}
