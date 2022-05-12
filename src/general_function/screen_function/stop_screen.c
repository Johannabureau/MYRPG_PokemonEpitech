/*
** EPITECH PROJECT, 2022
** screen_function
** File description:
** stop_screen
*/

#include <SFML/Graphics.h>
#include "rpg.h"

void stop_my_rpg(screen_t *screen)
{
    if (screen->event.type == sfEvtClosed ||
    screen->event.key.code == sfKeyEscape)
        sfRenderWindow_close(screen->window);
    return;
}
