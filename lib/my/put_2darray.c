/*
** EPITECH PROJECT, 2021
** Minishell1
** File description:
** put_2darray.c
*/

#include "my.h"

void put_2darray(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        put("%s\n", array[i]);
}
