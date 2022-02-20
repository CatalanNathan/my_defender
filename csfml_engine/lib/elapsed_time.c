/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** elapsed_time.c
*/

#include "my.h"
#include "engine.h"

bool elapsed_time_seconds(int seconds, float *increment, engine_t *engine)
{
    sfTime convert;

    convert = sfClock_getElapsedTime(engine->win_settings.clock);
    *increment += convert.microseconds;
    if (*increment / 1000000 >= seconds) {
        *increment = 0;
        return true;
    }
    return false;
}

bool elapsed_time_milliseconds(int milliseconds, float *increment, engine_t *engine)
{
    sfTime convert;

    convert = sfClock_getElapsedTime(engine->win_settings.clock);
    *increment += convert.microseconds;
    if (*increment / 1000 >= milliseconds) {
        *increment = 0;
        return true;
    }
    return false;
}

bool elapsed_time_microseconds(int microseconds, float *increment, engine_t *engine)
{
    sfTime convert;

    convert = sfClock_getElapsedTime(engine->win_settings.clock);
    *increment += convert.microseconds;
    if (*increment >= microseconds) {
        *increment = 0;
        return true;
    }
    return false;
}
