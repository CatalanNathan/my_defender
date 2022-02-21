/*
** EPITECH PROJECT, 2021
** CSFML engine
** File description:
** update.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void system_function(var_t *var, engine_t *engine)
{
    if (key_pressed(sfKeyEscape, engine))
        game_end(0, engine);
}

void animation_move_enemies(var_t *var, engine_t *engine)
{
    static float anim_ennemie = 0.00;
    static float move_enemies = 0.00;
    static int pos_path = 0;
    sfVector2f path[2] = {{860, 640}, {1020, 750}};

    animation_obj(&var->enemies, (int[4]){0, 48, 240, 100}, &anim_ennemie, engine);
    if (elapsed_time_milliseconds(50, &move_enemies, engine) != true)
        return;
    if (get_position_obj(var->enemies, engine).x > path[pos_path].x) {
        set_position_obj(var->enemies, (sfVector2f){get_position_obj(var->enemies, engine).x - 1,get_position_obj(var->enemies, engine).y}, engine);
        if (get_scale_obj(var->enemies, engine).x > 0) {
            set_position_obj(var->enemies, (sfVector2f){get_position_obj(var->enemies, engine).x + get_size_obj(&var->enemies, engine).x, get_position_obj(var->enemies, engine).y}, engine);
            set_scale_obj(&var->enemies, (sfVector2f){get_scale_obj(var->enemies, engine).x * -1, get_scale_obj(var->enemies, engine).y}, engine);
        }
    }
    if (get_position_obj(var->enemies, engine).x < path[pos_path].x) {
        set_position_obj(var->enemies, (sfVector2f){get_position_obj(var->enemies, engine).x + 1,get_position_obj(var->enemies, engine).y}, engine);
        if (get_scale_obj(var->enemies, engine).x < 0) {
            set_position_obj(var->enemies, (sfVector2f){get_position_obj(var->enemies, engine).x - get_size_obj(&var->enemies, engine).x, get_position_obj(var->enemies, engine).y}, engine);
            set_scale_obj(&var->enemies, (sfVector2f){get_scale_obj(var->enemies, engine).x * -1, get_scale_obj(var->enemies, engine).y}, engine);
        }
    }
    if (get_position_obj(var->enemies, engine).y > path[pos_path].y)
        set_position_obj(var->enemies, (sfVector2f){get_position_obj(var->enemies, engine).x,get_position_obj(var->enemies, engine).y - 0.5}, engine);
    if (get_position_obj(var->enemies, engine).y < path[pos_path].y)
        set_position_obj(var->enemies, (sfVector2f){get_position_obj(var->enemies, engine).x,get_position_obj(var->enemies, engine).y + 0.5}, engine);
    if (compare_sfvector2f(get_position_obj(var->enemies, engine), path[pos_path]))
        pos_path++;
    if (pos_path > 1)
        pos_path = 0;

}

void update(var_t *var, engine_t *engine)
{
    system_function(var, engine);
    animation_move_enemies(var, engine);
}
