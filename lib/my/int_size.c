/*
** EPITECH PROJECT, 2021
** LIB
** File description:
** int_size.c
*/

#include "my.h"

int int_size(int n)
{
    int size = 0;

    while (n >= 1) {
        size += 1;
        n /= 10;
    }
    return size;
}
