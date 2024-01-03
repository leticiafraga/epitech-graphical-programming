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

static void get_next_nb(char **str)
{
    char *new = *str;
    int n = 0;
    int found = 0;

    while (*new != '\0') {
        if (is_number(*new) && found == 1)
            continue;
        if (!is_number(*new) && found == 1)
            break;
        if (is_number(*new)) {
            n = my_getnbr(new);
            found = 1;
        }
        new++;
    }
    str = &new;
}

static void create_plane(game_parts *game, char *str)
{
    while (*str != '\0') {
        get_next_nb(&str);
        str++;
    }
}

static void create_tower(game_parts *game, char *str)
{
    while (*str != '\0') {
        get_next_nb(&str);
        str++;
    }
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
