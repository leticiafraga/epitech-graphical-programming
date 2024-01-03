/*
** EPITECH PROJECT, 2023
** main fns
** File description:
** main fns
*/
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/radar.h"

static int handle_error(int f)
{
    close(f);
    return 84;
}

static sfVector2i get_next_nb(char *str, int i)
{
    int result = 0;
    sfVector2i v = {i, 0};

    while (is_number(str[i])) {
        result = result * 10;
        result += (str[i] - '0');
        i++;
    }
    v.x = i;
    v.y = result;
    return v;
}

static void create_struct_plane(game_parts *game, int *info)
{
    airplane *plane = malloc(sizeof(airplane));

    game->planes[game->plane_cnt] = plane;
    game->plane_cnt += 1;
    plane->departure.x = info[0];
    plane->departure.y = info[1];
    plane->arrival.x = info[2];
    plane->arrival.y = info[3];
    plane->speed = info[4];
    plane->delay = info[5];
}

static void create_struct_tower(game_parts *game, int *info)
{
    tower *t = malloc(sizeof(t));

    game->towers[game->tower_cnt] = t;
    game->tower_cnt += 1;
    t->coordinates.x = info[0];
    t->coordinates.y = info[1];
    t->radius = info[2];
}

static void create_plane(game_parts *game, char *str)
{
    sfVector2i result;
    int i = 0;
    int it = 0;
    int info[10];

    while (str[i] != '\0') {
        if (is_number(str[i])) {
            result = get_next_nb(str, i);
            i = result.x;
            info[it] = result.y;
            it++;
        } else
            i++;
    }
    create_struct_plane(game, info);
}

static void create_tower(game_parts *game, char *str)
{
    sfVector2i result;
    int i = 0;
    int it = 0;
    int info[10];

    while (str[i] != '\0') {
        if (is_number(str[i])) {
            result = get_next_nb(str, i);
            i = result.x;
            info[it] = result.y;
            it++;
        } else
            i++;
    }
    create_struct_tower(game, info);
}

int get_data(game_parts *game, char **map)
{
    while (*map != 0) {
        switch (**map) {
        case 'A':
            create_plane(game, *map);
            break;
        case 'T':
            create_tower(game, *map);
            break;
        default:
            break;
        }
        map++;
    }
}

int handle_file(game_parts *game, char *str)
{
    int f;
    char **map;

    f = open(str, O_RDONLY);
    if (f < 0)
        return 84;
    map = load_lines(str, 100);
    get_data(game, map);
    return 0;
}
