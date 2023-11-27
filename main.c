/*
** EPITECH PROJECT, 2023
** MY_HUNTER
** File description:
** MY_HUNTER
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/System/Clock.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/hunter.h"

static int validate_args(int ac, char **av)
{
    for (int i = 1; i < ac; i++) {
        if (my_strcmp(av[i], "-h") == 0) {
            mini_printf("MY HUNTER\nUsage: ./my_hunter [OPTION]\n");
            mini_printf("Duck Hunt game.\n");
            mini_printf("With no OPTION, open game.\n");
            mini_printf("  -h \t\t Shows description and options\n");
            return 1;
        }
    }
    return 0;
}

static int start_game(void)
{
    game_parts *game = init_game();
    int state = 0;

    add_sound("assets/startup.wav");
    while (sfRenderWindow_isOpen(game->window))
        switch (state) {
            case 0:
                state = handle_menu(game);
                break;
            case 1:
                state = handle_play(game);
                break;
            case 2:
                state = handle_options(game);
                break;
            case 3:
                state = handle_go(game);
                break;
        }
    destroy(game);
}

int main(int ac, char **av)
{
    if (validate_args(ac, av))
        return 0;
    else
        return start_game();
}
