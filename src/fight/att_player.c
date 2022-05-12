/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-johanna.bureau
** File description:
** att_player
*/

#include <math.h>
#include "rpg.h"

int atk_player(game_t *game, atk_t *atk)
{
    if (game == NULL || game->start == NULL || atk == NULL)
        return 84;
    if (check_efficacity_f(game->enemy[0].type[0], atk->type) == true)
        game->enemy[0].pdv -= round(game->start->pokemon_inv[0].stat[S_ATK]
                + atk->dmg * 2 /
                game->enemy[0].stat[S_DEF]);
    else
        game->enemy[0].pdv -= round(game->start->pokemon_inv[0].stat[S_ATK]
                + atk->dmg / game->enemy[0].stat[S_DEF]);
    return 0;
}
