/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-johanna.bureau
** File description:
** main
*/

#include "rpg.h"

int main(int argc, char * const argv[], char **env)
{
    if (argc > 2 || env == NULL || check_env(env) == 84)
        return 84;
    else if (begin_rpg(argv[1]) == 84)
        return 84;
    return 0;
}
