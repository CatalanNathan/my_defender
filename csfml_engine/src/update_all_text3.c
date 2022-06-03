/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-mydefender-guillaume.kucia
** File description:
** update_all_text3
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void update_all_text3(void)
{
    if (get_shape_tag("selecte_tower_1").width >=
    (int)get_texture_size_tag("selecte_tower_1").x / 2)
        set_text_visible_tag("price_tower_1", true);
    else
        set_text_visible_tag("price_tower_1", false);
    if (get_shape_tag("selecte_tower_2").width >=
    (int)get_texture_size_tag("selecte_tower_2").x / 2)
        set_text_visible_tag("price_tower_2", true);
    else
        set_text_visible_tag("price_tower_2", false);
    if (get_shape_tag("selecte_tower_3").width >=
    (int)get_texture_size_tag("selecte_tower_3").x / 2)
        set_text_visible_tag("price_tower_3", true);
    else
        set_text_visible_tag("price_tower_3", false);
}
