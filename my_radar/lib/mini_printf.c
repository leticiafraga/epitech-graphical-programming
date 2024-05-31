/*
** EPITECH PROJECT, 2023
** MINI_PRINTF
** File description:
** Mini printf
*/

#include <stdarg.h>
#include "../include/my.h"

static int get_format(const char *format, va_list args)
{
    switch (*format) {
    case '%':
        my_putchar('%');
        return 1;
    case 'd':
        return my_put_nbr(va_arg(args, int));
    case 'i':
        return my_put_nbr(va_arg(args, int));
    case 's':
        return my_putstr(va_arg(args, char *));
    case 'c':
        my_putchar(va_arg(args, int));
        return 1;
    case '\0':
        return -1;
    default:
        my_putchar('%');
        my_putchar(*format);
        return 2;
    }
}

int mini_printf(const char *format, ...)
{
    va_list args;
    int cnt = 0;
    int res = 0;

    va_start(args, format);
    while (*format != '\0') {
        if (*format == '%') {
            format++;
            res = get_format(format, args);
            cnt += res;
        } else {
            my_putchar(*format);
            cnt++;
        }
        format++;
        if (res < 0)
            return res;
    }
    va_end(args);
    return cnt;
}
