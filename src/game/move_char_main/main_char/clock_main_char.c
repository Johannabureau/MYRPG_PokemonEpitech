/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-johanna.bureau
** File description:
** clock_main_char
*/

#include "move_main_char.h"

void clock_left_right(scene_t *all)
{
    float seg = all->object[1][LEFT]->time.microseconds / 100000;

    if (seg > 0.2) {
        sfClock_restart(all->object[1][LEFT]->clock);
        if (all->object[1][LEFT]->rect.left >= 16)
            all->object[1][LEFT]->rect.left = 0;
        else
            all->object[1][LEFT]->rect.left += 20;
    }
    seg = all->object[1][RIGHT]->time.microseconds / 100000;
    if (seg> 0.2) {
        sfClock_restart(all->object[1][RIGHT]->clock);
        if (all->object[1][RIGHT]->rect.left >= 16)
            all->object[1][RIGHT]->rect.left = 0;
        else
            all->object[1][RIGHT]->rect.left += 20;
    }
    return;
}

void clock_down_up(scene_t *all)
{
    float seg = all->object[1][DOWN]->time.microseconds / 100000;

    if (seg > 0.2) {
        sfClock_restart(all->object[1][DOWN]->clock);
        if (all->object[1][DOWN]->rect.left >= 16)
            all->object[1][DOWN]->rect.left = 0;
        else
            all->object[1][DOWN]->rect.left += 20;
    }
    seg = all->object[1][UP]->time.microseconds / 100000;
    if (seg > 0.2) {
        sfClock_restart(all->object[1][UP]->clock);
        if (all->object[1][UP]->rect.left >= 16)
            all->object[1][UP]->rect.left = 0;
        else
            all->object[1][UP]->rect.left += 20;
    }
    return;
}
