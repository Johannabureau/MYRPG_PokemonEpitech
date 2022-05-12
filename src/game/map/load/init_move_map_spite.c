/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** init_move_map_spite
*/

#include "map.h"

static bool set_pos_map(scene_t *scene)
{
    sfVector2f pos[] = {{-1150, -7900}, {-195, -560}, {250, -520}, {300, -560},
        {50, -4500}, {880, -4880}, {180, -4960}, {180, -5400}, {760, -5700}};

    if (!scene)
        return false;
    sfSprite_setPosition(scene->object[0][0]->sprite, pos[0]);
    sfSprite_setPosition(scene->object[0][1]->sprite, pos[1]);
    sfSprite_setPosition(scene->object[0][2]->sprite, pos[1]);
    sfSprite_setPosition(scene->object[0][3]->sprite, pos[3]);
    sfSprite_setPosition(scene->object[0][4]->sprite, pos[2]);
    sfSprite_setPosition(scene->object[0][5]->sprite, pos[4]);
    sfSprite_setPosition(scene->object[0][6]->sprite, pos[4]);
    sfSprite_setPosition(scene->object[0][7]->sprite, pos[5]);
    sfSprite_setPosition(scene->object[0][8]->sprite, pos[6]);
    sfSprite_setPosition(scene->object[0][9]->sprite, pos[7]);
    sfSprite_setPosition(scene->object[0][10]->sprite, pos[8]);
    sfSprite_setPosition(scene->object[0][11]->sprite, pos[0]);
    return true;
}

static bool scale_map(scene_t *scene)
{
    if (!scene)
        return false;
    sfSprite_setScale(scene->object[0][0]->sprite, (sfVector2f){4, 4});
    sfSprite_setScale(scene->object[0][1]->sprite, (sfVector2f){4, 4});
    sfSprite_setScale(scene->object[0][2]->sprite, (sfVector2f){4, 4});
    sfSprite_setScale(scene->object[0][3]->sprite, (sfVector2f){4, 4});
    sfSprite_setScale(scene->object[0][4]->sprite, (sfVector2f){4, 4});
    sfSprite_setScale(scene->object[0][5]->sprite, (sfVector2f){4, 4});
    sfSprite_setScale(scene->object[0][6]->sprite, (sfVector2f){4, 4});
    sfSprite_setScale(scene->object[0][7]->sprite, (sfVector2f){4, 4});
    sfSprite_setScale(scene->object[0][8]->sprite, (sfVector2f){4, 4});
    sfSprite_setScale(scene->object[0][9]->sprite, (sfVector2f){4, 4});
    sfSprite_setScale(scene->object[0][10]->sprite, (sfVector2f){4, 4});
    sfSprite_setScale(scene->object[0][11]->sprite, (sfVector2f){4, 4});
    return true;
}

bool mouve_sprite_map(scene_t *scene)
{
    if (!scene || !scale_map(scene) || !set_pos_map(scene))
        return false;
    return true;
}
