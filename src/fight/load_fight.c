/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-johanna.bureau
** File description:
** load_fight
*/

#include "rpg.h"
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/View.h>
#include <stdlib.h>

static game_object_t ***malloc_obj(void)
{
    game_object_t ***object = malloc(sizeof(game_object_t**) * 4);

    if (object == NULL)
        return NULL;
    object[3] = NULL;
    for (int i = 0; i < 3; i++) {
        object[i] = malloc(sizeof(game_object_t*) * 3);
        if (object[i] == NULL)
            return NULL;
    }
    for (int j = 0; j < 3; j++) {
        object[j][0] = malloc(sizeof(game_object_t));
        object[j][1] = malloc(sizeof(game_object_t));
        if (object[j][0] == NULL || object[j][1] == NULL)
            return NULL;
        object[j][2] = NULL;
    }
    return object;
}

static int load_scene(game_object_t **object)
{
    sfIntRect rect = {0, 0, 1920, 1080};

    if (init_object(rect, "assets/fight/fight_terrain.jpg",
                "assets/fight/fight_song.ogg", object[0]) == 84)
        return 84;
    object[0]->text = sfText_create();
    object[0]->font = sfFont_createFromFile("assets/font/base_font.ttf");
    if (object[0]->text == NULL || object[0]->font == NULL)
        return 84;
    sfText_setFont(object[0]->text, object[0]->font);
    sfText_setFillColor(object[0]->text, sfBlack);
    sfText_setScale(object[0]->text, (sfVector2f){4.0, 4.0});
    rect.width = 77;
    rect.height = 100;
    if (init_object(rect, "assets/intro_g/sprite/arrow.png",
                NULL, object[1]) == 84)
        return 84;
    sfSprite_setPosition(object[1]->sprite, (sfVector2f){1135, 800});
    return 0;
}

int load_fight(scene_t *scene)
{
    if (scene == NULL)
        return 84;
    scene->object = malloc_obj();
    if (scene->object == NULL)
        return 84;
    if (load_scene(scene->object[0]) == 84)
        return 84;
    return 0;
}
