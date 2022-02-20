/*
** EPITECH PROJECT, 2021
** My_runner
** File description:
** my_itoa.c
*/

#include "my.h"
#include <stdlib.h>

void my_itoa_loop(int n, int *division, char *str, int *i)
{
    if (*division != 1)
        str[*i] = ((n / *division) % 10) + 48;
    else
        str[*i] = (n % 10) + 48;
    *i += 1;
    *division /= 10;
}

char *my_itoa(int n, int space)
{
    char *str = malloc(sizeof(char) * ((space + int_size(n)) + 1));
    int i = 0;
    int division = 10;

    if (space != 0 && (space - int_size(n)) != 0) {
        for (; i < (space - int_size(n)); i += 1)
            str[i] = '0';
    }
    for (int e = 0; e != int_size(n); e += 1) {
        division *= 10;
    }
    division /= 100;
    for (int e = 0; e != int_size(n); e += 1) {
        my_itoa_loop(n, &division, str, &i);
    }
    str[i] = '\0';
    return str;

}
