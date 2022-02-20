/*
** EPITECH PROJECT, 2021
** CSFML engine
** File description:
** engine.h
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/FontInfo.h>
#include <SFML/Graphics/Glyph.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/InputStream.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/Time.h>
#include <SFML/System/Vector3.h>
#include <stddef.h>
#include <SFML/Audio.h>
#include "my.h"

#ifndef ENGINE_
    #define ENGINE_

struct obj_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2u size;
    char *tag;
    bool display;
    bool exist;
    bool gravity;
    bool ishape;
    float speed;
    bool mouse_inside;
    sfIntRect shape;
    int display_order;
    float angle;
    int id;
};
typedef struct obj_s obj_t;

struct text_s
{
    sfText *text;
    int id;
    bool display;
    bool exist;
    int font_size;
    sfColor color;
    char *tag;
};
typedef struct text_s text_t;

struct music_s
{
    sfMusic *sound;
    int id;
    float volume;
    bool playing;
    bool loop;
    char *tag;
};
typedef struct music_s music_t;

typedef struct node_s node_t;
struct node_s
{
    node_t *next;
    node_t *previous;
    obj_t settings;

};

typedef struct node_music_s node_music_t;
struct node_music_s
{
    node_music_t *next;
    node_music_t *previous;
    music_t settings;

};

typedef struct node_text_s node_text_t;
struct node_text_s
{
    node_text_t *next;
    node_text_t *previous;
    text_t settings;
};

struct fps_s
{
    bool view_fps;
    sfClock *elapsed;
    int fps;
    sfText *text;
    sfTime time;
};
typedef struct fps_s fps_t;

struct window_s
{
    sfRenderWindow* window;
    sfRenderWindow* engine;
    sfVideoMode win_mode;
    sfVector2f size;
    char *win_name;
    bool fullscreen;
    int framerate;
    sfVector2i middle_screen;
    obj_t background;
    node_t *parallax;
    fps_t fps;
    sfClock *clock;
    sfTime time;
};
typedef struct window_s window_t;


struct game_s
{
    node_t *list;
    node_text_t *text;
    node_music_t *music;
    bool game_end;
    float gravity;
    int end_value;
};
typedef struct game_s game_t;

struct engine_s
{
    window_t win_settings;
    game_t game;
    sfColor clear_background;
    sfEvent event;
};
typedef struct engine_s engine_t;

void shape_img(engine_t *engine);
void display_engine(engine_t *engine);
void window_set_position(sfVector2i offset, engine_t *engine);
void microprogramme_create(engine_t *engine);
void primary_function(engine_t *engine);
void display(engine_t *engine);
void destroy_all(engine_t *engine);
void set_background(char *src_img, bool auto_resize, engine_t *engine);
bool key_pressed(sfKeyCode key, engine_t *engine);
void game_end(int value, engine_t *engine);
obj_t create_object(char *src_img, char *flag, int display_order, engine_t *engine);
void set_scale_tag(char *tag, sfVector2f scale,engine_t *engine);
void set_scale_obj(obj_t *obj, sfVector2f scale,engine_t *engine);
sfVector2f get_scale_tag(char *tag, engine_t *engine);
void set_position_tag(char *tag, sfVector2f offset, engine_t *engine);
void set_position_obj(obj_t obj, sfVector2f offset, engine_t *engine);
sfVector2u get_size_tag(char *tag, engine_t *engine);
sfVector2u get_size_obj(obj_t *obj, engine_t *engine);
void set_gravity_tag(char *tag, bool gravity, engine_t *engine);
void set_gravity_obj(obj_t *obj, bool gravity, engine_t *engine);
sfVector2f get_position_tag(char *tag, engine_t *engine);
sfVector2f get_position_obj(obj_t obj, engine_t *engine);
void set_shape_tag(char *tag, sfIntRect shape, bool ishape, engine_t *engine);
void set_shape_obj(obj_t *obj, sfIntRect shape, bool ishape, engine_t *engine);
bool get_collision_tag(char *obj_tag, char *obstacles_tag, engine_t *engine);
bool get_collision_obj(obj_t *obj, char *obstacles_tag, engine_t *engine);
void set_parallax(char **src_img, float speed, float multiplicator, engine_t *engine);
void display_parallax(engine_t *engine);
void set_visible_tag(char *tag, bool visible, engine_t *engine);
void set_visible_obj(obj_t *obj, bool visible, engine_t *engine);
void view_fps(engine_t *engine);
void set_fps(bool visible, int font_size, sfColor color, engine_t *engine);
bool mouse_inside_tag(char *tag, engine_t *engine);
bool mouse_pressed(sfMouseButton button, engine_t *engine);
bool mouse_inside_obj(obj_t *obj, engine_t *engine);
bool elapsed_time_seconds(int seconds, float *increment, engine_t *engine);
bool elapsed_time_milliseconds(int milliseconds, float *increment, engine_t *engine);
bool elapsed_time_microseconds(int microseconds, float *increment, engine_t *engine);
sfIntRect get_shape_tag(char *tag, engine_t *engine);
sfIntRect get_shape_obj(obj_t *obj, engine_t *engine);
void animation_tag(char *tag, int *shape_start_increment_end_milliseconds, float *increment, engine_t *engine);
void animation_obj(obj_t *obj, int *shape_start_increment_end_milliseconds, float *increment, engine_t *engine);
void display_obj(engine_t *engine);
text_t create_text(char *text, char *tag, engine_t *engine);
void display_text(engine_t *engine);
void set_text_color_text(text_t *text, sfColor color, engine_t *engine);
void set_text_color_tag(char *tag, sfColor color, engine_t *engine);
void set_text_position_text(text_t text, sfVector2f position, engine_t *engine);
void set_text_position_tag(char *tag, sfVector2f position, engine_t *engine);
void set_text_text(text_t *text, char *str, engine_t *engine);
void set_text_tag(char *tag, char *text, engine_t *engine);
void set_text_size_text(text_t *text, int size, engine_t *engine);
void set_text_size_tag(char *tag, int size, engine_t *engine);
void set_text_visible_tag(char *tag, bool visible, engine_t *engine);
void set_text_visible_text(text_t *text, bool visible, engine_t *engine);
sfVector2f get_text_position_tag(char *tag, engine_t *engine);
sfVector2f get_text_position_text(text_t text, engine_t *engine);
bool key_press(sfKeyCode key, engine_t *engine);
bool mouse_press(sfMouseButton button, engine_t *engine);
void exit_program(engine_t *engine);
sfVector2u get_texture_size_tag(char *tag, engine_t *engine);
sfVector2u get_texture_size_obj(obj_t *obj, engine_t *engine);
music_t create_music(char *src_sound, char *tag, engine_t *engine);
void set_music_play_sfmusic(music_t *sound, bool loop, float volume, engine_t *engine);
void set_music_play_tag(char *tag, bool loop, float volume, engine_t *engine);
void set_music_pause_sfmusic(music_t *sound, engine_t *engine);
void set_music_pause_tag(char *tag, engine_t *engine);
void set_music_stop_tag(char *tag, engine_t *engine);
void set_music_stop_sfmusic(music_t *sound, engine_t *engine);
void set_music_volume_sfmusic(music_t *sound, float volume, engine_t *engine);
void set_music_volume_tag(char *tag, float volume, engine_t *engine);
void set_music_loop_tag(char *tag, bool loop, engine_t *engine);
void set_music_loop_sfmusic(music_t *sound, bool loop, engine_t *engine);
void destroy_list(engine_t *engine);
void destroy_music(engine_t *engine);
void destroy_text(engine_t *engine);
int get_collision_obj_id(obj_t *obj, char *obstacles_tag, engine_t *engine);
int get_collision_tag_id(char *obj_tag, char *obstacles_tag, engine_t *engine);
obj_t copy_object(int id, engine_t *engine);
void set_rotation_obj(obj_t *obj, float angle, engine_t *engine);
void set_rotation_tag(char *tag, float angle, engine_t *engine);
void destroy_object(int id, engine_t *engine);

#endif
