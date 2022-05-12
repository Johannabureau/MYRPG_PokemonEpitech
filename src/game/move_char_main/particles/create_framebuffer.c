/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** create_framebuffer
*/

#include "rpg.h"

static framebuffer_t *create_framebuffer(int width, int height)
{
    framebuffer_t *fb = malloc(sizeof(framebuffer_t));

    if (fb == NULL)
        return NULL;
    fb->pixels = malloc(sizeof(int) * ((width * height * 4) + 1));
    if (fb->pixels == NULL)
        return NULL;
    fb->width = width;
    fb->height = height;
    fb->sprite = sfSprite_create();
    fb->texture = sfTexture_create(width, height);
    sfSprite_setTexture(fb->sprite, fb->texture, sfTrue);
    return fb;
}

int init_framebuffer(screen_t *screen)
{
    if (!screen)
        return 84;
    screen->fb = create_framebuffer(400, 400);
    screen->fb_smoke = create_framebuffer(800, 800);
    if (screen->fb == NULL || screen->fb_smoke == NULL)
        return 84;
    sfSprite_move(screen->fb->sprite, (sfVector2f){-100, -100});
    sfSprite_move(screen->fb_smoke->sprite, (sfVector2f){800, 50});
    return 0;
}
