/*
** EPITECH PROJECT, 2021
** Day06task01
** File description:
** function - my_strcpy
*/

#include <unistd.h>

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
