/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-johanna.bureau
** File description:
** switch_pkm
*/

#include <stdlib.h>
#include "rpg.h"

static int cpy_stat(pokemon_t *cpy, pokemon_t *pkm)
{
    if (cpy == NULL || pkm == NULL)
        return 84;
    for (int i = 0; i < 6; i++) {
        cpy->stat[i] = pkm->stat[i];
        cpy->f_stat[i] = pkm->f_stat[i];
        cpy->stat_level[i] = pkm->stat_level[i];
    }
    cpy->lv = pkm->lv;
    cpy->pdv = pkm->pdv;
    cpy->xp = pkm->xp;
    cpy->type[0] = pkm->type[0];
    cpy->type[1] = pkm->type[1];
    return 0;
}

static int cpy_atk(pokemon_t *cpy, pokemon_t *pkm)
{
    if (cpy == NULL || pkm == NULL)
        return 84;
    for (int i = 0; i < 4; i++) {
        cpy->atk[i].type = pkm->atk[i].type;
        cpy->atk[i].dmg = pkm->atk[i].type;
        cpy->atk[i].text = pkm->atk[i].text;
        cpy->atk[i].font = pkm->atk[i].font;
    }
    return 0;
}

static int cpy_rest(pokemon_t *cpy, pokemon_t *pkm)
{
    if (cpy == NULL || pkm == NULL)
        return 84;
    cpy->font = pkm->font;
    for (int i = 0; i < 4; i++)
        cpy->text[i] = pkm->text[i];
    cpy->texture = pkm->texture;
    cpy->sprite = pkm->sprite;
    cpy->index = pkm->index;
    cpy->name = pkm->name;
    cpy->object = pkm->object;
    return 0;
}

int switch_pkm(pokemon_t *pokemon_1, pokemon_t *pokemon_2)
{
    pokemon_t cpy;

    if (pokemon_1 == NULL || pokemon_2 == NULL)
        return 84;
    if (cpy_stat(&cpy, pokemon_1) == 84 || cpy_atk(&cpy, pokemon_1) == 84 ||
            cpy_rest(&cpy, pokemon_1) == 84)
        return 84;
    if (cpy_stat(pokemon_1, pokemon_2) == 84 ||
            cpy_atk(pokemon_1, pokemon_2) == 84 ||
            cpy_rest(pokemon_1, pokemon_2) == 84)
        return 84;
    if (cpy_stat(pokemon_2, &cpy) == 84 ||
            cpy_atk(pokemon_2, &cpy) == 84 ||
            cpy_rest(pokemon_2, &cpy) == 84)
        return 84;
    return 0;
}
