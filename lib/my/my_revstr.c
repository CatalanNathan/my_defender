/*
** EPITECH PROJECT, 2021
** my_revstr.c
** File description:
** Day06 task03
*/

#include <unistd.h>

char *my_revstr(char *str)
{
    char mot;
    int a = 0;
    int b = 0;

    while (str[a] != '\0') {
        a++;
    }
    a--;

    while (b < a) {
        mot = str[b];
        str[b] = str[a];
        str[a] = mot;
        b++;
        a--;
    }
    return str;
}
