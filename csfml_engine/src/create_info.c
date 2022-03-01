/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** create_info.c
*/

#include "engine.h"
#include "my.h"
#include "var.h"

void create_info(var_t *var)
{
    create_object("info+.png", "info+", 0);
    set_visible_tag("info+", false);
}
