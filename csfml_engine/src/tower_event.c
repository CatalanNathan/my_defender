/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** tower_event.c
*/

#include "engine.h"
#include "my.h"
#include "var.h"

void check_time(obj_t object)
{
    set_exits_tag(object.link_tag, true);
}

void check_upgrade_tower(char *tag)
{
    if (equal(tag, "Tower_1.1"))
    if (equal(tag, "Tower_1.2"))
    if (equal(tag, "Tower_1.3"))
    if (equal(tag, "Tower_1.4"))
    if (equal(tag, "Tower_1.5"))
    if (equal(tag, "Tower_2.1"))
    if (equal(tag, "Tower_2.2"))
    if (equal(tag, "Tower_2.3"))
    if (equal(tag, "Tower_2.4"))
    if (equal(tag, "Tower_2.5"))
    return;
}

void tower_event(var_t *var)
{
    obj_t object;
    char *tower = my_strdup("Tower_1.1");
    char e = '1';
    static int i = 0;

    while (e != '6') {
        object = copy_object_tag(tower);
        if (mouse_inside_tag(tower) && var->thor_mod == true) {
            sfSprite_setColor(object.sprite, sfYellow);
            if (mouse_pressed(sfMouseLeft, &i)) {
                check_time(object);
                check_upgrade_tower(tower);
            }
        }
        else
            sfSprite_setColor(object.sprite, var->color_tower);
        e++;
        tower[8] = e;
    }
}
