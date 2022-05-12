/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** display_start
*/

#include "rpg.h"
#include "map.h"
#include <SFML/Graphics/Text.h>

static void change_color(screen_t *screen, scene_t *scene)
{
    sfVector2i pos;
    sfFloatRect rect = {0.0, 0.0, 0.0, 0.0};

    if (!scene || !screen || scene->menu_index != TO_NOWERE)
        return;
    for (int i = 5; i < 8; i++) {
        rect = sfText_getGlobalBounds(scene->object[1][i]->text);
        pos = sfMouse_getPositionRenderWindow(screen->window);
        if (sfFloatRect_contains(&rect, pos.x, pos.y))
            sfText_setFillColor(scene->object[1][i]->text, sfMagenta);
        else
            sfText_setFillColor(scene->object[1][i]->text, sfBlack);
    }
    return;
}

int display_start(screen_t *screen, scene_t **scene, game_t *game)
{
    if (screen == NULL || scene == NULL || game == NULL)
        return 84;
    change_color(screen, scene[MENU]);
    DRAW_SP_MAP(scene[MENU]->object[0][1]);
    DRAW_TEXT(scene[MENU]->object[1][5]->text);
    DRAW_TEXT(scene[MENU]->object[1][6]->text);
    DRAW_TEXT(scene[MENU]->object[1][7]->text);
    return check_buttons_state(screen, scene);
}
