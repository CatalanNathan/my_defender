/*
** EPITECH PROJECT, 2021
** Sokoban
** File description:
** allowed.c
*/

#include "my.h"

bool check(char unverified, char *library)
{
    int passed = 0;

    for (int e = 0; library[e] != '\0'; e++) {
        if (unverified == library[e])
            passed = 1;
    }
    if (passed == 1)
        return true;
    else
        return false;
}

bool allowed(char *unverified, char *library)
{
    for (int i = 0; unverified[i] != '\0'; i++) {
        if (check(unverified[i], library) == false)
            return false;
    }
    return true;
}
