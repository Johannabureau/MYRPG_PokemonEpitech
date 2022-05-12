/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** display_map
*/

#include "map.h"

int display_map(scene_t *scene, screen_t *screen)
{
    if (!scene->object[0] || !scene->object[0][scene->index]->sprite)
        return 84;
    sfRenderWindow_setView(screen->window, screen->view);
    DRAW_SP_MAP(scene->object[0][scene->index]);
    return 0;
}
