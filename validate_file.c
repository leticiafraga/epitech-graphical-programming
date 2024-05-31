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

static int validate_plane(char *str, file_cnt *cnt)
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
    if (it == 6)
        cnt->plane_cnt += 1;
    return (it == 6) ? 0 : 84;
}

static int validate_tower(char *str, file_cnt *cnt)
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
    if (it == 3)
        cnt->tower_cnt += 1;
    return (it == 3) ? 0 : 84;
}

static int it_map(char **map, file_cnt *cnt)
{
    int err = 0;

    switch (**map) {
        case 'A':
            err = validate_plane(*map, cnt);
            break;
        case 'T':
            err = validate_tower(*map, cnt);
            break;
        default:
            err = 84;
            break;
    }
    return err;
}

int validate_data(char **map, file_cnt *cnt)
{
    while (*map != 0) {
        if (it_map(map, cnt))
            return put_error_file_format();
        map++;
    }
    return 0;
}

file_cnt *init_cnt(void)
{
    file_cnt *cnt = malloc(sizeof(file_cnt));

    cnt->plane_cnt = 0;
    cnt->tower_cnt = 0;
    return cnt;
}

file_cnt *validate_file(char *str)
{
    int f = open(str, O_RDONLY);
    char **map;
    file_cnt *cnt = init_cnt();

    if (f < 0) {
        put_error_file();
        free(cnt);
        return 0;
    }
    map = load_lines(str, 3000);
    if (validate_data(map, cnt)) {
        free(cnt);
        cnt = 0;
    }
    close(f);
    return cnt;
}
