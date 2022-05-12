/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** pokemon_center
*/

#include "map.h"

static bool change_to_upstaire(game_t *game, scene_t *scene)
{
    sfVector2i new;

    if (game == NULL || scene == NULL)
        return false;
    game->index = POKEMON_CENTER_UP;
    scene->index = VIRIDIAN_1;
    scene->move = NO_MOVE_RIGHT;
    new = (sfVector2i){3 - game->player_pos.x, 5 - game->player_pos.y};
    game->player_start = new;
    return true;
}

bool change_pokemon_center(scene_t *scene, game_t *game, char ch)
{
    if (ch == '1')
        return change_to_pallet(scene, game, ch);
    else if (ch == '2')
        return change_to_upstaire(game, scene);
    return true;
}

bool change_to_pc_down(game_t *game, scene_t *scene)
{
    sfVector2i new;

    if (game == NULL || scene == NULL)
        return false;
    game->index = POKEMON_CENTER;
    scene->index = VIRIDIAN_2;
    new = (sfVector2i){9 - game->player_pos.x, 7 - game->player_pos.y};
    game->player_start = new;
    return true;
}

bool from_pc_upstair(scene_t *scene, game_t *game, char ch)
{
    sfVector2i new;

    if (game == NULL || scene == NULL)
        return false;
    else if (ch != '1')
        return true;
    game->index = POKEMON_CENTER;
    scene->index = VIRIDIAN_2;
    scene->move = NO_MOVE_RIGHT;
    new = (sfVector2i){3 - game->player_pos.x, 5 - game->player_pos.y};
    game->player_start = new;
    return true;
}
