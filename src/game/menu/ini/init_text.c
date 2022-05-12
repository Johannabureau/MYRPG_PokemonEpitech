/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** init_text
*/

#include "map.h"
#include "rpg.h"

static bool malloc_sprite(scene_t *scene, int nb_sprite, int index)
{
    if (scene == NULL || scene->object == NULL)
        return false;
    scene->object[index] = malloc(sizeof(game_object_t *) * (nb_sprite + 1));
    if (scene->object[0] == NULL)
        return false;
    for (int j = 0; j < nb_sprite; j++) {
        scene->object[index][j] = malloc(sizeof(game_object_t));
        if (scene->object[index][j] == NULL)
            return false;
    }
    scene->object[index][nb_sprite] = NULL;
    return true;
}

static int init_text(game_object_t *obj, sfIntRect rect, sfVector2f pos)
{
    if (obj == NULL)
        return 84;
    obj->clock = NULL;
    obj->texture = NULL;
    obj->sprite = NULL;
    obj->rect = rect;
    obj->text = sfText_create();
    obj->font = sfFont_createFromFile("assets/font/base_font.ttf");
    if (!obj->font || !obj->text)
        return 84;
    sfText_setFont(obj->text, obj->font);
    sfText_setPosition(obj->text, pos);
    sfText_setFillColor(obj->text, sfBlack);
    sfText_setCharacterSize(obj->text, 64);
    return 0;
}

static bool init_in_text(scene_t *scene)
{
    if (scene == NULL)
        return false;
    sfText_setString(scene->object[1][0]->text, "Cancel");
    sfText_setString(scene->object[1][1]->text, "Options");
    sfText_setString(scene->object[1][2]->text, "Pokemons");
    sfText_setString(scene->object[1][3]->text, "Menu");
    sfText_setString(scene->object[1][4]->text, "Quit");
    sfText_setString(scene->object[1][5]->text, "New");
    sfText_setString(scene->object[1][6]->text, "Help");
    sfText_setString(scene->object[1][7]->text, "Quit");
    return true;
}

bool init_all_text(scene_t *scene)
{
    sfIntRect rect[] = {{80, 30, 100, 50}, {200, 50, 130, 50},
        {350, 50, 150, 50}, {520, 50, 90, 50}, {610, 50, 90, 50},
        {650, 150, 90, 50}, {650, 230, 90, 50}, {650, 310, 90, 50}};
    int err = 0;

    if (!scene || !malloc_sprite(scene, 8, 1) || !malloc_sprite(scene, 12, 2))
        return false;
    err += INIT_TXT(0, rect[0], ((sfVector2f){100, 50}));
    err += INIT_TXT(1, rect[1], ((sfVector2f){255, 50}));
    err += INIT_TXT(2, rect[2], ((sfVector2f){440, 50}));
    err += INIT_TXT(3, rect[3], ((sfVector2f){660, 50}));
    err += INIT_TXT(4, rect[4], ((sfVector2f){800, 50}));
    err += INIT_TXT(5, rect[5], ((sfVector2f){840, 200}));
    err += INIT_TXT(6, rect[6], ((sfVector2f){840, 300}));
    err += INIT_TXT(7, rect[7], ((sfVector2f){840, 400}));
    if (err > 0 || !init_in_text(scene) || init_stat_text(scene) > 0)
        return false;
    return true;
}
