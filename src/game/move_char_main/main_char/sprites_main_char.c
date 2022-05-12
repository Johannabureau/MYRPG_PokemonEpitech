/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-johanna.bureau
** File description:
** sprites_main_char
*/

#include "move_main_char.h"
#include "rpg.h"

game_object_t *sprite_main_char_no_walk_l(game_t *game)
{
    game_object_t *i = malloc(sizeof(game_object_t));

    if (game->is_a_boy == true)
        i->texture = sfTexture_createFromFile(SP_ASH_NO_LEFT, NULL);
    else
        i->texture = sfTexture_createFromFile(SP_GIRL_NO_LEFT, NULL);

    i->sprite = sfSprite_create();
    i->clock = sfClock_create();
    i->music = NULL;
    sfSprite_setScale(i->sprite, (sfVector2f){.x = 4, .y = 4});
    sfSprite_setTexture(i->sprite, i->texture, sfFalse);
    return i;
}

game_object_t *sprite_main_char_no_walk_d(game_t *game)
{
    game_object_t *i = malloc(sizeof(game_object_t));

    if (game->is_a_boy == true)
        i->texture = sfTexture_createFromFile(SP_ASH_NO_DOWN, NULL);
    else
        i->texture = sfTexture_createFromFile(SP_GIRL_NO_DOWN, NULL);

    i->sprite = sfSprite_create();
    i->clock = sfClock_create();
    i->music = NULL;
    sfSprite_setScale(i->sprite, (sfVector2f){.x = 4, .y = 4});
    sfSprite_setTexture(i->sprite, i->texture, sfFalse);
    return i;
}

game_object_t *sprite_main_char_no_walk_u(game_t *game)
{
    game_object_t *i = malloc(sizeof(game_object_t));

    if (game->is_a_boy == true)
        i->texture = sfTexture_createFromFile(SP_ASH_NO_UP, NULL);
    else
        i->texture = sfTexture_createFromFile(SP_GIRL_NO_UP, NULL);
    i->sprite = sfSprite_create();
    i->clock = sfClock_create();
    i->music = NULL;
    sfSprite_setScale(i->sprite, (sfVector2f){.x = 4, .y = 4});
    sfSprite_setTexture(i->sprite, i->texture, sfFalse);
    return i;
}
