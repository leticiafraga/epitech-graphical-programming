/*
** EPITECH PROJECT, 2023
** MY
** File description:
** My lib header
*/

#ifndef MY_H
    #define MY_H
char *my_nbrtostr(int nb);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int mini_printf(const char *format, ...);
char *my_revstr(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
int is_number(char c);
int my_getnbr(char const *str);
char *my_getfloat(double nb, int precision);
void my_put_err(char *str);

#endif
