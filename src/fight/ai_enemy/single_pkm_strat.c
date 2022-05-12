/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-johanna.bureau
** File description:
** single_pkm_strat
*/

#include <math.h>
#include "rpg.h"

static int check_most_effi_atk(game_t *game)
{
    int atk = game->enemy[0].atk[0].dmg;
    int index_atk = 0;

    if (game == NULL)
        return 84;
    for (int i = 0; i < 4; i++) {
        if (game->enemy[0].atk[i].dmg == -1)
            break;
        if (atk < game->enemy[0].atk[0].dmg) {
            atk = game->enemy[0].atk[0].dmg;
            index_atk = i;
        }
    }
    game->start->pokemon_inv[0].pdv -= round(
            game->enemy[0].atk[index_atk].dmg + game->enemy[0].stat[S_ATK] /
            game->start->pokemon_inv[0].stat[S_DEF]);
    return 0;
}

static int check_if_decided(game_t *game, bool is_decided)
{
    if (game == NULL)
        return 84;
    if (is_decided == false)
        if (check_most_effi_atk(game) == 84)
            return 84;
    return 0;
}

int single_pkm_strat(game_t *game)
{
    bool is_decided = false;

    if (game == NULL)
        return 84;
    for (int i = 0; i < 4; i++) {
        if (game->enemy[0].atk[i].type == NONE)
            break;
        if (check_efficacity_f(game->start->pokemon_inv[0].type[0],
                    game->enemy[0].atk[i].type)) {
            is_decided = true;
            game->start->pokemon_inv[0].pdv -= round(
                    game->enemy[0].stat[S_ATK] +
                    game->enemy[0].atk[i].dmg * 2 /
                    game->start->pokemon_inv[0].stat[S_DEF]);
            break;
        }
    }
    if (check_if_decided(game, is_decided) == 84)
        return 84;
    return 0;
}
