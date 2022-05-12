/*
** EPITECH PROJECT, 2022
** destroy_function
** File description:
** destroy_all
*/

#include <stdlib.h>
#include "map.h"
#include "rpg.h"

void destroy_all(scene_t **scene, screen_t *screen, game_t *game)
{
    if (scene == NULL)
        return;
    for (int i = 0; scene[i] != NULL; i++)
        destroy_scene(scene[i]);
    free(scene);
    destroy_map(game);
    free(game);
    sfRenderWindow_destroy(screen->window);
    sfClock_destroy(screen->clock);
    sfView_destroy(screen->view);
    free(screen);
    return;
}
