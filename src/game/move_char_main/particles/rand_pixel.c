/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-johanna.bureau
** File description:
** create_pixel
*/

#include "rpg.h"

void my_put_pixel(framebuffer_t *framebuffer, int x, int y, sfColor color)
{
    int pos = (((y - 1) * framebuffer->width) + x) * 4;

    framebuffer->pixels[pos] = color.r;
    framebuffer->pixels[pos + 1] = color.g;
    framebuffer->pixels[pos + 2] = color.b;
    framebuffer->pixels[pos + 3] = color.a;
}

void my_draw_square(framebuffer_t *fb, sfVector2i vtc, int size, sfColor color)
{
    int x = vtc.x;
    int y = vtc.y;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            my_put_pixel(fb, x + j, y + i, color);
        }
    }
}

framebuffer_t *clear_frame(framebuffer_t *fb)
{
    for (unsigned int i = 0; i < (fb->width * fb->height * 4); i++)
        fb->pixels[i] = 0;
    return fb;
}

framebuffer_t *rand_pixel(framebuffer_t *fb, int width, int height)
{
    int size = 25;
    int size_square = 10;
    sfColor brown = {.r = 101, .b = 67, .g = 33, .a = 255};
    sfColor brown2 = {.r = 244, .b = 96, .g = 164, .a = 255};
    int x = width + rand() % size;
    int y = height + rand() % size;
    int i = width + rand() % size;
    int j = height + rand() % size;

    clear_frame(fb);
    my_draw_square(fb, (sfVector2i){x, y}, size_square, brown);
    my_draw_square(fb, (sfVector2i){i, j}, size_square, brown2);
    return fb;
}

framebuffer_t *make_smoke_fireplace(framebuffer_t *fb, int width, int height)
{
    int size = 25;
    int size_square = 10;
    sfColor grey = {.r = 194, .b = 204, .g = 197, .a = 125};
    int x = width + rand() % size;
    int y = height + rand() % size;

    clear_frame(fb);
    my_draw_square(fb, (sfVector2i){x, y}, size_square, grey);
    x = width + (rand() % size);
    y = height + (rand() % size);
    my_draw_square(fb, (sfVector2i){x, y}, size_square, sfWhite);
    return fb;
}
