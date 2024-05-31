/*
** EPITECH PROJECT, 2023
** load_2d_arr_from_file
** File description:
** load_2d_arr_from_file
*/
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "include/my.h"

char *read_line(int f, int nb_cols)
{
    char c;
    char *str = malloc(sizeof(char) * nb_cols);
    int i = 0;
    int n;

    n = read(f, &c, 1);
    while (c != '\0' && c != '\n' && n > 0 && i < nb_cols) {
        str[i] = c;
        n = read(f, &c, 1);
        i++;
    }
    str[i] = '\0';
    if (i == 0) {
        free(str);
        return 0;
    }
    return str;
}

char **load_lines(char const *filepath, int nb_rows)
{
    int fd = open(filepath, O_RDONLY);
    char str[30001];
    char **res = malloc(sizeof(char *) * 30001);
    int len;
    int r;
    int nb_cols = 100;

    if (fd < 0)
        return 0;
    for (int i = 0; i < nb_rows; i++) {
        res[i] = read_line(fd, nb_cols);
        if (res[i] == 0)
            break;
    }
    close(fd);
    return res;
}
