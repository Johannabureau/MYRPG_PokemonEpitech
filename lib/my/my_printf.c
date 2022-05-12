/*
** EPITECH PROJECT, 2021
** B-PSU-100-BDX-1-1-myprintf-leandre.godet
** File description:
** my_printf
*/
#include <stdarg.h>
#include "my.h"

int my_print_segond(int i, const char *str, va_list list)
{
    if (str[i] == 'b' || str[i] == 'u')
        my_convert_main(str[i], va_arg(list, unsigned int));
    if (str[i] == '%')
        my_putchar(str[i]);
    if (str[i] == '#') {
        i = my_put_hashtag(str, i, list) + 1;
    }
    return i;
}

int my_print_first(int i, const char *str, va_list list)
{
    int (*flag_step_2)(int i, const char *str, va_list list);

    i += 1;
    flag_step_2 = &my_print_segond;
    if (str[i] == 'i' || str[i] == 'd')
        my_put_nbr(va_arg(list, int));
    if (str[i] == 'x' || str[i] == 'X' || str[i] == 'o')
        my_convert_main(str[i], va_arg(list, unsigned int));
    if (str[i] == 'c')
        my_putchar(va_arg(list, int));
    return flag_step_2(i, str, list);
}

void my_printf(const char *str, ...)
{
    va_list list;
    int i = 0;

    va_start(list, str);
    while (str[i] != '\0') {
        if (str[i] != '%') {
            my_putchar(str[i]);
        } else if (str[i + 1] == 's') {
            my_putstr(va_arg(list, char *));
            i += 1;
        } else
            i = my_print_first(i, str, list);
        i += 1;
    }
}
