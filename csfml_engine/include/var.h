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
} wall_t;

struct tower_s
{
    obj_t tower;
};

typedef struct tower_s tower_t;

struct var_s
{
    int nb_enemies;
    obj_t enemies;
    obj_t b_constructor;
    tower_t tower;
    wall_t wall;
    int castle_life;
    int enemy_dammage;
    obj_t hearth;
};
typedef struct var_s var_t;



void create(var_t *var);
void update(var_t *var);
void engine_is_open(int *start, var_t *var);
void manage_enemy(var_t *var);
void manage_construct(var_t *var);
void make_enemies(var_t *var);
void create_enemies(var_t *var, int possibility);
void create_tower(char *src_img, V2f pos, var_t *var);
void create_wall(char *src_image, V2f pos, var_t *var);
void manage_button(var_t *var);

#endif
