/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** event_menu
*/

#include "rpg.h"
#include "map.h"

static int check_in_menu_event(screen_t *screen, scene_t **scene)
{
    if (!screen || !scene)
        return 84;
    if (scene[MENU]->index == LOOSE_MENU && screen->event.key.code != sfKeyX) {
        screen->scene_type = GAME;
        scene[MENU]->index = BASIC_MENU;
    }
    if (screen->event.key.code == sfKeyB && scene[MENU]->index == BASIC_MENU)
        screen->scene_type = set_old_scene(-1);
    if (scene[MENU]->index == WIN_MENU)
        sfRenderWindow_close(screen->window);
    if (screen->event.type == sfEvtMouseButtonPressed)
        return check_menu_button(screen, scene);
    return 0;
}

int set_old_scene(int index)
{
    static int old_index = 0;

    if (index == -1)
        return old_index;
    else
        old_index = index;
    return -1;
}

void check_menu_event(screen_t *screen, scene_t **scene)
{
    if (screen->event.key.code == sfKeyEnter &&
            screen->event.type == sfEvtKeyPressed &&
            (screen->scene_type == GAME || screen->scene_type == TEXT)) {
        set_old_scene(screen->scene_type);
        screen->scene_type = MENU;
        set_index_menu(BASIC_MENU);
    }
    if (screen->scene_type == MENU)
        check_in_menu_event(screen, scene);
    return;
}
