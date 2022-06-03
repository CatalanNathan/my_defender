/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** tower_destroy
*/

#include "engine.h"
#include "my.h"
#include "var.h"

void check_tower_true(int i, var_t *var)
{
    if (i == 1)
        var->tower.valide_position_1 = true;
    if (i == 2)
        var->tower.valide_position_2 = true;
    if (i == 3)
        var->tower.valide_position_3 = true;
    if (i == 4)
        var->tower.valide_position_4 = true;
    if (i == 5)
        var->tower.valide_position_5 = true;
}

void reattribute_tower(var_t *var, char *tower)
{
    for (int i = '1'; i != '6'; i++) {
        if (i == tower[8]) {
            check_tower_true(i - 48, var);
            set_visible_tag(my_strcat_char("Tower_1.", i), true);
            set_visible_tag(my_strcat_char("Tower_2.", i), true);
            set_visible_tag(my_strcat_char("Tower_3.", i), true);
            return;
        }
    }
}

void tower_destroyer(char *tower, var_t *var, obj_t object, int i)
{
    if (mouse_inside_tag(tower) && var->destroy_mod == true
    && get_shape_tag(tower).left > 1400) {
        sfSprite_setColor(object.sprite, sfYellow);
        if (mouse_press(sfMouseLeft) && var->money >= 5000) {
            var->money -= 5000;
            var->destroy_mod = false;
            set_cursor(var, "cursor");
            set_shape_tag(tower, (sfIntRect){150, 0, get_shape_tag(
            tower).width, get_shape_tag(tower).height}, true);
            reattribute_tower(var, tower);
        }
    } else if (var->thor_mod == false)
        sfSprite_setColor(object.sprite, var->color_tower);
}

void tower_destroy(var_t *var)
{
    obj_t object;
    char *tower = my_strdup("Tower_1.1");
    char e = '1';
    char a = '1';
    static int i = 0;

    if (var->pause)
        return;
    while (a != '4') {
        while (e != '6') {
            object = copy_object_tag(tower);
            tower_destroyer(tower, var, object, i);
            e++;
            tower[8] = e;
        }
        e = '1';
        tower[8] = '1';
        a++;
        tower[6] = a;
    }
}
