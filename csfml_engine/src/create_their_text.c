/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** create_their_text.c
*/

#include "engine.h"
#include "my.h"
#include "var.h"

void create_their_text(var_t *var)
{
    create_text(my_itoa(var->tower.price_tower_1, 0), "price_tower_1");
    set_text_size_tag("price_tower_1", 10);
    set_text_position_tag("price_tower_1", (V2f){get_position_tag("selecte_tower_1").x + get_size_tag("selecte_tower_1").x/2 - 10, get_position_tag("selecte_tower_1").y + 20});
    set_text_color_tag("price_tower_1", sfWhite);
}
