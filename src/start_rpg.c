/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-mydefender-samuel.florentin
** File description:
** start_my_defender
*/

#include <SFML/Audio/Music.h>
#include <unistd.h>
#include <stdlib.h>
#include <SFML/Window/Export.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <math.h>
#include <stdio.h>
#include "rpg.h"
#include "map.h"
#include "move_main_char.h"

static int initialize_screen(screen_t *screen)
{
    sfVideoMode mode = {1920, 1080, 32};
    screen->window = sfRenderWindow_create
        (mode, "window", sfClose | sfResize, NULL);
    sfRenderWindow_setFramerateLimit(screen->window, 30);
    screen->scaling_x = 1.0;
    screen->scaling_y = 1.0;
    screen->clock = sfClock_create();
    screen->scene_type = INTRO;
    if (init_framebuffer(screen) == 84)
        return 84;
    screen->view = sfView_createFromRect((sfFloatRect){-500, -200, 920, 580});
    sfView_zoom(screen->view, 1);
    sfView_setViewport(screen->view, (sfFloatRect){0.25, 0.25, 0.5, 0.5});
    return 0;
}

static void check_all_event(screen_t *screen, scene_t **scene)
{
    while (sfRenderWindow_pollEvent(screen->window, &screen->event)) {
        stop_my_rpg(screen);
        check_menu_event(screen, scene);
        if (screen->scene_type == GAME || screen->scene_type == TEXT)
            event_mouve(screen, scene[GAME]);
    }
    return;
}

static int set_global_clock(screen_t *screen, scene_t **scene, game_t *game)
{
    check_all_event(screen, scene);
    if (scene_handling(scene, screen, game) == 84)
        return 84;
    sfRenderWindow_display(screen->window);
    sfRenderWindow_clear(screen->window, sfBlack);
    return 0;
}

int initialize_scene(scene_t **scene)
{
    for (int i = 0; i < NB_SCENE; i++) {
        scene[i] = malloc(sizeof(scene_t));
        if (scene[i] == NULL)
            return 84;
        scene[i]->music = NULL;
        scene[i]->object = NULL;
    }
    scene[4] = NULL;
    return 0;
}

int begin_rpg(char *filepath)
{
    screen_t *screen = malloc(sizeof(screen_t));
    scene_t **scene = malloc(sizeof(scene_t*) * NB_SCENE);
    game_t *game = malloc(sizeof(game_t));

    if (scene == NULL || !screen || !game || filepath)
        return 84;
    game->map = NULL;
    if (initialize_scene(scene) == 84 || initialize_screen(screen) == 84)
        return 84;
    while (sfRenderWindow_isOpen(screen->window)) {
        if (set_global_clock(screen, scene, game) == 84)
            return 84;
    }
    sfMusic_destroy(scene[INTRO]->music);
    sfMusic_destroy(scene[INTRO]->object[0][0]->music);
    sfMusic_destroy(scene[INTRO]->object[0][1]->music);
    return 0;
}
