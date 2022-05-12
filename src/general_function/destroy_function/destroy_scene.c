/*
** EPITECH PROJECT, 2022
** destroy_function
** File description:
** destroy_scene
*/

#include <stdlib.h>
#include "rpg.h"

void destroy_scene(scene_t *scene)
{
    if (scene == NULL || scene->object == NULL)
        return;
    for (int i = 0; scene->object[i] != NULL; i++) {
        for (int j = 0; scene->object[i][j] != NULL; j++) {
            destroy_game_object(scene->object[i][j]);
        }
        free(scene->object[i]);
    }
    free(scene->object);
    if (scene->music != NULL) {
        sfMusic_stop(scene->music);
        sfMusic_destroy(scene->music);
    }
    free(scene);
    return;
}
