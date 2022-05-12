/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** move_map_spite
*/

#include <stdlib.h>
#include "map.h"

static bool check_map(game_t *game, sfVector2i pos)
{
    int index = game->index;

    if (!game || !game->map || !game->map[game->index])
        return false;
    for (index = 0; index < pos.y; index++) {
        if (!game->map[game->index][index])
            return false;
    }
    return true;
}

bool call_move_player(scene_t *scene, game_t *game, sfVector2i p, screen_t *s)
{
    int index = game->index;

    if (!game || !game->map || !game->map[index] || !check_map(game, p))
        return false;
    switch (scene->move) {
        case UP:
            return move_player_up(scene, game, p, s);
        case DOWN:
            return move_player_down(scene, game, p, s);
        case RIGHT:
            return move_player_right(scene, game, p, s);
        case LEFT:
            return move_player_left(scene, game, p, s);
        default:
            return true;
    }
    return true;
}

bool mouve_player_in_map(scene_t *scene, game_t *game, screen_t *screen)
{
    sfVector2f pos = sfSprite_getPosition(scene->object[1][0]->sprite);
    int posx = pos.x / 62;
    int posy = pos.y / 64;
    sfVector2i new = {0, 0};

    game->player_pos.x = posx;
    game->player_pos.y = posy;
    new.x = posx + game->player_start.x;
    new.y = posy + game->player_start.y;
    if (!call_move_player(scene, game, new, screen))
        return false;
    return true;
}
