/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-johanna.bureau
** File description:
** init_inv
*/

#include "rpg.h"

int init_inv(inv_t *inv)
{
    char * const pokeball[4] =
    {"pokeball", "super ball", "hyper ball", "master ball"};
    char * const ct[4] =
    {"coupe", "force", "vol", "surf"};
    char * const special[4] =
    {"canne", "velo", "super canne", "mega canne"};

    if (inv == NULL)
        return 84;
    for (int i = 0; i < 4; i++) {
        inv->pokeball[i].nb = 0;
        inv->pokeball[i].name = pokeball[i];
        inv->special[i].nb = 0;
        inv->special[i].name = special[i];
        inv->ct[i].nb = 0;
        inv->ct[i].name = ct[i];
    }
    return 0;
}
