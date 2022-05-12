/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** display_help
*/

#include "rpg.h"
#include "map.h"
#include <SFML/Graphics/RenderWindow.h>

int display_help(screen_t *screen, scene_t **scene, game_t *game)
{
    if (screen == NULL || scene == NULL || game == NULL)
        return 84;
    sfRenderWindow_drawSprite(screen->window,
            scene[MENU]->object[0][2]->sprite, NULL);
    return check_buttons_state(screen, scene);
}
