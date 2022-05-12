/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** move_player_up
*/

#include "map.h"

bool move_player_left(scene_t *scene, game_t *game, sfVector2i p, screen_t *s)
{
    char current = 0;

    if (game == NULL || scene == NULL || !game->map[game->index][p.y])
        return false;
    current = game->map[game->index][p.y][p.x - 1];
    switch (current) {
        case 'C':
        case 'X':
            scene->vtc = (sfVector2f){0, 0};
            break;
        case 'O':
            return check_pokemon(scene, game, s);
        default:
            return change_map(scene, game, current);
    }
    return true;
}
