/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-johanna.bureau
** File description:
** laod_intro
*/

#include <SFML/Audio/Music.h>
#include <SFML/System/Clock.h>
#include <stdlib.h>
#include "rpg.h"

static int load_first_part(game_object_t *object)
{
    sfIntRect rect;

    rect.left = 0;
    rect.top = 0;
    rect.width = 385;
    rect.height = 216;
    if (init_object(rect, "assets/intro/sprite/intro385_216.jpg",
                "assets/intro/sound/intro_part1.ogg", object) == 84)
        return 84;
    sfSprite_scale(object->sprite, (sfVector2f){5.0,5.0});
    sfMusic_play(object->music);
    return 0;
}

static int load_second_part(game_object_t *object)
{
    sfIntRect rect;

    rect.left = 0;
    rect.top = 0;
    rect.width = 385;
    rect.height = 216;
    if (init_object(rect, "assets/intro/sprite/intro2|385_216.jpg",
                "assets/intro/sound/intro_part2.ogg", object) == 84)
        return 84;
    sfSprite_scale(object->sprite, (sfVector2f){5.0,5.0});
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
    object[0][3] = NULL;
    for (int j = 0; j < 3; j++) {
        object[0][j] = malloc(sizeof(game_object_t));
        if (object[0][j] == NULL)
            return NULL;
    }
    object[0][2] = NULL;
    return object;
}

int load_intro(scene_t *scene)
{
    scene->object = malloc_obj();
    if (scene->object == NULL)
        return 84;
    if ((scene->clock = sfClock_create()) == NULL)
        return 84;
    if (load_first_part(scene->object[0][0]) == 84)
        return 84;
    if (load_second_part(scene->object[0][1]) == 84)
        return 84;
    return 0;
}
