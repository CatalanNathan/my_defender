/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-mydefender-guillaume.kucia
** File description:
** death_event.c
*/

#include "engine.h"
#include "var.h"
#include "my.h"

void death_action(char *s, var_t *var)
{
    if (equal(s, "DeathExit"))
        game_end(0);
    if (equal(s, "deathRestart")) {
        destroy_all();
        create(var);
    }
    if (equal(s, "DeathMenuBtn")) {
        destroy_all();
        var->global_menu = true;
        create(var);
    }
}

void update_death_btn(var_t *var, char *s)
{
    if (mouse_inside_tag(s)) {
        set_shape_tag(s, (sfIntRect){get_size_tag(s).x, 0,
        get_texture_size_tag(s).x / 2, get_size_tag(s).y}, true);
        change_cursor(var, "cursor");
        if (mouse_press(sfMouseLeft)) {
            set_music_play_tag("click", false, 100);
            death_action(s, var);
        }
    } else {
        set_shape_tag(s, (sfIntRect){0, 0,
        get_texture_size_tag(s).x / 2, get_size_tag(s).y}, true);
    }
}

void create_death(var_t *var)
{
    create_object("deathM.png", "deathM", 5);
    create_object("DeathExit.png", "DeathExit", 4);
    set_this_shape("DeathExit", 820, 472);
    create_object("deathRestart.png", "deathRestart", 4);
    set_this_shape("deathRestart", 492, 472);
    create_object("DeathMenuBtn.png", "DeathMenuBtn", 4);
    set_this_shape("DeathMenuBtn", 658, 472);
    create_text("ok", "TimePlay");
    set_text_position_tag("TimePlay", (V2f){1340, 428});
    create_text("ok", "EnemyKilled");
    set_text_position_tag("EnemyKilled", (V2f){1340, 490});
}

void death_event(var_t *var)
{
    if (var->castle_life <= 0 && !var->death_m) {
        var->pause = true;
        var->death_m = true;
        create_death(var);
    }
    if (!var->death_m)
        return;
    update_death_btn(var, "DeathExit");
    update_death_btn(var, "deathRestart");
    update_death_btn(var, "DeathMenuBtn");
    set_text_tag("TimePlay", my_strcat_char(my_itoa(var->time_play, 0), 's'));
    set_text_tag("EnemyKilled", my_itoa(var->enemies_kill, 0));
}
