/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-johanna.bureau
** File description:
** fight_handling
*/

#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/System/Clock.h>
#include "rpg.h"
#include "map.h"
#include "my.h"

static int check_error_f(game_t *game)
{
    if (game == NULL)
        return 84;
    if (game->start == NULL ||
            my_strcmp(game->start->pokemon_inv[0].name, "none") == 0 ||
            my_strcmp(game->enemy[0].name, "none") == 0)
        return 84;
    return 0;
}

static int select_status_f(scene_t *scene, game_t *game, screen_t *screen,
        int *status)
{
    if (scene == NULL || game == NULL || screen == NULL || status == NULL)
        return 84;
    if (game->your_turn == false)
        return 0;
    if (*status == FI_CHOICE)
        if (choose_option_f(game, scene, screen, status) == 84)
            return 84;
    if (*status == FI_ATK)
        if (choose_atk_f(game, scene, screen, status) == 84)
            return 84;
    if (*status == FI_POKEMON) {
        set_old_scene(FIGHT);
        screen->scene_type = MENU;
        status[0] = FI_CHOICE;
        set_index_menu(INV_MENU);
    }
    return 0;
}

    static int
set_clock_f(scene_t *scene, game_t *game, screen_t *screen, int *status)
{
    if (!scene || !scene->object || !scene->object[0] || !scene->object[0][0]
            || !scene->object[0][0]->clock)
        return 84;
    if (select_status_f(scene, game, screen, status) == 84)
        return 84;
    begin_ai(game);
    sfClock_restart(scene->object[0][0]->clock);
    return 0;
}

static int fight(scene_t *scene, game_t *game, screen_t *screen, int *status)
{
    int is_alive = 0;

    if (scene == NULL || game == NULL || screen == NULL || status == NULL)
        return 84;
    for (int i = 0; i < 6; i++)
        if (game->enemy[i].pdv > 0)
            is_alive++;
    if (set_clock_f(scene, game, screen, status) == 84)
        return 84;
    if (is_alive == 0) {
        game->start->pokemon_inv[0].xp += 20;
        if (game->start->pokemon_inv[0].xp >= 100) {
            game->start->pokemon_inv[0].xp = 0;
            game->start->pokemon_inv[0].lv += 1;
        }
        end_fight(scene, game, screen, true);
    }
    return 0;
}

    int fight_handling
(scene_t *scene, game_t *game, screen_t *screen)
{
    int is_alive_player = 0;
    static int status = FI_CHOICE;

    if (scene == NULL || game == NULL || screen == NULL)
        return 84;
    if (check_error_f(game) == 84)
        return 84;
    for (int i = 0; i < 6; i++)
        if (game->start->pokemon_inv[i].pdv > 0)
            is_alive_player++;
    if (is_alive_player == 0)
        return end_fight(scene, game, screen, false);
    fight(scene, game, screen, &status);
    draw_fight(scene, game, screen);
    return 0;
}
