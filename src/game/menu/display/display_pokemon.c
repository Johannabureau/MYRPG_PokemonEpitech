/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** display_pokemon
*/

#include "rpg.h"
#include "map.h"
#include "my.h"

static void change_color(screen_t *screen, scene_t *scene)
{
    sfVector2i pos;
    sfFloatRect rect = {0.0, 0.0, 0.0, 0.0};

    if (!scene || !screen || scene->menu_index != TO_NOWERE)
        return;
    for (int i = 0; i < 5; i++) {
        rect = sfText_getGlobalBounds(scene->object[1][i]->text);
        pos = sfMouse_getPositionRenderWindow(screen->window);
        if (sfFloatRect_contains(&rect, pos.x, pos.y))
            sfText_setFillColor(scene->object[1][i]->text, sfMagenta);
        else
            sfText_setFillColor(scene->object[1][i]->text, sfBlack);
    }
    return;
}

static int no_pokemon(screen_t *screen, scene_t **scene)
{
    if (screen == NULL || scene == NULL)
        return 84;
    sfText_setString(scene[MENU]->object[2][0]->text, "You have no pokemon");
    DRAW_TEXT(scene[MENU]->object[2][0]->text);
    return check_buttons_state(screen, scene);
}

int display_pokemon_menu(screen_t *screen, scene_t **scene, game_t *game)
{
    if (screen == NULL || scene == NULL || game == NULL)
        return 84;
    change_color(screen, scene[MENU]);
    DRAW_SP_MAP(scene[MENU]->object[0][0]);
    DRAW_TEXT(scene[MENU]->object[1][0]->text);
    DRAW_TEXT(scene[MENU]->object[1][4]->text);
    if (my_strcmp(game->start->pokemon_inv[0].name, "none") == 0)
        return no_pokemon(screen, scene);
    else
        return display_stat_poke(screen, scene, game);
    return check_buttons_state(screen, scene);
}
