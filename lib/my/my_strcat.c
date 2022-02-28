/*
** EPITECH PROJECT, 2021
** B-CPE-101-MPL-1-1-bistromatic-nicolas.spijkerman
** File description:
** my_strcat
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    int dest_len = my_strlen(dest);
    char *res = malloc(dest_len + my_strlen(src) + 1);

    my_strcpy(res, dest);
    while (src[i]) {
        res[dest_len + i] = src[i];
        i++;
    }
    res[dest_len + i] = 0;
    return res;
}

char *my_strcat_char(char *dest, char src)
{
    int dest_len = my_strlen(dest);
    char *res = malloc(dest_len + 2);

    my_strcpy(res, dest);
    res[dest_len] = src;
    res[dest_len + 1] = 0;
    return res;
}
