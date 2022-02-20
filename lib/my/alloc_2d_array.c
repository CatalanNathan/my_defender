/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-BSQ-guillaume.kucia
** File description:
** allocate_my_2d_array.c
*/

#include "my.h"
#include <unistd.h>

int width_alloc(char *str)
{
    int size = 1;

    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == ' ')
            size += 1;
    }
    return size;
}

int size_of_arg_n(char *str, int n)
{
    int i = 0;
    int size = 0;

    while (n != 0) {
        if (str[i] == ' ')
            n -= 1;
        i += 1;
    }
    while (str[i] != ' ' && str[i] != '\0')  {
        size += 1;
        i += 1;
    }
    return size;
}

char **alloc_2d_array(char *str)
{
    char **allocate = malloc((width_alloc(str) + 1) * sizeof(char *));
    allocate[width_alloc(str)] = NULL;

    for (int i = 0; i != width_alloc(str); i += 1) {
        allocate[i] = malloc(sizeof(char) * size_of_arg_n(str, i) + 1);
    }
    return allocate;
}
