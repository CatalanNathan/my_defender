/*
** EPITECH PROJECT, 2021
** CSFML engine
** File description:
** home.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"

engine_t engine = { 0 };

void initiate(int *window_mode, bool fullscreen, char *win_name)
{
    engine.game.game_end = false;
    engine.game.end_value = 0;
    engine.clear_background = sfBlack;
    engine.win_settings.win_mode = (sfVideoMode){window_mode[0],
    window_mode[1], window_mode[2]};
    engine.win_settings.size = (V2f){window_mode[0], window_mode[1]};
    engine.win_settings.background.display = false;
    engine.win_settings.background.exist = false;
    engine.win_settings.clock = sfClock_create();
    engine.game.list = NULL;
    engine.win_settings.parallax = NULL;
    engine.game.text = NULL;
    engine.game.music = NULL;
    engine.game.gravity = 9.81;
    engine.win_settings.middle_screen.x = window_mode[0];
    engine.win_settings.middle_screen.y = window_mode[1];
    engine.win_settings.fullscreen = fullscreen;
    engine.win_settings.win_name = win_name;
    engine.win_settings.fps.view_fps = false;
    engine.win_settings.fps.fps = 0;
}

void display(int start)
{
    shape_img(engine);
    if (start == 0)
        return display_engine(engine);
    if (engine.win_settings.background.display &&
    engine.win_settings.background.exist)
        sfRenderWindow_drawSprite(engine.win_settings.window,
        engine.win_settings.background.sprite, NULL);
    display_parallax(engine);
    display_obj(engine);
    display_text(engine);
    view_fps();
}

void destroy_all(void)
{
    if (engine.win_settings.background.exist == true) {
        sfSprite_destroy(engine.win_settings.background.sprite);
        sfTexture_destroy(engine.win_settings.background.texture);
        engine.win_settings.background.display = false;
        engine.win_settings.background.exist = false;
    }
    destroy_list(engine);
    destroy_music(engine);
    destroy_text(engine);
}

void primary_function(void)
{
    node_t *start = engine.game.list;

    while (engine.event.type == sfEvtClosed) {
        game_end(0);
        break;
    }
    while (engine.game.list != NULL) {
        if (engine.game.list->settings.gravity &&
        engine.game.list->settings.exist)
            sfSprite_setPosition(engine.game.list->settings.sprite,
            (V2f){sfSprite_getPosition(engine.game.list->settings.sprite).x,
            sfSprite_getPosition(engine.game.list->settings.sprite).y +
            engine.game.gravity});
        engine.game.list = engine.game.list->previous;
    }
    engine.game.list = start;
}

int csfml_engine(int *window_mode, char *win_name, bool fullscreen,
int framerate)
{
    static int start = 0;
    var_t var;

    initiate(window_mode, fullscreen, win_name);
    engine.win_settings.framerate = framerate;
    microprogramme_create();
    while (sfRenderWindow_isOpen(engine.win_settings.engine)
    || engine.game.game_end != true) {
        engine_is_open(&start, &var);
    }
    sfRenderWindow_destroy(engine.win_settings.engine);
    return engine.game.end_value;
}
