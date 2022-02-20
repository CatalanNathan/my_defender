/*
** EPITECH PROJECT, 2021
** src
** File description:
** main.c
*/

#include "my.h"

int main(void)
{
    return csfml_engine((int[3]){960, 540, 32}, "game", false, 60);
}
