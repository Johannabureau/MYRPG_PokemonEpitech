/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** init_stat_text
*/

#include "rpg.h"
#include "map.h"

static int init_text(game_object_t *obj, sfVector2f pos)
{
    if (obj == NULL)
        return 84;
    obj->clock = NULL;
    obj->texture = NULL;
    obj->sprite = NULL;
    obj->text = sfText_create();
    obj->font = sfFont_createFromFile("assets/font/base_font.ttf");
    if (!obj->font || !obj->text)
        return 84;
    sfText_setFont(obj->text, obj->font);
    sfText_setPosition(obj->text, pos);
    sfText_setFillColor(obj->text, sfGreen);
    sfText_setCharacterSize(obj->text, 64);
    return 0;
}

int init_stat_text(scene_t *scene)
{
    int err = 0;

    err += init_text(scene->object[2][0], ((sfVector2f){100, 250}));
    err += init_text(scene->object[2][1], ((sfVector2f){100, 310}));
    err += init_text(scene->object[2][2], ((sfVector2f){100, 370}));
    err += init_text(scene->object[2][3], ((sfVector2f){100, 430}));
    err += init_text(scene->object[2][4], ((sfVector2f){100, 490}));
    err += init_text(scene->object[2][5], ((sfVector2f){100, 550}));
    err += init_text(scene->object[2][6], ((sfVector2f){100, 610}));
    err += init_text(scene->object[2][7], ((sfVector2f){100, 670}));
    err += init_text(scene->object[2][8], ((sfVector2f){100, 730}));
    err += init_text(scene->object[2][9], ((sfVector2f){100, 790}));
    err += init_text(scene->object[2][10], ((sfVector2f){100, 850}));
    err += init_text(scene->object[2][11], ((sfVector2f){100, 910}));
    return err;
}
