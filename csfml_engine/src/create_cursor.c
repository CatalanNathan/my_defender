/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-guillaume.kucia
** File description:
** create_cursor.c
*/

#include "engine.h"
#include "var.h"
#include "my.h"

void create_cursor(var_t *var)
{
    create_object("btn_delete.png", "btn_delete", 0);
    set_scale_tag("btn_delete", (V2f){0.1, 0.1});
    set_visible_tag("btn_delete", false);
}
