/*
** EPITECH PROJECT, 2022
** destroy_function
** File description:
** destroy_game_object
*/

#include <stdlib.h>
#include "rpg.h"

void destroy_game_object(game_object_t *object)
{
    if (object == NULL)
        return;
    if (!(object->texture == NULL))
        sfTexture_destroy(object->texture);
    if (!(object->sprite == NULL))
        sfSprite_destroy(object->sprite);
    if (!(object->clock == NULL))
        sfClock_destroy(object->clock);
    if (object->music != NULL) {
        sfMusic_stop(object->music);
        sfMusic_destroy(object->music);
    }
    free(object);
    return;
}
