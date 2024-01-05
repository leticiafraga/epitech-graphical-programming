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
            mini_printf("MY RADAR\nAir traffic simulation panel\n\n");
            mini_printf("USAGE\n  ./my_radar [OPTIONS] path_to_script\n");
            mini_printf("  path_to_script The path to the script file.\n");
            mini_printf("OPTIONS\n");
            mini_printf("  -h \t\tprint the usage and quit.\n");
            mini_printf("USER INTERACTIONS\n");
            mini_printf("  'L' key\tenable/disable hitboxes and areas.\n");
            return 1;
        }
    }
    return 0;
}

static int game_loop(game_parts *game, corner **corners, sfText *timer)
{
    render(game);
    display_timer(game->window, timer, game->timer);
    sfRenderWindow_display(game->window);
    analyse_events(game);
    handle_move_planes(game->planes,
        game->plane_cnt, game->clock, game->window);
    set_planes_corner(corners, game->planes, game->plane_cnt);
    check_collisions(corners, game->towers, game->tower_cnt);
}

static int start_sim(char *str, file_cnt *cnt)
{
    game_parts *game = init_game(cnt);
    corner **corners;
    sfRectangleShape **rects;
    sfText* timer = init_text(game->font);

    if (handle_file(game, str, cnt))
        return 84;
    corners = init_corners(1920, 1080, game->planes, game->plane_cnt);
    while (sfRenderWindow_isOpen(game->window)) {
        game_loop(game, corners, timer);
    }
    destroy(game, corners);
    return 0;
}

static int simulation(char *str)
{
    file_cnt *cnt = validate_file(str);
    int res = 0;

    if (cnt == 0)
        return 84;
    res = start_sim(str, cnt);
    free(cnt);
    return res;
}

int main(int ac, char **av)
{
    if (ac == 1) {
        my_put_err("./my_radar: bad arguments: 0 given but 1 is required\n");
        my_put_err("retry with -h\n");
        return 84;
    }
    if (validate_args(ac, av))
        return 0;
    else {
        return simulation(av[1]);
    }
}
