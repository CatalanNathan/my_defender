/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** build_time.c
*/

 #include "engine.h"
 #include "var.h"
 #include "my.h"

void link_build(void)
{
    set_link_tag("clock_build1", "Tower_1.1");
    set_link_tag("clock_build2", "Tower_1.2");
    set_link_tag("clock_build3", "Tower_1.3");
    set_link_tag("clock_build4", "Tower_1.4");
    set_link_tag("clock_build5", "Tower_1.5");
}

void create_build_time(var_t *var)
{
    create_object("clock_time_wall.png", "clock_build1", 7);
    set_position_tag("clock_build1", (V2f){get_position_tag("Tower_1.1").x + 30, get_position_tag("Tower_1.1").y + 150});
    create_object("clock_time_wall.png", "clock_build2", 7);
    set_position_tag("clock_build2", (V2f){get_position_tag("Tower_1.2").x + 30, get_position_tag("Tower_1.2").y + 150});
    create_object("clock_time_wall.png", "clock_build3", 7);
    set_position_tag("clock_build3", (V2f){get_position_tag("Tower_1.3").x + 30, get_position_tag("Tower_1.3").y + 150});
    create_object("clock_time_wall.png", "clock_build4", 7);
    set_position_tag("clock_build4", (V2f){get_position_tag("Tower_1.4").x + 30, get_position_tag("Tower_1.4").y + 150});
    create_object("clock_time_wall.png", "clock_build5", 7);
    set_position_tag("clock_build5", (V2f){get_position_tag("Tower_1.5").x + 30, get_position_tag("Tower_1.5").y + 150});
    set_exits_tag("clock_build1", false);
    set_exits_tag("clock_build2", false);
    set_exits_tag("clock_build3", false);
    set_exits_tag("clock_build4", false);
    set_exits_tag("clock_build5", false);
    link_build();
}
