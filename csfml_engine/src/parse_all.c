/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** parse_all
*/

#include "my.h"
#include "engine.h"
#include "var.h"

char *format_number(char *str, int str_i)
{
    int char_count = my_strlen(str);
    int space_count = ((int)(char_count / 3));
    char *res = malloc(sizeof(char) * (char_count + space_count + 1));
    int i = 0;
    int digit;
    int out_index = 0;

    for (i = str_i; i != 0; i /= 10) {
        digit = i % 10;
        if ((out_index + 1) % 4 == 0)
            res[out_index++] = ' ';
        res[out_index++] = digit + '0';
    }
    res[out_index] = '\0';
    my_revstr(res);
    return res;
}
