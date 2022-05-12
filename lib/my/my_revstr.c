/*
** EPITECH PROJECT, 2021
** revstr
** File description:
** return reversed str
*/
#include <stdio.h>

int my_strlen(char const *str);

void my_swap2(char *a, char *b)
{
    char c = *a;

    *a = *b;
    *b = c;
}

char *my_revstr(char *str)
{
    int i = 0;
    int len_str = my_strlen(str);

    while (i != (len_str) / 2 ) {
        my_swap2(&str[len_str - i - 1], &str[i]);
        i = i + 1;
    }
    str[len_str] = '\0';
    return (str);
}
