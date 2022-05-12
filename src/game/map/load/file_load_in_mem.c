/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** file_load_in_mem
*/

#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include "map.h"
#include "rpg.h"
#include "my.h"

static void my_memset(char *str, int len)
{
    for (int i = 0; i < len; i++)
        str[i] = '\0';
    return;
}

static int count_nb_line(char *file)
{
    int count = 0;

    if (file == NULL)
        return -1;
    for (int index = 0; file[index] != '\0'; index += 1) {
        if (file[index] == '\n')
            count += 1;
    }
    return count + 1;
}

static int count_line(char *line)
{
    int count = 0;

    if (line == NULL)
        return -1;
    for (int index = 0; line[index] != '\0' && line[index] != '\n'; index += 1)
        count += 1;
    return count;
}

char **my_load_inmem_array(char *file)
{
    int nb_line = count_nb_line(file);
    char **tab = malloc(sizeof(char *) * nb_line);
    int index = 0;
    int tmp = 0;

    if (nb_line < 0 || !file || !tab)
        return NULL;
    for (int index_line = 0; index_line < nb_line - 1; index_line += 1) {
        tmp = count_line(file + index);
        tab[index_line] = malloc(sizeof(char) * tmp + 1);
        my_memset(tab[index_line], tmp + 1);
        tab[index_line] = my_strncpy(tab[index_line], file + index, tmp);
        tmp += 1;
        index += tmp;
    }
    tab[nb_line - 1] = NULL;
    return tab;
}
