/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-johanna.bureau
** File description:
** move_main_char
*/

#include "move_main_char.h"

static void move_sp(scene_t *i)
{
    DRAW_SP_MOVE(i->object[1][RIGHT]);
    DRAW_SP_MOVE(i->object[1][LEFT]);
    DRAW_SP_MOVE(i->object[1][DOWN]);
    DRAW_SP_MOVE(i->object[1][UP]);
    DRAW_SP_MOVE(i->object[1][NO_MOVE_RIGHT]);
    DRAW_SP_MOVE(i->object[1][NO_MOVE_LEFT]);
    DRAW_SP_MOVE(i->object[1][NO_MOVE_DOWN]);
    DRAW_SP_MOVE(i->object[1][NO_MOVE_UP]);
}

void create_move(scene_t *i, screen_t *screen)
{
    sfVector2f pos = sfView_getCenter(screen->view);
    sfVector2f new = {pos.x + i->vtc.x, pos.y + i->vtc.y};

    i->time = sfClock_getElapsedTime(i->clock);
    if (i->time.microseconds / 10000 > 5 && screen->scene_type == GAME) {
        sfClock_restart(i->clock);
        move_sp(i);
        PIX_MOVE(screen->fb);
        PIX_MOVE(i->object[2][3]);
        MOVE_TEXT(i->object[3][0]);
        MOVE_TEXT(i->object[3][1]);
        MOVE_TEXT(i->object[3][2]);
        MOVE_TEXT(i->object[3][3]);
        sfView_setCenter(screen->view, new);
    }
    return;
}

void move_main_char_right(scene_t *i, screen_t *screen)
{
    if (screen->event.key.code == sfKeyRight) {
        i->vtc = (sfVector2f){.x = 12, .y = 0};
        i->move = RIGHT;
    }
    if (screen->event.key.code == sfKeyLeft) {
        i->vtc = (sfVector2f){.x = -12, .y = 0};
        i->move = LEFT;
    }
    if (screen->event.key.code == sfKeyDown) {
        i->vtc = (sfVector2f){.x = 0, .y = 12};
        i->move = DOWN;
    }
    if (screen->event.key.code == sfKeyUp) {
        i->vtc = (sfVector2f){.x = 0, .y = -12};
        i->move = UP;
    }
    return;
}

void no_move_main_char(scene_t *all, screen_t *screen)
{
    if (screen->event.key.code == sfKeyRight) {
        all->vtc = (sfVector2f){.x = 0, .y = 0};
        all->move = NO_MOVE_RIGHT;
    }
    if (screen->event.key.code == sfKeyLeft) {
        all->vtc = (sfVector2f){.x = 0, .y = 0};
        all->move = NO_MOVE_LEFT;
    }
    if (screen->event.key.code == sfKeyDown) {
        all->vtc = (sfVector2f){.x = 0, .y = 0};
        all->move = NO_MOVE_DOWN;
    }
    if (screen->event.key.code == sfKeyUp) {
        all->vtc = (sfVector2f){.x = 0, .y = 0};
        all->move = NO_MOVE_UP;
    }
    return;
}
