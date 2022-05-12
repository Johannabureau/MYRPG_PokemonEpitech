/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** init_move_menu
*/

#include "rpg.h"
#include "map.h"

bool init_pos(scene_t *scene)
{
    if (!scene || !scene->object || !scene->object[0] || !init_all_text(scene))
        return false;
    sfSprite_scale(scene->object[0][0]->sprite, (sfVector2f){6, 6});
    sfSprite_setPosition(scene->object[0][1]->sprite, (sfVector2f){1000, 100});
    sfSprite_scale(scene->object[0][1]->sprite, (sfVector2f){6, 6});
    sfSprite_setRotation(scene->object[0][1]->sprite, 90);
    return true;
}
