/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** third_buttun_state
*/

#include "rpg.h"
#include "map.h"

static void do_button_after(screen_t *screen, scene_t *scene)
{
    if (!scene || !screen)
        return;
    if (scene->menu_index == TO_CANCEL) {
        screen->scene_type = set_old_scene(-1);
        set_index_menu(BASIC_MENU);
    }
    if (scene->menu_index == TO_OPTION)
        scene->index = OPTION_MENU;
    if (scene->menu_index == TO_INV)
        set_index_menu(INV_MENU);
    if (scene->menu_index == TO_MENU)
        set_index_menu(START_MENU);
    if (scene->menu_index == TO_QUIT || scene->menu_index == TO_QUIT2)
        sfRenderWindow_close(screen->window);
    if (scene->menu_index == TO_NEW)
        screen->scene_type = START_G;
    if (scene->menu_index == TO_HELP)
        set_index_menu(HELP_MENU);
}

int check_buttons_state(screen_t *screen, scene_t **scene)
{
    float seconds = 0.00;

    if (!scene || !screen)
        return false;
    scene[MENU]->time = sfClock_getElapsedTime(scene[MENU]->clock);
    seconds = scene[MENU]->time.microseconds / 1000000.0;
    if (scene[MENU]->menu_index != TO_NOWERE) {
        if (seconds > 1) {
            sfClock_restart(scene[MENU]->clock);
            do_button_after(screen, scene[MENU]);
            scene[MENU]->menu_index = TO_NOWERE;
        } else
            SET_COLOR(scene[MENU]->object[1][scene[MENU]->menu_index]->text);
    } else
        sfClock_restart(scene[MENU]->clock);
    return 0;
}
