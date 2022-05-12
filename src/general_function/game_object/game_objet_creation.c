/*
** EPITECH PROJECT, 2022
** sprite_related_function
** File description:
** sprite_creation
*/

#include <unistd.h>
#include <stdlib.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include "rpg.h"

int init_object(sfIntRect rect, char *sprite_path, char *song
        ,game_object_t *object)
{
    if (sprite_path == NULL || sprite_path[0] == '\0' || object == NULL)
        return 84;
    object->texture = sfTexture_createFromFile(sprite_path, NULL);
    if (object->texture == NULL)
        return 84;
    object->sprite = sfSprite_create();
    if (object->sprite == NULL)
        return 84;
    sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    sfSprite_setTextureRect(object->sprite, rect);
    object->clock = sfClock_create();
    object->music = NULL;
    if (song != NULL) {
        object->music = sfMusic_createFromFile(song);
        if (object->music == NULL)
            return 84;
    }
    object->left = rect.left;
    object->top = rect.top;
    return 0;
}
