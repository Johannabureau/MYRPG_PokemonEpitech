/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** oak_lab
*/

#include "map.h"

bool change_to_oak(game_t *game, scene_t *scene)
{
    sfVector2i new;

    if (game == NULL || scene == NULL)
        return false;
    new = (sfVector2i){8 - game->player_pos.x, 11 - game->player_pos.y};
    game->index = LE_VIEUX_LA;
    scene->index = OAK_LABORATORY;
    game->player_start = new;
    return true;
}
