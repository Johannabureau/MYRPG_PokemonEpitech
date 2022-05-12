/*
** EPITECH PROJECT, 2022
** Lib
** File description:
** str_to_word
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int my_strlen(char *str);
int len_array(char **aray);
int count_words(char *str);
int count_letters(char *str, int i);
char *my_strcat(char *dest, char const *src);

char **put_word_in_array(char *str, char **array, int i)
{
    int nb_letter = count_letters(str, i) + 5;
    int j = len_array(array);
    int k = 0;

    if (str == NULL || array == NULL)
        return NULL;
    array[j] = malloc(sizeof(char) * nb_letter);
    for (; str[i] != '\n' && str[i] != '\0'; k++) {
        array[j][k] = str[i];
        i++;
    }
    array[j][k] = '\0';
    return array;
}

int add_last_arr(char *str, char **array, int i)
{
    int j = len_array(array) - 1;

    if (str == NULL || array == NULL)
        return -1;
    i = i + my_strlen(array[j]);
    while (str[i] == '\n')
        i++;
    return i;
}

char *replace_new_line(char *new)
{
    char *str = NULL;

    if (new == NULL)
        return NULL;
    str = my_strcat(new, "\0");
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n' || str[i] == '\r' || str[i] == '\t') {
            str[i] = '\n';
        }
    }
    return str;
}

char **my_str_to_word_array(char *new)
{
    char *str = replace_new_line(new);
    int nb_words = count_words(str) + 5;
    char **array = malloc(sizeof(char *) * nb_words);
    int i = 0;

    if (str == NULL)
        return NULL;
    for (int j = 0; j < nb_words; j++) {
        array[j] = NULL;
    }
    while (str[i] == '\n' || str[i] == '\t')
        i++;
    while (str[i] != '\0') {
        array = put_word_in_array(str, array, i);
        i = add_last_arr(str, array, i);
    }
    return array;
}
