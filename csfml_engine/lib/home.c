/*
** EPITECH PROJECT, 2021
** CSFML engine
** File description:
** home.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void initiate(engine_t *engine, int *window_mode, bool fullscreen, char *win_name)
{
    engine->game.game_end = false;
    engine->game.end_value = 0;
    engine->clear_background = sfBlack;
    engine->win_settings.win_mode = (sfVideoMode){window_mode[0], window_mode[1], window_mode[2]};
    engine->win_settings.size = (sfVector2f){window_mode[0], window_mode[1]};
    engine->win_settings.background.display = false;
    engine->win_settings.background.exist = false;
    engine->win_settings.clock = sfClock_create();
    engine->game.list = NULL;
    engine->win_settings.parallax = NULL;
    engine->game.text = NULL;
    engine->game.music = NULL;
    engine->game.gravity = 9.81;
    engine->win_settings.middle_screen = (sfVector2i){sfVideoMode_getDesktopMode().width/2 - engine->win_settings.size.x/2, sfVideoMode_getDesktopMode().height/2 - engine->win_settings.size.y/2};
    engine->win_settings.fullscreen = fullscreen;
    engine->win_settings.win_name = win_name;
    engine->win_settings.fps.view_fps = false;
    engine->win_settings.fps.fps = 0;
}

void display(engine_t *engine)
{
    shape_img(engine);
    if (sfRenderWindow_isOpen(engine->win_settings.engine))
        return display_engine(engine);
    if (engine->win_settings.background.display == true && engine->win_settings.background.exist == true)
        sfRenderWindow_drawSprite(engine->win_settings.window, engine->win_settings.background.sprite, NULL);
    display_parallax(engine);
    display_obj(engine);
    display_text(engine);
    view_fps(engine);
}

void destroy_all(engine_t *engine)
{
    if (engine->win_settings.background.exist == true) {
        sfSprite_destroy(engine->win_settings.background.sprite);
        sfTexture_destroy(engine->win_settings.background.texture);
        engine->win_settings.background.display = false;
        engine->win_settings.background.exist = false;
    }
    destroy_list(engine);
    destroy_music(engine);
    destroy_text(engine);
}

void primary_function(engine_t *engine)
{
    node_t *start = engine->game.list;

    while (engine->event.type == sfEvtClosed) {
        game_end(0, engine);
        break;
    }
    while (engine->game.list != NULL) {
        if (engine->game.list->settings.gravity == true && engine->game.list->settings.exist == true)
            sfSprite_setPosition(engine->game.list->settings.sprite, (sfVector2f){sfSprite_getPosition(engine->game.list->settings.sprite).x, sfSprite_getPosition(engine->game.list->settings.sprite).y + engine->game.gravity});
        engine->game.list = engine->game.list->previous;
    }
    engine->game.list = start;
}

int csfml_engine(int *window_mode, char *win_name, bool fullscreen, int framerate)
{
    engine_t engine;
    var_t var;

    initiate(&engine, window_mode, fullscreen, win_name);
    engine.win_settings.framerate = framerate;
    microprogramme_create(&engine);
    while (sfRenderWindow_isOpen(engine.win_settings.engine) || engine.game.game_end != true) {
        engine_is_open(&var, &engine);
    }
    sfRenderWindow_destroy(engine.win_settings.engine);
    return engine.game.end_value;
}
