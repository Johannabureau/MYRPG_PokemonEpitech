/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** free_map
*/

#include "map.h"
#include "rpg.h"
#include "my.h"

int destroy_map(game_t *game)
{
    int i = 0;

    if (!game || !game->map)
        return 0;
    while (game->map[i] != NULL) {
        free_tab(game->map[i]);
        i++;
    }
    return 0;
}
