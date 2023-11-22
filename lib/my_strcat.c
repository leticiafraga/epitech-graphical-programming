/*
** EPITECH PROJECT, 2023
** my_strcat
** File description:
** my_strcat
*/
#include "../include/my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int len = my_strlen(dest);

    while (src[i] != '\0') {
        dest[len] = src[i];
        len++;
        i++;
    }
    dest[len] = '\0';
    return dest;
}
