/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** elapsed_time.c
*/

#include "my.h"
#include "engine.h"

bool elapsed_time_seconds(float seconds, float *increment,
float *save_increment)
{
    sfTime convert = sfClock_getElapsedTime(engine.win_settings.clock);

    if (*increment == 0) {
        *save_increment = convert.microseconds;
        *increment = 1;
    } else {
        *increment += convert.microseconds - *save_increment;
        *save_increment = convert.microseconds;
    }
    if (*increment / 1000000 >= seconds) {
        *increment = 0;
        return true;
    }
    return false;
}

bool elapsed_time_milliseconds(float milliseconds,
float *increment, float *save_increment)
{
    sfTime convert = sfClock_getElapsedTime(engine.win_settings.clock);

    if (*increment == 0) {
        *save_increment = convert.microseconds;
        *increment = 1;
    } else {
        *increment += convert.microseconds - *save_increment;
        *save_increment = convert.microseconds;
    }
    if (*increment / 1000 >= milliseconds) {
        *increment = 0;
        return true;
    }
    return false;
}

bool elapsed_time_microseconds(float microseconds,
float *increment, float *save_increment)
{
    sfTime convert = sfClock_getElapsedTime(engine.win_settings.clock);

    if (*increment == 0) {
        *save_increment = convert.microseconds;
        *increment = 1;
    } else {
        *increment += convert.microseconds - *save_increment;
        *save_increment = convert.microseconds;
    }
    if (*increment >= microseconds) {
        *increment = 0;
        return true;
    }
    return false;
}

void get_elapsed_time(float *increment, float *save_increment)
{
    sfTime convert = sfClock_getElapsedTime(engine.win_settings.clock);

    if (*increment == 0) {
        *save_increment = convert.microseconds;
        *increment = 0.0000001;
    } else {
        *increment = convert.microseconds - *save_increment;
        *save_increment = convert.microseconds;
    }
}
