/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** my_spacelen.c
*/

#include "my.h"

int my_spacelen(char *str)
{
    int space = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '\n')
            space++;
    return space;
}
