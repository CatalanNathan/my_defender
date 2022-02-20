/*
** EPITECH PROJECT, 2021
** Minishell1
** File description:
** my_arraylen.c
*/

#include "my.h"

int my_arraylen(char **array)
{
    int i = 0;

    for (; array[i] != NULL; i++);
    return i;
}
