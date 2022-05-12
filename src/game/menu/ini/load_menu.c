/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** load_menu
*/

#include "rpg.h"
#include "map.h"

static int display_handeling(screen_t *screen, scene_t **scene, game_t *game)
{
    if (!screen || !scene || !game)
        return 84;
    if (scene[MENU]->index == BASIC_MENU)
        return display_menu(screen, scene, game);
    if (scene[MENU]->index == OPTION_MENU)
        return display_option(screen, scene, game);
    if (scene[MENU]->index == START_MENU)
        return display_start(screen, scene, game);
    if (scene[MENU]->index == HELP_MENU)
        return display_help(screen, scene, game);
    if (scene[MENU]->index == INV_MENU)
        return display_pokemon_menu(screen, scene, game);
    if (scene[MENU]->index == WIN_MENU || scene[MENU]->index == LOOSE_MENU)
        return display_end_menu(screen, scene, game);
    return 0;
}

int set_index_menu(int index)
{
    static int old_index = 0;

    if (index == -1)
        return old_index;
    else
        old_index = index;
    return 0;
}

static int get_index_menu(void)
{
    return set_index_menu(-1);
}

int load_menu(screen_t *screen, scene_t **scene, game_t *game)
{
    static bool is_load = false;
    static sfView *new = NULL;

    if (is_load == false) {
        new = sfView_createFromRect((sfFloatRect){0, 0, 1920, 1080});
        if (!init_menu(scene[MENU]) || !init_pos(scene[MENU]) || !new)
            return 84;
        is_load = true;
    }
    sfRenderWindow_setView(screen->window, new);
    scene[MENU]->index = get_index_menu();
    return display_handeling(screen, scene, game);
}
