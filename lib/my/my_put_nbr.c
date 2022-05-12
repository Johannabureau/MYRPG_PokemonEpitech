/*
** EPITECH PROJECT, 2021
** put_nbr
** File description:
** displays the number
*/
#include "my.h"

int my_put_nbr(int nb)
{
    int count = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb >= 10) {
        count = nb % 10;
        nb = (nb - count) / 10;
        my_put_nbr(nb);
        my_putchar(count + 48);
    } else {
        my_putchar(nb + 48);
    }
    return 0;
}
