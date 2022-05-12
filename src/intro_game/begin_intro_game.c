/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-johanna.bureau
** File description:
** begin_intro_game
*/

#include "rpg.h"

int begin_intro_game(scene_t *scene, screen_t *screen, game_t *game)
{
    static bool init_intro_g = false;

    if (scene == NULL || screen == NULL || game == NULL)
        return 84;
    if (init_intro_g == false) {
        if (load_intro_g(scene, game) == 84)
            return 84;
        init_intro_g = true;
    }
    intro_g_handling(scene, game, screen);
    return 0;
}
