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

static int validate_plane(char *str)
{
    sfVector2i result;
    int i = 0;
    int it = 0;
    int info[6];

    while (str[i] != '\0' && it < 6) {
        if (is_number(str[i])) {
            result = get_next_nb(str, i);
            i = result.x;
            info[it] = result.y;
            it++;
        } else
            i++;
    }
    return (it == 6) ? 0 : 84;
}

static int validate_tower(char *str)
{
    sfVector2i result;
    int i = 0;
    int it = 0;
    int info[3];

    while (str[i] != '\0' && it < 3) {
        if (is_number(str[i])) {
            result = get_next_nb(str, i);
            i = result.x;
            info[it] = result.y;
            it++;
        } else
            i++;
    }
    return (it == 3) ? 0 : 84;
}

int validate_data(char **map)
{
    int err = 0;

    while (*map != 0) {
        switch (**map) {
            case 'A':
                err = validate_plane(*map);
                break;
            case 'T':
                err = validate_tower(*map);
                break;
            default:
                err = 84;
                break;
        }
        map++;
        if (err)
            return put_error_file_format();
    }
    return 0;
}

int validate_file(char *str)
{
    int f;
    char **map;
    int res = 0;

    f = open(str, O_RDONLY);
    if (f < 0)
        return put_error_file();
    map = load_lines(str, 100);
    if (validate_data(map))
        res = 84;
    close(f);
    return res;
}
