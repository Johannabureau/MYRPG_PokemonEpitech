/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-leandre.godet
** File description:
** my_freetab
*/
#include <stdlib.h>

void free_tab(char **tab)
{
    int i = 0;

    if (tab == NULL)
        return;
    while (tab[i]) {
        free(tab[i]);
        i += 1;
    }
    free(tab);
}
