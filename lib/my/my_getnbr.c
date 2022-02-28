/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-nathan.catalan
** File description:
** my_getnbr
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>

int find_my_number(char *str)
{
    int i = 0;

    while ((str[i] < '1' || str[i] > '9') && str[i] != '-' && str[i] != '\0')
        i += 1;
    return i;
}

int my_getnbr(char *str)
{
    int i = find_my_number(str);
    int number = 0;
    int negative = 0;

    if (str[i] == '-') {
        negative = 1;
        i += 1;
    }
    while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9')) {
        number = (number * 10) + str[i] - 48;
        i += 1;
    }
    if (negative == 1)
        number *= (-1);
    return number;
}
