/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-johanna.bureau
** File description:
** init_game
*/

#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/Text.h>
#include <stdio.h>
#include "rpg.h"

static int init_atk(pokemon_t *pokemon)
{
    if (pokemon == NULL)
        return 84;
    for (int i = 0; i < 4; i++) {
        pokemon->atk[i].dmg = -1;
        pokemon->atk[i].font
            = sfFont_createFromFile("assets/font/base_font.ttf");
        pokemon->atk[i].text = sfText_create();
        if (pokemon->atk[i].font == NULL || pokemon->atk[i].text == NULL)
            return 84;
        sfText_setFont(pokemon->atk[i].text, pokemon->atk[i].font);
        sfText_setFillColor(pokemon->atk[i].text, sfBlack);
        sfText_setScale(pokemon->atk[i].text, (sfVector2f){2.0,2.0});
        pokemon->atk[i].name = "none";
        pokemon->atk[i].type = NONE;
    }
    return 0;
}

static int init_pokemon_stat(pokemon_t *pokemon)
{
    if (pokemon == NULL)
        return 84;
    for (int i = 0; i < 6; i++) {
        pokemon->stat[i] = -1;
        pokemon->f_stat[i] = -1;
        pokemon->stat_level[i] = -1;
    }
    pokemon->index = -1;
    pokemon->xp = -1;
    pokemon->lv = -1;
    pokemon->pdv = -1;
    pokemon->name = "none";
    pokemon->object = "none";
    return 0;
}

static int init_pokemon(pokemon_t *pokemon)
{
    if (init_atk(pokemon) == 84)
        return 84;
    for (int i = 0; i < 2; i++)
        pokemon->type[i] = NONE;
    pokemon->font = sfFont_createFromFile("assets/font/base_font.ttf");
    for (int i = 0; i < 4; i++) {
        pokemon->text[i] = sfText_create();
        if (pokemon->text[i] == NULL || pokemon->font == NULL)
            return 84;
        sfText_setFont(pokemon->text[i], pokemon->font);
        sfText_setFillColor(pokemon->text[i], sfBlack);
        sfText_setScale(pokemon->text[i], (sfVector2f){2.0,2.0});
    }
    if (init_pokemon_stat(pokemon) == 84)
        return 84;
    pokemon->sprite = sfSprite_create();
    if (pokemon->sprite == NULL)
        return 84;
    return 0;
}

static int init_game_start(game_t *game)
{
    game->start->inv = malloc(sizeof(inv_t));
    if (game->start->inv == NULL)
        return 84;
    game->start->player_name = malloc(sizeof(char) * 7);
    game->is_a_boy = true;
    for (int i = 0; i < 7; i++)
        game->start->player_name[i] = '\0';
    game->start->money = 500;
    game->start->nb_badges = 0;
    for (int i = 0; i < 6; i++)
        if (init_pokemon(&game->start->pokemon_inv[i]) == 84
                || init_pokemon(&game->enemy[i]) == 84)
            return 84;
    for (int i = 0; i < 30; i++)
        if (init_pokemon(&game->start->pokemon_box[i]) == 84)
            return 84;
    if (init_inv(game->start->inv) == 84)
        return 84;
    return 0;
}

int init_game(game_t *game)
{
    if (game == NULL)
        return 84;
    game->start = malloc(sizeof(start_t));
    game->index = 0;
    game->is_a_boy = true;
    game->your_turn = true;
    if (game->start == NULL)
        return 84;
    if (init_game_start(game) == 84)
        return 84;
    return 0;
}
