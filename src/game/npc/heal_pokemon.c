/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** heal_pokemon
*/

#include "rpg.h"
#include "map.h"

static void set_string(scene_t *scene, game_t *game)
{
    static int time = 0;

    if (time == 0 || time == 11) {
        sfText_setString(scene->object[3][3]->text,
        "Your pokemons has been healed \nand you have won a potion");
        game->start->pokemon_inv[0].object = "Potion";
    } else
        sfText_setString(scene->object[3][3]->text,
                    "Yours pokemons has been healed");
    time += 1;
}

int check_heal_pokemon(screen_t *screen, scene_t *scene, game_t *game)
{
    int missing_life = 0;

    if (screen == NULL || scene == NULL || game == NULL)
        return 84;
    for (int i = 0; i < 6; i++) {
        missing_life += (game->start->pokemon_inv[i].stat[0] -
                                            game->start->pokemon_inv[i].pdv);
        game->start->pokemon_inv[i].pdv = game->start->pokemon_inv[i].stat[0];
    }
    if (missing_life == 0)
        return 0;
    set_string(scene, game);
    screen->scene_type = TEXT;
    scene->text = TEXT4;
    return 0;
}
