/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** get_player_pos
*/

#include "map.h"

static sfVector2i get_player_pos_y(int y, char **map)
{
    for (int x = 0; map[y][x] != '\0'; x++) {
        if (map[y][x] == 'P') {
            return ((sfVector2i){.x = x, .y = y});
        }
    }
    return ((sfVector2i){-1, -1});
}

sfVector2i get_player_pos(game_t *game)
{
    char **map = game->map[0];
    sfVector2i tmp;

    for (int i = 0; map[i] != NULL; i++) {
        tmp = get_player_pos_y(i, map);
        if (tmp.x != -1 && tmp.y != -1)
            return tmp;
    }
    return ((sfVector2i){-1, -1});
}
