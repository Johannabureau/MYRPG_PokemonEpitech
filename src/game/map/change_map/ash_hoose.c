/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** ash_hoose
*/

#include "map.h"

bool change_to_ash_hoose(game_t *game, scene_t *scene)
{
    if (game == NULL || scene == NULL)
        return false;
    game->index = START_HOUSE;
    scene->index = START_SALON;
    game->player_start = (sfVector2i){3, 7};
    return true;
}

bool from_upstair(scene_t *scene, game_t *game, char ch)
{
    if (game == NULL || scene == NULL)
        return false;
    else if (ch != '1')
        return true;
    game->index = START_HOUSE;
    scene->index = START_SALON;
    game->player_start = (sfVector2i){3, 7};
    return true;
}
