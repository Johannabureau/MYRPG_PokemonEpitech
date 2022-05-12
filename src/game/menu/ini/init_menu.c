/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** init_menu
*/

#include "map.h"
#include "rpg.h"

static bool malloc_sprite(scene_t *scene, int nb_sprite)
{
    if (scene == NULL)
        return false;
    scene->object = malloc(sizeof(game_object_t **) * 4);
    if (scene->object == NULL)
        return false;
    scene->object[0] = malloc(sizeof(game_object_t *) * (nb_sprite + 1));
    if (scene->object[0] == NULL)
        return false;
    for (int j = 0; j < nb_sprite; j++) {
        scene->object[0][j] = malloc(sizeof(game_object_t));
        if (scene->object[0][j] == NULL)
            return false;
    }
    scene->object[0][nb_sprite] = NULL;
    scene->object[3] = NULL;
    return true;
}

bool init_menu(scene_t *scene)
{
    int err = 0;

    if (!scene || !malloc_sprite(scene, 6))
        return false;
    err += INIT_MAP(((sfIntRect){0, 0, 200, 200}), SP_MENU_FRAME, 0);
    err += INIT_MAP(((sfIntRect){0, 0, 200, 200}), START_FRAME_SP, 1);
    err += INIT_MAP(((sfIntRect){0, 0, 1920, 1080}),
            "assets/intro_g/sprite/help_menu.png", 2);
    scene->clock = sfClock_create();
    scene->menu_index = TO_NOWERE;
    set_index_menu(START_MENU);
    return (err > 0) ? false : true;
}
