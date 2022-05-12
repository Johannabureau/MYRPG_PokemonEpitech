/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** display_poke_stat
*/

#include "rpg.h"
#include "map.h"
#include "my.h"

static bool update_string_suite(scene_t *scene, game_t *game)
{
    char *atks = "";

    if (game == NULL || scene == NULL)
        return false;
    sfText_setString(scene->object[2][8]->text, my_strcat("Pokemon lvl: ",
    my_int_to_str(game->start->pokemon_inv[0].lv)));
    sfText_setString(scene->object[2][9]->text, my_strcat("Pokemon xp: ",
    my_strcat(my_int_to_str(game->start->pokemon_inv[0].xp), " / 100")));
    sfText_setString(scene->object[2][10]->text,
    my_strcat("Pokemon object: ", game->start->pokemon_inv[0].object));
    for (int i = 0; i < 4; i++) {
        if (my_strcmp(game->start->pokemon_inv[0].atk[i].name, "none") != 0) {
            atks = my_strcat(atks, game->start->pokemon_inv[0].atk[i].name);
            atks = my_strcat(atks, "\t");
        }
    }
    sfText_setString(scene->object[2][11]->text,
    my_strcat("Pokemon ataque(s): ", atks));
    return true;
}

static bool update_string(scene_t *scene, game_t *game)
{
    if (game == NULL || scene == NULL)
        return false;
    sfText_setString(scene->object[2][0]->text,
    my_strcat("Pokemon name: ", game->start->pokemon_inv[0].name));
    sfText_setString(scene->object[2][1]->text, my_strcat("Pokedex index: ",
    my_int_to_str(game->start->pokemon_inv[0].index)));
    sfText_setString(scene->object[2][2]->text, my_strcat("Pokemon life: ",
    my_strcat(my_strcat(my_int_to_str(game->start->pokemon_inv[0].pdv), " / "),
    my_int_to_str(game->start->pokemon_inv[0].stat[0]))));
    sfText_setString(scene->object[2][3]->text, my_strcat("Pokemon attaque: ",
    my_int_to_str(game->start->pokemon_inv[0].stat[1])));
    sfText_setString(scene->object[2][4]->text, my_strcat("Pokemon defence: ",
    my_int_to_str(game->start->pokemon_inv[0].stat[2])));
    sfText_setString(scene->object[2][5]->text, my_strcat("Pokemon atk spe: ",
    my_int_to_str(game->start->pokemon_inv[0].stat[3])));
    sfText_setString(scene->object[2][6]->text, my_strcat("Pokemon def spe: ",
    my_int_to_str(game->start->pokemon_inv[0].stat[4])));
    sfText_setString(scene->object[2][7]->text, my_strcat("Pokemon speed: ",
    my_int_to_str(game->start->pokemon_inv[0].stat[5])));
    return update_string_suite(scene, game);
}

static bool draw_string(screen_t *screen, scene_t *scene)
{
    if (screen == NULL || scene == NULL)
        return false;
    DRAW_TEXT(scene->object[2][0]->text);
    DRAW_TEXT(scene->object[2][1]->text);
    DRAW_TEXT(scene->object[2][2]->text);
    DRAW_TEXT(scene->object[2][3]->text);
    DRAW_TEXT(scene->object[2][4]->text);
    DRAW_TEXT(scene->object[2][5]->text);
    DRAW_TEXT(scene->object[2][6]->text);
    DRAW_TEXT(scene->object[2][7]->text);
    DRAW_TEXT(scene->object[2][8]->text);
    DRAW_TEXT(scene->object[2][9]->text);
    DRAW_TEXT(scene->object[2][10]->text);
    DRAW_TEXT(scene->object[2][11]->text);
    return true;
}

int display_stat_poke(screen_t *screen, scene_t **scene, game_t *game)
{
    if (!screen || !scene || !game || !update_string(scene[MENU], game))
        return 84;
    sfSprite_setPosition(game->start->pokemon_inv[0].sprite,
        (sfVector2f){1200, 400});
    sfRenderWindow_drawSprite(screen->window,
        game->start->pokemon_inv[0].sprite, NULL);
    draw_string(screen, scene[MENU]);
    return check_buttons_state(screen, scene);
}
