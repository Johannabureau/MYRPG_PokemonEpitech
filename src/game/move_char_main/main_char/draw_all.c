/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-johanna.bureau
** File description:
** draw_all
*/

#include "move_main_char.h"
#include "rpg.h"
#include "map.h"

int create_sprites_peoples(scene_t *all, game_t *game)
{
    all->object[1] = malloc(sizeof(game_object_t *) * 9);
    all->object[1][LEFT] = sprite_main_char_left(game);
    all->object[1][RIGHT] = sprites_main_char_right(game);
    all->object[1][DOWN] = sprites_main_char_dow(game);
    all->object[1][UP] = sprites_main_char_up(game);
    all->object[1][NO_MOVE_RIGHT] = sprite_main_char_no_walk_r(game);
    all->object[1][NO_MOVE_LEFT] = sprite_main_char_no_walk_l(game);
    all->object[1][NO_MOVE_DOWN] = sprite_main_char_no_walk_d(game);
    all->object[1][NO_MOVE_UP] = sprite_main_char_no_walk_u(game);
    all->object[1][8] = NULL;
    all->move = NO_MOVE_LEFT;
    return 0;
}

void sprites_rect(scene_t *all)
{
    SPSET_TEXRECT(all->object[1][UP], all->object[1][UP]);
    SPSET_TEXRECT(all->object[1][DOWN], all->object[1][DOWN]);
    SPSET_TEXRECT(all->object[1][LEFT], all->object[1][LEFT]);
    SPSET_TEXRECT(all->object[1][RIGHT], all->object[1][RIGHT]);
    return;
}

void draw_move_sprite(sfRenderWindow *win, scene_t *all)
{
    if (all->move == RIGHT)
        DRAW_SP_WIN(all->object[1][RIGHT]);
    if (all->move == NO_MOVE_RIGHT)
        DRAW_SP_WIN(all->object[1][NO_MOVE_RIGHT]);
    if (all->move == LEFT)
        DRAW_SP_WIN(all->object[1][LEFT]);
    if (all->move == DOWN)
        DRAW_SP_WIN(all->object[1][DOWN]);
    if (all->move == UP)
        DRAW_SP_WIN(all->object[1][UP]);
    if (all->move == NO_MOVE_LEFT)
        DRAW_SP_WIN(all->object[1][NO_MOVE_LEFT]);
    if (all->move == NO_MOVE_DOWN)
        DRAW_SP_WIN(all->object[1][NO_MOVE_DOWN]);
    if (all->move == NO_MOVE_UP)
        DRAW_SP_WIN(all->object[1][NO_MOVE_UP]);
    return;
}

void draw_sprites_peoples(scene_t *all, sfRenderWindow *win)
{
    sprites_rect(all);
    all->object[1][DOWN]->time = COLCK_ELAPSE(all->object[1][DOWN]->clock);
    all->object[1][UP]->time = COLCK_ELAPSE(all->object[1][UP]->clock);
    all->object[1][RIGHT]->time = COLCK_ELAPSE(all->object[1][RIGHT]->clock);
    all->object[1][LEFT]->time = COLCK_ELAPSE(all->object[1][LEFT]->clock);
    clock_left_right(all);
    clock_down_up(all);
    draw_move_sprite(win, all);
}
