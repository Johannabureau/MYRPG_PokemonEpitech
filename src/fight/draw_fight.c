/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-johanna.bureau
** File description:
** draw_fight
*/

#include <SFML/Config.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Text.h>
#include "rpg.h"
#include "my.h"

static int set_atk_pos(game_t *game)
{
    if (game == NULL || game->start == NULL)
        return 84;
    if (game->start->pokemon_inv[0].atk[0].dmg != -1)
        sfText_setPosition(game->start->pokemon_inv[0].atk[0].text,
                (sfVector2f){100.0, 800.0});
    if (game->start->pokemon_inv[0].atk[1].dmg != -1)
        sfText_setPosition(game->start->pokemon_inv[0].atk[1].text,
                (sfVector2f){500.0, 800.0});
    if (game->start->pokemon_inv[0].atk[2].dmg != -1)
        sfText_setPosition(game->start->pokemon_inv[0].atk[2].text,
                (sfVector2f){100.0, 950.0});
    if (game->start->pokemon_inv[0].atk[3].dmg != -1)
        sfText_setPosition(game->start->pokemon_inv[0].atk[3].text,
                (sfVector2f){500.0, 950.0});
    return 0;
}

static int refresh_string(game_t *game)
{
    if (game == NULL || game->start == NULL)
        return 84;
    sfText_setString(game->enemy[0].text[3], game->enemy[0].name);
    sfText_setString(game->start->pokemon_inv[0].text[3],
            game->start->pokemon_inv[0].name);
    sfText_setString(game->start->pokemon_inv[0].text[2],
            my_int_to_str(game->start->pokemon_inv[0].pdv));
    sfText_setString(game->start->pokemon_inv[0].text[0],
            my_int_to_str(game->start->pokemon_inv[0].lv));
    sfText_setString(game->enemy[0].text[2],
            my_int_to_str(game->enemy[0].pdv));
    return 0;
}

static int set_text_pos(game_t *game)
{
    if (game == NULL || game->start == NULL)
        return 84;
    sfText_setPosition(game->enemy[0].text[0], (sfVector2f){1050,100});
    sfText_setPosition(game->enemy[0].text[1], (sfVector2f){-1050,130});
    sfText_setPosition(game->enemy[0].text[2], (sfVector2f){730,150});
    sfText_setPosition(game->enemy[0].text[3], (sfVector2f){750,100});
    sfText_setPosition(game->start->pokemon_inv[0].text[0],
            (sfVector2f){1845,525});
    sfText_setPosition(game->start->pokemon_inv[0].text[1],
            (sfVector2f){-1845,525});
    sfText_setPosition(game->start->pokemon_inv[0].text[2],
            (sfVector2f){1400,565});
    sfText_setPosition(game->start->pokemon_inv[0].text[3],
            (sfVector2f){1400,495});
    if (refresh_string(game) == 84)
        return 84;
    return 0;
}

static int set_sp_pos(game_t *game)
{
    if (game == NULL)
        return 84;
    sfSprite_setPosition(game->start->pokemon_inv[0].sprite,
            (sfVector2f){385, 419});
    sfSprite_setScale(game->start->pokemon_inv[0].sprite, (sfVector2f){4, 4});
    sfSprite_setPosition(game->enemy[0].sprite, (sfVector2f){1165, 165});
    sfSprite_setScale(game->enemy[0].sprite, (sfVector2f){4, 4});
    return 0;
}

int draw_fight(scene_t *scene, game_t *game, screen_t *screen)
{
    if (!scene || !game || !screen || !game->start)
        return 84;
    draw_sprite(scene->object[0][0]->sprite, screen);
    draw_sprite(scene->object[0][1]->sprite, screen);
    draw_sprite(game->start->pokemon_inv[0].sprite, screen);
    draw_sprite(game->enemy[0].sprite, screen);
    if (set_text_pos(game) == 84 || set_atk_pos(game) == 84 ||
            set_sp_pos(game) == 84)
        return 84;
    for (int i = 0; i < 4; i++) {
        sfRenderWindow_drawText(screen->window, game->enemy[0].text[i], NULL);
        sfRenderWindow_drawText
            (screen->window, game->start->pokemon_inv[0].text[i], NULL);
        if (my_strcmp(game->start->pokemon_inv[0].atk[i].name, "none") != 0)
            sfRenderWindow_drawText(screen->window,
                    game->start->pokemon_inv[0].atk[i].text, NULL);
    }
    return 0;
}
