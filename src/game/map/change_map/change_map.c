/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** change_map
*/

#include "map.h"

static bool change_pallet(scene_t *scene, game_t *game, char ch)
{
    int all[] = {'1', '2', '3', '4', '5', '6', '7', '8', -1};
    bool (*change_to[])(game_t *, scene_t *) = {change_to_ash_hoose,
        change_to_rival, change_to_oak, change_to_pc_down, change_to_mart,
        change_to_hose3, change_to_hose4, change_to_arene, NULL};
    int index = 0;

    if (game == NULL || scene == NULL)
        return false;
    while (all[index] != -1 && all[index] != ch)
        index += 1;
    if (all[index] != -1)
        return change_to[index](game, scene);
    return true;
}

bool change_map(scene_t *scene, game_t *game, char ch)
{
    pallet_viridian_e all[] = {MAP, START_HOUSE, CHAMBER_START,
        LE_VIEUX_LA, RIVAL_HOUSE, POKEMON_CENTER, POKEMON_CENTER_UP,
        MART_POKEMON, VIRIDIAN_SCOOL, VIRIDIAN_HOOSE, ARENE, END_ENUM};
    bool (*change_to[])(scene_t *, game_t *, char) = {change_pallet,
        change_map_hosse_ash, from_upstair, change_to_pallet, change_to_pallet,
        change_pokemon_center, from_pc_upstair, change_to_pallet,
        change_to_pallet, change_to_pallet, change_to_pallet, NULL};
    int index = 0;

    if (game == NULL || scene == NULL)
        return false;
    while (all[index] != END_ENUM && all[index] != game->index)
        index += 1;
    if (all[index] != END_ENUM)
        return change_to[index](scene, game, ch);
    return true;
}
