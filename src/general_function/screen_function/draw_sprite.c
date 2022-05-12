/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-johanna.bureau
** File description:
** draw_sprite
*/

#include "rpg.h"

void draw_sprite(sfSprite *sprite, screen_t *screen)
{
    if (screen == NULL || sprite == NULL)
        return;
    sfRenderWindow_drawSprite(screen->window, sprite, NULL);
    return;
}
