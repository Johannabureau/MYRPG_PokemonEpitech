/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** check_fight
*/

#include "rpg.h"
#include "map.h"
#include "move_main_char.h"

static int check_png_map(screen_t *screen, scene_t *scene, game_t *game)
{
    sfVector2f pos;
    int err = 0;

    if (screen == NULL || scene == NULL || game == NULL)
        return 84;
    pos = sfSprite_getPosition(scene->object[1][0]->sprite);
    if ((pos.x > 500 && pos.x < 600 && pos.y < -2800 && pos.y > -3000) ||
            (pos.x > -200 && pos.x < 0 && pos.y < -1600 && pos.y > -1800) ||
            (pos.x > 300 && pos.x < 500 && pos.y < -900 && pos.y > -1100)) {
        screen->scene_type = FIGHT;
        err += read_poke_dir(&game->enemy[0], "3.marcacrin");
    }
    if (err > 0)
        return 84;
    return 0;
}

int is_the_boss_fight(int index)
{
    static int is_boss = 0;

    if (index == -1)
        return is_boss;
    else
        is_boss = index;
    return is_boss;
}

int end_fight(scene_t *scene, game_t *game, screen_t *screen, bool good_end)
{
    if (!scene || !game || !screen)
        return 84;
    if (is_the_boss_fight(-1) != 1 && good_end) {
        screen->scene_type = GAME;
        return 0;
    }
    screen->scene_type = MENU;
    if (good_end)
        set_index_menu(WIN_MENU);
    else
        set_index_menu(LOOSE_MENU);
    return 0;
}

static int check_png_boss(screen_t *screen, scene_t *scene, game_t *game)
{
    sfVector2f pos;
    int err = 0;

    if (screen == NULL || scene == NULL || game == NULL)
        return 84;
    pos = sfSprite_getPosition(scene->object[1][0]->sprite);
    if (pos.x > 1100 && pos.x < 1200 && pos.y > -5400 && pos.y < -5200) {
        screen->scene_type = FIGHT;
        err += read_poke_dir(&game->enemy[0], "5.rondoudou");
        err += read_poke_dir(&game->enemy[1], "3.marcacrin");
        is_the_boss_fight(1);
    }
    return err;
}

int check_fight_png(screen_t *screen, scene_t *scene, game_t *game)
{
    if (screen == NULL || scene == NULL || game == NULL)
        return 84;
    if (!sfKeyboard_isKeyPressed(sfKeyX))
        return 0;
    if (scene->index == PALLET_VIRIDIAN)
        return check_png_map(screen, scene, game);
    if (scene->index == VIR_ARENE)
        return check_png_boss(screen, scene, game);
    if (scene->index == VIRIDIAN_2)
        return check_heal_pokemon(screen, scene, game);
    return 0;
}
