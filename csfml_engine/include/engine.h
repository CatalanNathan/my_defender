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

struct enemy_s
{
    bool it_is;
    sfVector2f *path;
    float anim_ennemie;
    float move_enemies;
    int pos_path;
};
typedef struct enemy_s enemy_t;

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
    enemy_t enemy;

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

extern engine_t engine;

void shape_img();
void display_engine();
void window_set_position(sfVector2i offset);
void microprogramme_create();
void primary_function();
void display(int start);
void destroy_all();
void set_background(char *src_img, bool auto_resize);
bool key_pressed(sfKeyCode key);
void game_end(int value);
obj_t create_object(char *src_img, char *flag, int display_order);
void set_scale_tag(char *tag, sfVector2f scale);
void set_scale_obj(obj_t *obj, sfVector2f scale);
sfVector2f get_scale_tag(char *tag);
void set_position_tag(char *tag, sfVector2f offset);
void set_position_obj(obj_t obj, sfVector2f offset);
sfVector2u get_size_tag(char *tag);
sfVector2u get_size_obj(obj_t *obj);
void set_gravity_tag(char *tag, bool gravity);
void set_gravity_obj(obj_t *obj, bool gravity);
sfVector2f get_position_tag(char *tag);
sfVector2f get_position_obj(obj_t obj);
void set_shape_tag(char *tag, sfIntRect shape, bool ishape);
void set_shape_obj(obj_t *obj, sfIntRect shape, bool ishape);
bool get_collision_tag(char *obj_tag, char *obstacles_tag);
bool get_collision_obj(obj_t *obj, char *obstacles_tag);
void set_parallax(char **src_img, float speed, float multiplicator);
void display_parallax();
void set_visible_tag(char *tag, bool visible);
void set_visible_obj(obj_t *obj, bool visible);
void view_fps();
void set_fps(bool visible, int font_size, sfColor color);
bool mouse_inside_tag(char *tag);
bool mouse_pressed(sfMouseButton button);
bool mouse_inside_obj(obj_t *obj);
bool elapsed_time_seconds(int seconds, float *increment);
bool elapsed_time_milliseconds(int milliseconds, float *increment);
bool elapsed_time_microseconds(int microseconds, float *increment);
sfIntRect get_shape_tag(char *tag);
sfIntRect get_shape_obj(obj_t *obj);
void animation_tag(char *tag, int *shape_start_increment_end_milliseconds, float *increment);
void animation_obj(obj_t *obj, int *shape_start_increment_end_milliseconds, float *increment);
void display_obj();
text_t create_text(char *text, char *tag);
void display_text();
void set_text_color_text(text_t *text, sfColor color);
void set_text_color_tag(char *tag, sfColor color);
void set_text_position_text(text_t text, sfVector2f position);
void set_text_position_tag(char *tag, sfVector2f position);
void set_text_text(text_t *text, char *str);
void set_text_tag(char *tag, char *text);
void set_text_size_text(text_t *text, int size);
void set_text_size_tag(char *tag, int size);
void set_text_visible_tag(char *tag, bool visible);
void set_text_visible_text(text_t *text, bool visible);
sfVector2f get_text_position_tag(char *tag);
sfVector2f get_text_position_text(text_t text);
bool key_press(sfKeyCode key);
bool mouse_press(sfMouseButton button);
void exit_program();
sfVector2u get_texture_size_tag(char *tag);
sfVector2u get_texture_size_obj(obj_t *obj);
music_t create_music(char *src_sound, char *tag);
void set_music_play_sfmusic(music_t *sound, bool loop, float volume);
void set_music_play_tag(char *tag, bool loop, float volume);
void set_music_pause_sfmusic(music_t *sound);
void set_music_pause_tag(char *tag);
void set_music_stop_tag(char *tag);
void set_music_stop_sfmusic(music_t *sound);
void set_music_volume_sfmusic(music_t *sound, float volume);
void set_music_volume_tag(char *tag, float volume);
void set_music_loop_tag(char *tag, bool loop);
void set_music_loop_sfmusic(music_t *sound, bool loop);
void destroy_list();
void destroy_music();
void destroy_text();
int get_collision_obj_id(obj_t *obj, char *obstacles_tag);
int get_collision_tag_id(char *obj_tag, char *obstacles_tag);
obj_t copy_object(int id);
void set_rotation_obj(obj_t *obj, float angle);
void set_rotation_tag(char *tag, float angle);
void destroy_object(int id);
sfVector2f get_scale_obj(obj_t obj);
bool compare_sfvector2f(sfVector2f first, sfVector2f second);
void set_enemy_obj(obj_t *obj, sfVector2f *path);
void set_enemy_tag(char *tag, sfVector2f *path);
sfVector2f *random_this(sfVector2f *value, int n);

#endif
