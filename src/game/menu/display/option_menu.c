/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** option_menu
*/

#include "rpg.h"
#include "map.h"

int display_option(screen_t *screen, scene_t **scene, game_t *game)
{
    if (screen == NULL || scene == NULL || game == NULL)
        return 84;
    return 0;
}

int display_end_menu(screen_t *screen, scene_t **scene, game_t *game)
{
    if (screen == NULL || scene == NULL || game == NULL)
        return 84;
    if (scene[MENU]->index == WIN_MENU) {
        sfText_setString(scene[MENU]->object[2][0]->text, "YOU WIN");
        sfText_setString(scene[MENU]->object[2][4]->text,
                "Press any key to quit");
    } else {
        sfText_setString(scene[MENU]->object[2][0]->text,
                "Your pokemon have no more pv");
        sfText_setString(scene[MENU]->object[2][4]->text, "     To fight again\
                \nHeal your pokemon in the pokecenter");
    }
    sfText_setCharacterSize(scene[MENU]->object[2][0]->text, 128);
    DRAW_TEXT(scene[MENU]->object[2][0]->text);
    DRAW_TEXT(scene[MENU]->object[2][4]->text);
    return 0;
}
