/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** change_ash_hose
*/

#include "map.h"

static bool change_to_upstaire(game_t *game, scene_t *scene)
{
    sfVector2i new;

    if (game == NULL || scene == NULL)
        return false;
    new = (sfVector2i){11 - game->player_pos.x, 2 - game->player_pos.y};
    game->index = CHAMBER_START;
    scene->index = START_CHAMBER;
    game->player_start = new;
    return true;
}

bool change_map_hosse_ash(scene_t *scene, game_t *game, char ch)
{
    if (ch == '1')
        return change_to_pallet(scene, game, ch);
    else if (ch == '2')
        return change_to_upstaire(game, scene);
    return true;
}
