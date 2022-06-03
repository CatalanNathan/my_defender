/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** create_tools.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void create_tools(var_t *var)
{
    create_object("btools.png", "btools", 10);
    set_position_tag("btools", (V2f){150,
    get_position_tag("constructMenu").y - 5});
    set_shape_tag("btools", (sfIntRect){0, 0, 87, 85}, true);

    create_object("selecte_delete.png", "delete", 7);
    set_shape_tag("delete", (sfIntRect){ 0, 0,
    get_size_tag("delete").x/2, get_size_tag("delete").y}, true);
    set_position_tag("delete", (V2f){get_position_tag("btools").x + 110,
    get_position_tag("btools").y + 11});
    create_text("5 000", "price_delete");
    set_text_size_tag("price_delete", 10);
    set_text_position_tag("price_delete", (V2f){get_position_tag("delete").x +
    get_size_tag("delete").x/2 - 8, get_position_tag("delete").y + 48});
    set_text_color_tag("price_delete", sfWhite);
}
