/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-johanna.bureau
** File description:
** load_particle
*/

#include "rpg.h"
#include "move_main_char.h"

int load_particle(screen_t *screen, scene_t *scene, game_t *game)
{
    if (!screen || !scene || !game)
        return 84;
    clear_frame(screen->fb);
    if (scene->move == RIGHT)
        rand_pixel(screen->fb, 80, 150);
    if (scene->move == DOWN)
        rand_pixel(screen->fb, 110, 100);
    if (scene->move == LEFT)
        rand_pixel(screen->fb, 150, 150);
    if (scene->move == UP)
        rand_pixel(screen->fb, 110, 170);
    PIX_UPDATE(screen->fb->texture, screen->fb->pixels);
    sfRenderWindow_drawSprite(screen->window, screen->fb->sprite, NULL);
    return 0;
}
