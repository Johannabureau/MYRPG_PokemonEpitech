/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-johanna.bureau
** File description:
** begin_ai
*/

#include "rpg.h"
#include <SFML/System/Clock.h>

static int check_what_pkm_is_alive(game_t *game, int i)
{
    if (game == NULL)
        return 84;
    if (game->enemy[i].pdv > 0)
        if (switch_pkm(&game->enemy[0], &game->enemy[i]) == 84)
            return 84;
    return 0;
}

static int check_if_first_pkm_die(game_t *game)
{
    if (game == NULL)
        return 84;
    if (game->enemy[0].pdv > 0)
        return 0;
    for (int i = 0; i < 6; i++) {
        if (check_what_pkm_is_alive(game, i) == 84)
            return 84;
    }
    return 0;
}

static int how_many_pkm(game_t *game)
{
    int nb_pkm = 0;

    if (game == NULL)
        return 84;
    for (int i = 0; i < 6; i++)
        if (game->enemy[i].lv != -1)
            nb_pkm++;
    if (nb_pkm == 0)
        return 84;
    if (check_if_first_pkm_die(game) == 84)
        return 84;
    if (nb_pkm > 1)
        multiple_pkm_strat(game);
    else
        single_pkm_strat(game);
    return 0;
}

static sfClock *init_clock()
{
    static int init_clock = 0;
    static sfClock *clock = NULL;

    if (init_clock == 0) {
        clock = sfClock_create();
        init_clock++;
    }
    return clock;
}

int begin_ai(game_t *game)
{
    static float second = 0.0;
    static sfTime time;
    static sfClock *clock = NULL;

    clock = init_clock();
    if (game == NULL || clock == NULL)
        return 84;
    if (game->your_turn == true)
        return 0;
    time = sfClock_getElapsedTime(clock);
    second = time.microseconds / 1000000.0;
    if (second > 0.5) {
        if (how_many_pkm(game) == 84)
            return 84;
        game->your_turn = true;
        sfClock_restart(clock);
        second = 0.0;
    }
    return 0;
}
