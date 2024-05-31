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

int put_error_file(void)
{
    my_put_err("./my_radar: bad arguments: file not found\n");
    return 84;
}

int put_error_file_format(void)
{
    my_put_err("./my_radar: bad arguments: error parsing file\n");
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

float radian_to_degree(float radian)
{
    return radian * (180 / M_PI);
}
