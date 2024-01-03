/*
** EPITECH PROJECT, 2023
** MY_RADAR
** File description:
** MY_RADAR
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/System/Clock.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/radar.h"

static int validate_args(int ac, char **av)
{
    for (int i = 1; i < ac; i++) {
        if (my_strcmp(av[i], "-h") == 0) {
            mini_printf("MY RADAR\nUsage: ./my_radar [OPTION]\n");
            mini_printf("Flight Radar Simulator.\n");
            mini_printf("With no OPTION, open game.\n");
            mini_printf("  -h \t\t Shows description and options\n");
            return 1;
        }
    }
    return 0;
}

static int start_game(char *str)
{
    game_parts *game = init_game();
    target *d = game->t;
    int n = 500;
    sfCircleShape **circles = init_circles(n);
    corner **corners = init_corners(1920, 1080, circles, n);

    handle_file(game, str);
    while (sfRenderWindow_isOpen(game->window)) {
        render(game, d);
        handle_move_circles(corners, circles, game->clock, n);
        draw_circles(game->window, circles, n);
        analyse_events(game, d);
    }
    destroy(game);
}

int main(int ac, char **av)
{
    if (ac == 1)
        return 84;
    if (validate_args(ac, av))
        return 0;
    else
        return start_game(av[1]);
}
