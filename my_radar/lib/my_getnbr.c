/*
** EPITECH PROJECT, 2023
** MY_GETNBR
** File description:
** Returns a number, sent to the function as a string
*/
#include "../include/my.h"

static int validate(char c)
{
    if (c >= '0' && c <= '9') {
        return 1;
    }
    return 0;
}

static int transform(char const *nbr, int len, int neg)
{
    long int result = 0;

    for (int i = 0; i < len; i++) {
        result = result * 10;
        result += (nbr[i] - '0');
        if ((neg == 1 && result > 2147483647)
            || (neg == -1 && result > 2147483648)) {
            return 0;
        }
    }
    if (neg == -1 && nbr[0] != '0') {
        result = result * -1;
    }
    return result;
}

int my_getnbr(char const *str)
{
    char c;
    int i = 0;
    int valid = 1;

    while (str[i] != '\0' && valid != 0) {
        valid = validate(str[i]);
        i ++;
        if (valid == 0)
            break;
    }
    return transform(str, i, 1);
}
