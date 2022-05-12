/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-johanna.bureau
** File description:
** begin_fight
*/

#include "rpg.h"

int begin_fight(scene_t *scene, screen_t *screen, game_t *game)
{
    static bool init_fight = false;
    static sfView *new = NULL;

    if (scene == NULL || screen == NULL || game == NULL)
        return 84;
    if (init_fight == false) {
        if (load_fight(scene) == 84)
            return 84;
        new = sfView_createFromRect((sfFloatRect){0, 0, 1920, 1080});
        if (new == NULL)
            return 84;
        init_fight = true;
    }
    sfRenderWindow_setView(screen->window, new);
    if (fight_handling(scene, game, screen) == 84)
        return 84;
    return 0;
}
