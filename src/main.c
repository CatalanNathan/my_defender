/*
** EPITECH PROJECT, 2021
** src
** File description:
** main.c
*/

#include "my.h"

void get_arguments_loop(int i, opt_t *opt, int ac, char **av)
{
    if (equal(av[i], "-fullscreen::off")) {
        opt->fullscreen = false;
        opt->define = true;
    }
    if (equal(av[i], "-h")) {
        help();
        opt->define = true;
        opt->fd = 1;
    }
    if (ac >= i + i) {
        if (equal(av[i], "-fps") && (my_getnbr(av[i + 1]) > 0 &&
        my_getnbr(av[2]) < 999)) {
            opt->fps = my_getnbr(av[i + 1]);
            opt->define = true;
        }
    }
}

void unknown_arguments(opt_t *opt, char **av)
{
    if (!opt->define) {
        put("Unknown arguments {%s} You can try"
        " './my_defender [-h]'\n", av[1]);
        opt->fd = 84;
    }
}

void arguments(int ac, char **av, opt_t *opt)
{
    int i = 1;

    for (int i = 1; i < ac; i++)
        get_arguments_loop(i, opt, ac, av);
    unknown_arguments(opt, av);
}

int main(int ac, char **av)
{
    opt_t opt;

    opt.fps = 60;
    opt.fullscreen = true;
    opt.define = false;
    opt.fd = 0;
    if (ac > 1)
        arguments(ac, av, &opt);
    if (opt.fd != 84 && opt.fd != 1)
        return csfml_engine((int[3]){1920, 1080, 32},
        "my_defender", opt.fullscreen, opt.fps);
    return 0;
}
