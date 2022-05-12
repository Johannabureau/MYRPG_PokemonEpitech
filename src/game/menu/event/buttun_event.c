/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** buttun_event
*/

#include "rpg.h"
#include "map.h"
#include <SFML/Graphics/Text.h>

static void buttun_menu(screen_t *screen, scene_t *scene, int nb)
{
    if (!screen || !scene)
        return;
    scene->menu_index = nb;
    return;
}

static void do_button(screen_t *screen, scene_t *scene, sfVector2i opt)
{
    sfVector2i pos;
    sfFloatRect rect = {0.0, 0.0, 0.0, 0.0};

    if (!scene || !screen)
        return;
    for (int i = opt.x; i < opt.y; i++) {
        pos = sfMouse_getPositionRenderWindow(screen->window);
        rect = sfText_getGlobalBounds(scene->object[1][i]->text);
        if (sfFloatRect_contains(&rect, pos.x, pos.y))
            buttun_menu(screen, scene, i);
    }
    return;
}

int check_menu_button(screen_t *screen, scene_t **scene)
{
    if (!screen || !scene)
        return 84;
    if (scene[MENU]->index == BASIC_MENU)
        do_button(screen, scene[MENU], (sfVector2i){0, 5});
    if (scene[MENU]->index == START_MENU)
        do_button(screen, scene[MENU], (sfVector2i){5, 8});
    if (scene[MENU]->index == INV_MENU) {
        do_button(screen, scene[MENU], (sfVector2i){0, 1});
        do_button(screen, scene[MENU], (sfVector2i){4, 5});
    }
    if (scene[MENU]->index == HELP_MENU) {
        set_index_menu(START_MENU);
        set_old_scene(MENU);
        scene[MENU]->menu_index = TO_MENU;
    }
    return 0;
}
