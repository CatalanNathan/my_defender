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
    int tower_active;
};

typedef struct tower_s tower_t;

struct var_s
{
    int nb_enemies;
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
    bool thor_mod;
    sfColor color_tower;
};
typedef struct var_s var_t;

void create(var_t *var);
void update(var_t *var);
void engine_is_open(int *start, var_t *var);
void manage_enemy(var_t *var);
void manage_construct(var_t *var);
void make_enemies(var_t *var);
void create_enemies(var_t *var, int possibility);
void create_tower(char *src_img, V2f pos, var_t *var, char *tag);
void create_wall(char *src_image, V2f pos, var_t *var, char *tag);
void manage_button(var_t *var);
void create_loop_game(var_t *var);
void update_all_text(var_t *var);
void init_system(var_t *var);
void create_selected_tower(var_t *var);
void selected_button_tower(var_t *var);
void change_cursor(var_t * var);
void mouse_event(var_t *var);
void update_button_exists(char *tag_obj, char *tag_button, float *incrementation, float *save);
void event_game(var_t *var);
void tower_event(var_t *var);
void create_interface(var_t *var);
void create_their_text(var_t *var);
void create_build_time(var_t *var);
void create_text_build_time(void);

#endif
