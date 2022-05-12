/*
** EPITECH PROJECT, 2022
** Lib
** File description:
** str_count
*/

#include <stddef.h>
#include <stdlib.h>

int count_words(char const *str)
{
    int j = 0;

    if (str == NULL)
        return 0;
    for (int i = 0; str[i] != '\0' && str[i + 1] != '\0'; i++) {
        if (str[i] == '\n' && str[i + 1] != '\n') {
            j += 1;
        }
    }
    return j + 1;
}

int count_letters(char const *str, int i)
{
    int j = 0;

    for (; str[i] != '\n' && str[i] != '\0'; i += 1)
        j += 1;
    return j;
}

int len_array(char **array)
{
    int j = 0;

    while (array[j] != NULL) {
        j += 1;
    }
    return j;
}
