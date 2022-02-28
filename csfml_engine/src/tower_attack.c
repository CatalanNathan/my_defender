/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** tower_attack
*/

#include "my.h"
#include "engine.h"
#include "var.h"

void check_tower(char *tag, char char_end, char char_up)
{
    // if (char_up == '1') {

    // }
    // if(char_up == '2') {

    // }
    // if (char_up == '3') {

    // }
}

void tower_attack(var_t *var)
{
    obj_t object;
    char *tower = my_strdup("Tower_1.1");
    char char_end = '1';
    char char_up = '1';
    static int i = 0;

    for (; char_up != '4'; char_up++) {
        tower[6] = char_up;
        for (; char_end != '6'; char_end++, tower[8] = char_end) {
            object =  copy_object_tag(tower);
            if (get_shape_obj(&object).left > 400)
                check_tower(tower, char_end, char_up);
        }
        char_end = '1';
    }
}
