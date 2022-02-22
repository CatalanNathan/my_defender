/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** create_tower.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void create_tower(char *src_img, V2f pos, var_t *var)
{
    var->tower.tower = create_object(src_img, "tower", 8);
    set_shape_obj(&var->tower.tower, (sfIntRect){0, 0, 387, get_size_obj(&var->tower.tower).y}, true);
    set_position_obj(var->tower.tower, pos);
}
