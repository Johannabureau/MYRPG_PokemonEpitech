/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-johanna.bureau
** File description:
** load_intro_g
*/

#include "rpg.h"
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Text.h>
#include <SFML/System/Vector2.h>

static int load_select_name(game_object_t *object)
{
    sfIntRect rect;

    if (object == NULL)
        return 84;
    rect.left = 0;
    rect.top = 0;
    rect.width = 1920;
    rect.height = 1080;
    if (init_object(rect, "assets/intro_g/sprite/chose_name.jpg",
                NULL, object) == 84)
        return 84;
    object->text = sfText_create();
    object->font = sfFont_createFromFile("assets/font/base_font.ttf");
    if (object->text == NULL || object->font == NULL)
        return 84;
    sfText_setFont(object->text, object->font);
    sfText_setFillColor(object->text, sfBlack);
    sfText_setScale(object->text, (sfVector2f){4.0,4.0});
    sfText_move(object->text, (sfVector2f){790.0, 80.0});
    return 0;
}

static game_object_t ***malloc_obj(void)
{
    game_object_t ***object = malloc(sizeof(game_object_t**) * 2);

    if (object == NULL)
        return NULL;
    object[1] = NULL;
    object[0] = malloc(sizeof(game_object_t*) * 4);
    if (object[0] == NULL)
        return NULL;
    for (int j = 0; j < 3; j++) {
        object[0][j] = malloc(sizeof(game_object_t));
        if (object[0][j] == NULL)
            return NULL;
    }
    object[0][3] = NULL;
    return object;
}

static int load_select_gender(game_object_t **object)
{
    sfIntRect rect;

    if (object == NULL)
        return 84;
    rect.left = 0;
    rect.top = 0;
    rect.width = 1920;
    rect.height = 1080;
    if (init_object(rect, "assets/intro_g/sprite/chose_gender.jpg",
                NULL, object[1]) == 84)
        return 84;
    rect.width = 77;
    rect.height = 100;
    if (init_object(rect, "assets/intro_g/sprite/arrow.png",
                NULL, object[2]) == 84)
        return 84;
    sfSprite_setPosition(object[2]->sprite, (sfVector2f){1515.00,485.00});
    return 0;
}

int load_intro_g(scene_t *scene, game_t *game)
{
    if (scene == NULL)
        return 84;
    scene->object = malloc_obj();
    if (scene->object == NULL)
        return 84;
    if (load_select_name(scene->object[0][0]) == 84)
        return 84;
    if (init_game(game) == 84)
        return 84;
    if (load_select_gender(scene->object[0]) == 84)
        return 84;
    return 0;
}
