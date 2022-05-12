/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-johanna.bureau
** File description:
** check_efficacity_f
*/

#include "rpg.h"

static bool check_normal_to_ghost(int def, int atk)
{
    if (def == NORMAL && atk == FIGHTING)
        return true;
    if (def == FIGHTING && (atk == FLYING || atk == PSY))
        return true;
    if (def == FLYING && (atk == ROCK || atk == ELECTRIC || atk
                == ICE))
        return true;
    if (def == POISON && (atk == GROUND || atk == POISON))
        return true;
    if (def == GROUND && (atk == WATER || atk == GRASS || atk == ICE))
        return true;
    if (def == ROCK && (atk == GROUND || atk == WATER || atk == GRASS
                || atk == FIGHTING || atk == STEEL))
        return true;
    if (def == BUG && (atk == FIRE || atk == ROCK || atk == FLYING))
        return true;
    if (def == GHOST && (atk == GHOST || atk == DARK))
        return true;
    return false;
}

static bool check_steel_to_dark(int def, int atk)
{
    if (def == STEEL && (atk == FIRE || atk == GROUND || atk == FIGHTING))
        return true;
    if (def == FIRE && (atk == WATER || atk == GROUND || atk == ROCK))
        return true;
    if (def == WATER && (atk == ELECTRIC || atk == GRASS))
        return true;
    if (def == GRASS && (atk == FIRE || atk == ICE || atk == POISON ||
                atk == FLYING || atk == BUG))
        return true;
    if (def == ELECTRIC && atk == ELECTRIC)
        return true;
    if (def == PSY && (atk == GHOST || atk == BUG || atk == DARK))
        return true;
    if (def == ICE && (atk == FIRE || atk == FIGHTING || atk == ROCK ||
                atk == STEEL))
        return true;
    if (def == DARK && (atk == FIGHTING || atk == BUG))
        return true;
    return false;
}

bool check_efficacity_f(int def, int atk)
{
    if (check_normal_to_ghost(def, atk))
        return true;
    if (check_steel_to_dark(def, atk))
        return true;
    return false;
}
