/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** my_compare
*/

#include "my.h"
#include "engine.h"
#include "var.h"

bool compare_sfvector2f(sfVector2f first, sfVector2f second)
{
    if (first.x == second.x && first.y == second.y)
        return true;
    return false;
}
