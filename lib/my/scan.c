/*
** EPITECH PROJECT, 2021
** Sokoban
** File description:
** scan.c
*/

#include "my.h"

bool scan(char *filepath, char **buffer)
{
    struct stat scan;

    stat(filepath, &scan);
    *buffer = malloc(sizeof(char) * scan.st_size);
    if (read(open(filepath, O_RDONLY), *buffer, scan.st_size) < 0)
        return false;
    return true;
}
