/*
** EPITECH PROJECT, 2021
** B-PSU-100-BDX-1-1-myprintf-leandre.godet
** File description:
** my_convert_base
*/
#include <stdarg.h>
#include "my.h"

void my_converting_base(char *base, unsigned int nbr)
{
    unsigned int tmp = nbr;
    unsigned int count = 1;
    int base_len = my_strlen(base);

    while (tmp > 0) {
        tmp = tmp / base_len;
        count = count * base_len;
    }
    tmp = nbr;
    count = count / base_len;
    while (count > 0) {
        tmp = tmp / count;
        my_putchar(base[tmp]);
        nbr = nbr - tmp * count;
        count = count / base_len;
        tmp = nbr;
    }
}

void my_converting_segond(char base, unsigned int nbr)
{
    if (base == 'X')
        my_converting_base("0123456789ABCDEF", nbr);
    if (base == 'u')
        my_converting_base("0123456789", nbr);
    if (base == 'b')
        my_converting_base("01", nbr);

}

void my_convert_main(char base, unsigned int nbr)
{
    void (*next_convert)(char base, unsigned int nbr);

    next_convert = &my_converting_segond;
    if (base == 'o')
        my_converting_base("01234567", nbr);
    if (base == 'x')
        my_converting_base("0123456789abcdef", nbr);
    next_convert(base, nbr);
}

int my_put_hashtag(char const *str, int i, va_list list)
{
    my_putchar('0');
    if (str[i + 1] == 'x' || str[i + 1] == 'X') {
        my_putchar(str[i + 1]);
    }
    my_print_first(i, str, list);
    return i;
}
