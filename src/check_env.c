/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-johanna.bureau
** File description:
** check_env
*/

#include <stddef.h>
#include <stdbool.h>
#include "my.h"

int check_env(char **env)
{
    bool env_is_good = false;

    if (env == NULL)
        return 84;
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strcmp(env[i], "DISPLAY") == 0) {
            env_is_good = true;
        }
    }
    if (env_is_good == false)
        return 84;
    return 0;
}
