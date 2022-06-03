/*
** EPITECH PROJECT, 2021
** CSFML engine
** File description:
** engine.h
*/

#include "engine.h"
#include "my.h"

#ifndef VAR_
    #define VAR_

typedef struct wall_s
{
    obj_t button;
    int wait_time;
} wall_t;

struct tower_s
{
    obj_t tower;
    int price_tower_1;
    int price_tower_2;
    int price_tower_3;
    float build_time_t1;
    float build_time_t2;
    float buil_time__t3;
    int tower_selected;
    bool valide_position_1;
    bool valide_position_2;
    bool valide_position_3;
    bool valide_position_4;
    bool valide_position_5;
};

typedef struct tower_s tower_t;

struct var_s
{
    int enemie_recup;
    int nb_enemies;
    int nb_enemies_max;
    obj_t enemies;
    obj_t b_constructor;
    tower_t tower;
    wall_t wall;
    float castle_life;
    int enemy_dammage;
    obj_t hearth;
    int money;
    int price_wall;
    obj_t background;
    bool on_button;
    bool info_more;
    bool thor_mod;
    bool destroy_mod;
    sfColor color_tower;
    char *actual_c;
    sfClock *pause_clock;
    bool pause;
    bool settings_m;
    bool death_m;
    int enemies_kill;
    int time_play;
    bool global_menu;
    float volume;
    char m;
    sfText *nb_enemies_text;
};
typedef struct var_s var_t;

void create(var_t *var);
void update(var_t *var);
void engine_is_open(int *start, var_t *var);
void manage_enemy(var_t *var);
void manage_construct(var_t *var);
void make_enemies(var_t *var);
void create_enemies(var_t *var);
void create_tower(char *src_img, V2f pos, var_t *var, char *tag);
void create_wall(char *src_image, V2f pos, var_t *var, char *tag);
void manage_button(var_t *var);
void create_loop_game(var_t *var);
void update_all_text(var_t *var);
void init_system(var_t *var);
void create_selected_tower(var_t *var);
void selected_button_tower(var_t *var);
void change_cursor(var_t * var, char *tga_new_cursor);
void mouse_event(var_t *var);
void update_button_exists(char *tag_obj,
char *tag_button, float *incrementation, float *save);
void event_game(var_t *var);
void tower_event(var_t *var);
void create_interface(var_t *var);
void create_their_text(var_t *var);
void create_build_time(var_t *var);
void create_text_build_time(void);
void time_tower_run_one(var_t *var, char **tags, int *i);
void time_tower_run_two(var_t *var, char **tags, int *i);
void time_tower_run_three(var_t *var, char **tags, int *i);
void time_tower_run_four(var_t *var, char **tags, int *i);
void time_tower_run_five(var_t *var, char **tags, int *i);
void create_tools(var_t *var);
void btools(var_t *var);
void tower_attack(var_t *var);
void create_info(var_t *var);
void add_info_more(var_t *var, char *info);
void selecte_button_delete(var_t *var);
void frist_btn_tower_norms(var_t *var, int mouse, float calc_shape);
void second_btn_tower_norms(var_t *var, int mouse, float calc_shape);
void third_btn_tower_norms(var_t *var, int mouse, float calc_shape);
void set_cursor(var_t *var, char *new_c);
void update_cursor(var_t *var);
void tower_destroy(var_t *var);
void create_cursor(var_t *var);
void update_spears(var_t *var);
void display_lifebar(var_t *var);
void projectiles_move(char *spears, obj_t copy, float time, var_t *var);
void set_timer_build(int *i, float *timer, var_t *var);
void guard_and_quick(int i, int *guard, int *quick);
void create_settings(var_t *var);
void btn_settings(var_t *var);
void destroy_settings_m(var_t *var);
void settings_update(var_t *var);
void create_settings_m(var_t *var);
void death_event(var_t *var);
void set_this_shape(char *s, int x, int y);
void create_menu(var_t *var);
void global_menu_event(var_t *var);
void create_button_menu(var_t *var);
void menu_button_event(var_t *var);
void manage_settings_panel(var_t *var);
void manage_sanim(var_t *var, float time);
void update_volume_point(var_t *var);
void update_settings_btn(var_t *var, char *s);
void update_fps_point(var_t *var);
void destroy_settings_panels(var_t *var);
void destroy_h_panel(var_t *var);
void manage_h_panel(var_t *var);
void h_event(var_t *var);
void create_music_game(var_t *var);

void set_pv_tag(char *tag, int pv, int pv_max);
void set_pv_obj(obj_t *obj, int pv, int pv_max);
int get_pv_tag(char *tag);
int get_pv_obj(obj_t *obj);
void scene_pause();
void construction_tower(int i, char c);
void settings_action2(var_t *var, char *s);
void update_fpspoint2(void);

#endif
