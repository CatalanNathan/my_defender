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
    create_text(format_number(my_itoa(var->tower.price_tower_1, 0), var->tower.price_tower_1), "price_tower_1");
    set_text_size_tag("price_tower_1", 10);
    set_text_position_tag("price_tower_1", (V2f){get_position_tag("selecte_tower_1").x + get_size_tag("selecte_tower_1").x/2 - 8, get_position_tag("selecte_tower_1").y + 48});
    set_text_color_tag("price_tower_1", sfWhite);
    create_text(format_number(my_itoa(var->tower.price_tower_2, 0), var->tower.price_tower_2), "price_tower_2");
    set_text_size_tag("price_tower_2", 10);
    set_text_position_tag("price_tower_2", (V2f){get_position_tag("selecte_tower_2").x + get_size_tag("selecte_tower_2").x/2 - 8, get_position_tag("selecte_tower_2").y + 48});
    set_text_color_tag("price_tower_2", sfWhite);
    create_text(format_number(my_itoa(var->tower.price_tower_3, 0), var->tower.price_tower_3), "price_tower_3");
    set_text_size_tag("price_tower_3", 10);
    set_text_position_tag("price_tower_3", (V2f){get_position_tag("selecte_tower_3").x + get_size_tag("selecte_tower_3").x/2 - 8, get_position_tag("selecte_tower_3").y + 48});
    set_text_color_tag("price_tower_3", sfWhite);
}
