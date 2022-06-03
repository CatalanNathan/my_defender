/*
** EPITECH PROJECT, 2021
** my_defender_epitech
** File description:
** mouse_scroll_wheel.c
*/

#include "engine.h"
#include "var.h"
#include "my.h"

int mouse_scroll(void)
{
    return engine.event.mouseWheelScroll.wheel;
}
