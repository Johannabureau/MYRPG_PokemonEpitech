/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** return the lenth of the str
*/
#include <stdio.h>

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 0;
    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}
