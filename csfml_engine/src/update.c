/*
** EPITECH PROJECT, 2021
** CSFML engine
** File description:
** update.c
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void check_is_pause(var_t *var)
{
    if (key_pressed(sfKeyP) && var->settings_m == false && !var->death_m) {
        set_music_play_tag("click", false, 100);
        if (var->pause) {
            (var->pause) = false;
            destroy_object_tag("pause");
        }
        else {
            (var->pause) = true;
            create_object("pause.png", "pause", 5);
        }
    }
}

void end_update(var_t *var)
{
    if (var->on_button == false)
        set_shape_tag("cursor", (sfIntRect){0, 0, 173, 177}, true);
    if (var->info_more == false) {
        set_visible_tag("info+", false);
        set_text_visible_tag("info+", false);
    }
}

void update2(var_t *var)
{
    check_is_pause(var);
    event_game(var);
    make_enemies(var);
    manage_enemy(var);
    manage_construct(var);
    manage_button(var);
    update_all_text(var);
    mouse_event(var);
    tower_event(var);
    tower_attack(var);
    tower_destroy(var);
    update_cursor(var);
    display_lifebar(var);
    settings_update(var);
    death_event(var);
    end_update(var);
}

void update(var_t *var)
{
    static float time = 0.00;
    static float save = 0.00;

    var->on_button = false;
    var->info_more = false;
    if (var->volume < 0)
        var->volume = 0;
    if (var->global_menu) {
        global_menu_event(var);
        end_update(var);
        return;
    }
    if (elapsed_time_seconds(1, &time, &save) && !var->pause)
        var->time_play++;
    set_text_tag("text_enemies", my_itoa(var->nb_enemies, 0));
    update2(var);
}
