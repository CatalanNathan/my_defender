/*
** EPITECH PROJECT, 2021
** CSFML engine
** File description:
** update.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void update(var_t *var)
{
    var->on_button = false;
    event_game(var);
    make_enemies(var);
    manage_enemy(var);
    manage_construct(var);
    manage_button(var);
    update_all_text(var);
    mouse_event(var);
    tower_event(var);
    if (var->on_button == false)
        set_shape_tag("cursor", (sfIntRect){0, 0, 173, 177}, true);
}
