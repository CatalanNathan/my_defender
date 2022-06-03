/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-guillaume.kucia
** File description:
** help.c
*/

#include "my.h"

void help(void)
{
    char *help = NULL;

    scan("src/help.txt", &help);
    put("%s\n", help);
    free(help);
}
