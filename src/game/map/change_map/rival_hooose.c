/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** rival_hooose
*/

#include "map.h"

bool change_to_rival(game_t *game, scene_t *scene)
{
    sfVector2i new;

    if (game == NULL || scene == NULL)
        return false;
    new = (sfVector2i){5 - game->player_pos.x, 6 - game->player_pos.y};
    game->index = RIVAL_HOUSE;
    scene->index = RIVAL_SALON;
    game->player_start = new;
    return true;
}
