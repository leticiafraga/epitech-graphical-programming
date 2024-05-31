/*
** EPITECH PROJECT, 2023
** MY_PUT_NBR
** File description:
** Function that displays the number given as a parameter
*/
#include "../include/my.h"

static long int get_next(long int nb)
{
    long int next = nb % 10;
    int cnt = 0;

    nb = nb / 10;
    if (nb != 0) {
        cnt += get_next(nb);
    }
    cnt++;
    my_putchar(next + '0');
    return cnt;
}

int my_put_nbr(int nb)
{
    long int lg = nb;
    int cnt = 0;

    if (lg < 0) {
        my_putchar('-');
        cnt++;
        lg = lg * -1;
    }
    cnt += get_next(lg);
    return cnt;
}
