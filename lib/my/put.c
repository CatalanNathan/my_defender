/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** my_printf
*/

#include <stdlib.h>
#include "my.h"
#include <stdarg.h>
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char const *str)
{
    for (int i = 0; str[i]; i++)
        my_putchar(str[i]);
}

long long int put_n(long long int nb)
{
    if (nb < 0) {
        my_putchar('-');
        put_n(nb * -1);
    }
    if (nb > 9) {
        put_n(nb / 10);
        put_n(nb % 10);
    }
    if (nb < 10 && nb >= 0) {
        my_putchar(nb + 48);
    }
    return 0;
}

void write_format(int *i, char *my_str, va_list list)
{
    *i += 1;
    if (my_str[*i] == 's')
        my_putstr(va_arg(list, char *));
    if (my_str[*i] == 'd' || my_str[*i] == 'i')
        put_n(va_arg(list, int));
    if (my_str[*i] == 'c')
        my_putchar(va_arg(list, int));
}

void put(char const *string, ...)
{
    int i = 0;
    va_list list;
    va_start(list, string);
    char *my_str = my_strdup(string);

    while (my_str[i] != '\0') {
        if (my_str[i] == '%') {
            write_format(&i, my_str, list);
            i += 1;
        } else {
            my_putchar(my_str[i]);
            i += 1;
        }
    }
    free(my_str);
    va_end(list);
}
