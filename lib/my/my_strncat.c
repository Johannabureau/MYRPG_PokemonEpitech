/*
** EPITECH PROJECT, 2021
** strcat
** File description:
** concattrnates
*/
#include <stdlib.h>
#include "my.h"

char *my_strncat(char *dest, char const *src, int n)
{
    int i = 0;
    int j = 0;
    char *new = malloc(my_strlen(dest) + n + 1);

    while (dest[i] != '\0') {
        new[i] = dest[i];
        i = i + 1;
    }
    while (i < n && src[i] != '\0') {
        new[i] = src[j];
        i = i + 1;
        j = j + 1;
    }
    new[i] = '\0';
    return (new);
}
