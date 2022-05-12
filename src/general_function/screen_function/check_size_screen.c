/*
** EPITECH PROJECT, 2021
** general_function
** File description:
** check_size_screen
*/

#include <SFML/Graphics.h>
#include "rpg.h"

void check_size_screen(screen_t *screen)
{
    sfVector2u size;

    if (screen->event.type == sfEvtResized) {
        size = sfRenderWindow_getSize(screen->window);
        screen->scaling_x = size.x / 1920.0;
        screen->scaling_y = size.y / 1080.0;
    }
    return;
}
