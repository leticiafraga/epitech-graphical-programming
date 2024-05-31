/*
** EPITECH PROJECT, 2023
** MY_PUTFLOAT
** File description:
** Function that displays the number given as a parameter
*/
#include <stdlib.h>
#include "../include/my.h"

static char *put_float(double nb, int precision)
{
    int intpart;
    char *floatpart = malloc(sizeof(char) * (precision + 2));
    int rest = 0;
    int i = 0;

    floatpart[0] = '.';
    for (i = 0; i < precision; i++) {
        nb = nb * 10;
        intpart = (int) nb;
        rest = (int) nb % 10;
        floatpart[i + 1] = (rest + '0');
    }
    floatpart[i + 1] = '\0';
    return floatpart;
}

char *join_str(char *intpart, char *floatpart)
{
    char *res;
    int len = my_strlen(intpart) + my_strlen(floatpart) - 1;

    res = malloc(sizeof(char) * len);
    res[0] = '\0';
    my_strcat(res, intpart);
    my_strcat(res, floatpart);
}

char *my_getfloat(double nb, int precision)
{
    char *intpart;
    char *floatpart;
    char *res;

    if (nb < 0) {
        nb = nb * -1;
    }
    if (precision < 0)
        precision = 6;
    intpart = my_nbrtostr((int) nb);
    if (precision != 0)
        floatpart = put_float(nb, precision);
    res = join_str(intpart, floatpart);
    free(intpart);
    free(floatpart);
    return res;
}
