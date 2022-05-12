/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-johanna.bureau
** File description:
** scene_handling
*/

#include <stdio.h>
#include "rpg.h"
#include "map.h"
#include "move_main_char.h"

int scene_handling(scene_t **scene, screen_t *screen, game_t *game)
{
    switch (screen->scene_type) {
        case INTRO:
            return begin_intro(scene[INTRO], screen);
        case START_G:
            return begin_intro_game(scene[START_G], screen, game);
        case TEXT:
        case GAME:
            return begin_game(scene[GAME], screen, game);
        case MENU:
            return load_menu(screen, scene, game);
        case FIGHT:
            return begin_fight(scene[FIGHT], screen, game);
    }
    return 0;
}
