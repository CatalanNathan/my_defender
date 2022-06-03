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
    int fd = open(filepath, O_RDONLY);

    stat(filepath, &scan);
    (*buffer) = malloc(sizeof(char) * scan.st_size + 1);
    (*buffer)[scan.st_size] = '\0';
    if (read(fd, (*buffer), scan.st_size) < 0) {
        close(fd);
        return false;
    }
    close(fd);
    return true;
}
