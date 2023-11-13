/*
** EPITECH PROJECT, 2023
** my_nbrtostr
** File description:
** Function that return the number given as a string
*/
#include <stdlib.h>
#include "../include/my.h"

static char *get_next(long int nb)
{
    long int next = nb % 10;
    char *str = malloc(sizeof(char) * 11);
    int cnt = 0;

    while (nb != 0) {
        nb = nb / 10;
        str[cnt] = (next + '0');
        next = nb % 10;
        cnt++;
    }
    str[cnt] = '\0';
    return my_revstr(str);
}

char *my_nbrtostr(int nb)
{
    long int lg = nb;

    if (lg < 0) {
        lg = lg * -1;
    }
    return get_next(lg);
}
