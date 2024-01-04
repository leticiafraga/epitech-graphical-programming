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

    handle_file(game, str);
    while (sfRenderWindow_isOpen(game->window)) {
        render(game);
        sfRenderWindow_display(game->window);
        analyse_events(game);
        handle_move_planes(game->planes, game->plane_cnt, game->clock);
    }
    destroy(game);
    return 0;
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
