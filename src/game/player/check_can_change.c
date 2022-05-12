/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** check_can_change
*/

#include "map.h"
#include "rpg.h"

static bool check_in_pellet(scene_t *scene, game_t *game, screen_t *screen)
{
    float seconds = 0.00;

    if (!scene || !game || !screen)
        return false;
    scene->time = sfClock_getElapsedTime(scene->clock);
    seconds = scene->time.microseconds / 100000.0;
    if (game == NULL || scene == NULL)
        return false;
    if (game->as_a_pokemon == false && seconds > 0.5) {
        sfClock_restart(scene->clock);
        scene->vtc = (sfVector2f){0, 0};
        create_move(scene, screen);
        screen->scene_type = TEXT;
        scene->move = NO_MOVE_UP;
        scene->text = TEXT2;
    }
    return true;
}

static bool check_has_poke(scene_t *scene, game_t *game)
{
    if (scene->choose[2] || scene->choose[1] || scene->choose[0])
        game->as_a_pokemon = true;
    if (game->as_a_pokemon) {
        game->map[game->index][4][10] = 'X';
        game->map[game->index][4][11] = 'X';
        game->map[game->index][4][12] = 'X';
    }
    return true;
}

static bool check_in_lab(scene_t *scene, game_t *game)
{
    sfVector2f pos = sfSprite_getPosition(scene->object[1][0]->sprite);
    sfVector2i p = {pos.x / 64, pos.y / 64};
    sfVector2i new = {p.x + game->player_start.x, p.y + game->player_start.y};
    int err = 0;

    if (new.x == 10 && new.y == 4 && game->map[game->index][4][10] == 'O') {
        scene->choose[0] = true;
        err += read_poke_dir(&game->start->pokemon_inv[0], "1.tortipouss");
    }
    if (new.x == 11 && new.y == 4 && game->map[game->index][4][11] == 'O') {
        scene->choose[1] = true;
        err += read_poke_dir(&game->start->pokemon_inv[0], "4.salamèche");
    }
    if (new.x == 12 && new.y == 4 && game->map[game->index][4][12] == 'O') {
        scene->choose[2] = true;
        err += read_poke_dir(&game->start->pokemon_inv[0], "2.kaiminus");
    }
    check_has_poke(scene, game);
    return (err > 0) ? false : true;
}

bool check_pokemon(scene_t *scene, game_t *game, screen_t *screen)
{
    if (!scene || !game || !screen)
        return false;
    if (scene->index == PALLET_VIRIDIAN)
        return check_in_pellet(scene, game, screen);
    if (scene->index == OAK_LABORATORY && !game->as_a_pokemon)
        return check_in_lab(scene, game);
    return true;
}
