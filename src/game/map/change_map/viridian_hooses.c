/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** viridian_hooses
*/

#include "map.h"

bool change_to_pallet(scene_t *scene, game_t *game, char ch)
{
    if (game == NULL || scene == NULL)
        return false;
    else if (ch != '1')
        return true;
    game->index = MAP;
    scene->index = PALLET_VIRIDIAN;
    game->player_start = get_player_pos(game);
    return true;
}

bool change_to_hose3(game_t *game, scene_t *scene)
{
    sfVector2i new;

    if (game == NULL || scene == NULL)
        return false;
    new = (sfVector2i){5 - game->player_pos.x, 6 - game->player_pos.y};
    game->index = VIRIDIAN_HOOSE;
    scene->index = VIRIDIAN_4;
    game->player_start = new;
    return true;
}

bool change_to_hose4(game_t *game, scene_t *scene)
{
    sfVector2i new;

    if (game == NULL || scene == NULL)
        return false;
    new = (sfVector2i){5 - game->player_pos.x, 6 - game->player_pos.y};
    game->index = VIRIDIAN_SCOOL;
    scene->index = VIRIDIAN_5;
    game->player_start = new;
    return true;
}

bool change_to_arene(game_t *game, scene_t *scene)
{
    sfVector2i new;

    if (game == NULL || scene == NULL)
        return false;
    new = (sfVector2i){8 - game->player_pos.x, 9 - game->player_pos.y};
    game->index = ARENE;
    scene->index = VIR_ARENE;
    game->player_start = new;
    return true;
}
