/*
** EPITECH PROJECT, 2021
** csfml_engine
** File description:
** engine_is_open.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void window_creator()
{
    if (engine.win_settings.fullscreen == true)
        engine.win_settings.window = sfRenderWindow_create(engine.win_settings.win_mode, engine.win_settings.win_name, sfFullscreen | sfClose, NULL);
    else
        engine.win_settings.window = sfRenderWindow_create(engine.win_settings.win_mode, engine.win_settings.win_name, sfClose, NULL);
    if (engine.win_settings.framerate != 0)
        sfRenderWindow_setFramerateLimit(engine.win_settings.window, engine.win_settings.framerate);
}

void microprogramme_create()
{
    engine.win_settings.engine = sfRenderWindow_create((sfVideoMode){960, 540, 32}, "csfml engine", sfNone, NULL);
    window_set_position((sfVector2i){sfVideoMode_getDesktopMode().width/2 - 960/2, sfVideoMode_getDesktopMode().height/2 - 540/2});
    set_background("csfml_engine.png", false);
    create_object("load.png", "loadBar", 1);
    set_scale_tag("loadBar", (sfVector2f){0, 0.2});
    set_position_tag("loadBar", (sfVector2f){0, 540 - get_size_tag("loadBar").y});
    create_object("Exit.png", "engineExit", 1);
    set_position_tag("engineExit", (sfVector2f){20, 20});
    set_shape_tag("engineExit", (sfIntRect){0, 0, 30, get_size_tag("engineExit").y}, true);
}

void microprogramme(int *start, var_t *var)
{
    if (*start == 0 && get_scale_tag("loadBar").x >= 1) {
        *start = 1;
        window_creator();
        destroy_all();
        sfRenderWindow_close(engine.win_settings.engine);
        window_set_position(engine.win_settings.middle_screen);
        sfClock_restart(engine.win_settings.clock);
        engine.win_settings.fps.elapsed = sfClock_create();
        create(var);
        return;
    }
    if (get_scale_tag("loadBar").x < 1 && engine.win_settings.time.microseconds / 1000 > 5) {
        set_scale_tag("loadBar", (sfVector2f){get_scale_tag("loadBar").x + 0.001, 0.2});
        sfClock_restart(engine.win_settings.clock);
    }
    if (key_pressed(sfKeyEscape))
        game_end(0);
    exit_program();
}

void engine_is_open(int *start, var_t *var)
{
    engine.win_settings.time = sfClock_getElapsedTime(engine.win_settings.clock);
    if (sfRenderWindow_isOpen(engine.win_settings.engine))
        sfRenderWindow_clear(engine.win_settings.engine, engine.clear_background);
    else if (engine.game.game_end == false)
        sfRenderWindow_clear(engine.win_settings.window, engine.clear_background);
    if (*start == 1 && (engine.game.game_end == false)) {
        sfRenderWindow_pollEvent(engine.win_settings.window, &engine.event);
        update(var);
        primary_function();
        sfClock_restart(engine.win_settings.clock);
    } else
        microprogramme(start, var);
    display(*start);
    if (engine.game.game_end == true) {
        destroy_all();
        if (*start == 1) {
            sfRenderWindow_close(engine.win_settings.window);
            sfRenderWindow_destroy(engine.win_settings.window);
        } else
            sfRenderWindow_close(engine.win_settings.engine);
    } else {
        if (sfRenderWindow_isOpen(engine.win_settings.engine))
            sfRenderWindow_display(engine.win_settings.engine);
        else
            sfRenderWindow_display(engine.win_settings.window);
    }
}
