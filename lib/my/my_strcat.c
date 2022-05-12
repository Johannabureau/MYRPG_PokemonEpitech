/*
** EPITECH PROJECT, 2021
** strcat
** File description:
** concattrnates
*/

#include <stdlib.h>
int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;
    char *new = malloc(my_strlen(dest) + my_strlen(src) + 2);

    while (dest[i] != '\0') {
        new[i] = dest[i];
        i = i + 1;
    }
    while (src[j] != '\0') {
        new[i] = src[j];
        i = i + 1;
        j = j + 1;
    }
    new[i] = '\0';
    new[i + 1] = '\0';
    return (new);
}
