/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** change_cursor.c
*/

#include "engine.h"
#include "my.h"
#include "var.h"

void change_cursor(var_t * var)
{
    set_shape_tag("cursor", (sfIntRect){200, 0, 173, 177}, true);
    var->on_button = true;
}
