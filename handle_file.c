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

static int put_error_file(void)
{
    my_put_err("./my_radar: bad arguments: file not found\n");
    return 84;
}

static int handle_error(int f)
{
    close(f);
    return 84;
}

sfVector2i get_next_nb(char *str, int i)
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
        return put_error_file();
    map = load_lines(str, 100);
    get_data(game, map);
    close(f);
    return 0;
}

float radian_to_degree(float radian)
{
    return radian * (180 / M_PI);
}
