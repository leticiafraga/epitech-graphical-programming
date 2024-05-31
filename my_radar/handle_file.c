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
#include <math.h>
#include "include/my.h"
#include "include/radar.h"

static int handle_error(int f)
{
    close(f);
    return 84;
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
            put_error_file_format();
            return 84;
        }
        map++;
    }
    return 0;
}

int handle_file(game_parts *game, char *str, file_cnt* cnt)
{
    int f;
    char **map;
    int res = 0;

    f = open(str, O_RDONLY);
    if (f < 0)
        return put_error_file();
    map = load_lines(str, cnt->plane_cnt + cnt->tower_cnt + 1);
    if (get_data(game, map))
        res = 84;
    close(f);
    return res;
}
