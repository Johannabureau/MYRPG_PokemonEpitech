/*
** EPITECH PROJECT, 2022
** B-CPE-200-BDX-2-1-lemin-johanna.bureau
** File description:
** int_to_char
*/

#include <stdlib.h>
#include <stddef.h>

char *my_int_to_str(unsigned int score)
{
    char *str = NULL;
    int tmp = 1;
    int count = 2;
    int i = 0;

    if (score == 0)
        return "0";
    for (int temp = score; temp / tmp >= 1; count += 1)
        tmp *= 10;
    str = malloc(sizeof(char) * count);
    if (!str)
        return NULL;
    for (; i < count && tmp > 1; i++) {
        tmp /= 10;
        str[i] = score / tmp + '0';
        score %= tmp;
    }
    str[i] = '\0';
    return str;
}
