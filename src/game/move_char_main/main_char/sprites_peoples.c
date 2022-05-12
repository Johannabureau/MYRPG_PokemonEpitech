/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-johanna.bureau
** File description:
** srpties_peoples
*/

#include "rpg.h"
#include "move_main_char.h"

game_object_t *sprite_main_char_left(game_t *game)
{
    game_object_t *i = malloc(sizeof(game_object_t));

    if (game->is_a_boy == true) {
        i->texture = sfTexture_createFromFile(SP_ASH_LEFT, NULL);
    } else
        i->texture = sfTexture_createFromFile(SP_GIRL_LEFT, NULL);
    i->sprite = sfSprite_create();
    i->rect = (sfIntRect){.left = 0, .top = 0, .height = 40, .width = 19};
    i->clock = sfClock_create();
    i->music = NULL;
    sfSprite_setScale(i->sprite, (sfVector2f){.x = 4, .y = 4});
    sfSprite_setTexture(i->sprite, i->texture, sfFalse);
    return i;
}

game_object_t *sprites_main_char_right(game_t *game)
{
    game_object_t *j = malloc(sizeof(game_object_t));

    if (game->is_a_boy == true)
        j->texture = sfTexture_createFromFile(SP_ASH_RIGHT, NULL);
    else
        j->texture = sfTexture_createFromFile(SP_GIRL_RIGHT, NULL);
    j->sprite = sfSprite_create();
    j->rect = (sfIntRect){.left = 0, .top = 0, .height = 40, .width = 18};
    j->music = NULL;
    j->clock = sfClock_create();
    sfSprite_setScale(j->sprite, (sfVector2f){.x = 4, .y = 4});
    sfSprite_setTexture(j->sprite, j->texture, sfFalse);
    return j;
}

game_object_t *sprites_main_char_dow(game_t *game)
{
    game_object_t *i = malloc(sizeof(game_object_t));

    if (game->is_a_boy == true)
        i->texture = sfTexture_createFromFile(SP_ASH_DOWN, NULL);
    else
        i->texture = sfTexture_createFromFile(SP_GIRL_DOWN, NULL);
    i->sprite = sfSprite_create();
    i->rect = (sfIntRect){.left = 20, .top = 0, .height = 20, .width = 17};
    i->music = NULL;
    i->clock = sfClock_create();
    sfSprite_setScale(i->sprite, (sfVector2f){.x = 4, .y = 4});
    sfSprite_setTexture(i->sprite, i->texture, sfFalse);
    return i;
}

game_object_t *sprites_main_char_up(game_t *game)
{
    game_object_t *i = malloc(sizeof(game_object_t));

    if (game->is_a_boy == true)
        i->texture = sfTexture_createFromFile(SP_ASH_UP, NULL);
    else
        i->texture = sfTexture_createFromFile(SP_GIRL_UP, NULL);
    i->sprite = sfSprite_create();
    i->rect = (sfIntRect){.left = 0, .top = 0, .width = 17, .height = 40};
    i->music = NULL;
    i->clock = sfClock_create();
    sfSprite_setScale(i->sprite, (sfVector2f){.x = 4, .y = 4});
    sfSprite_setTexture(i->sprite, i->texture, sfFalse);
    return i;
}

game_object_t *sprite_main_char_no_walk_r(game_t *game)
{
    game_object_t *i = malloc(sizeof(game_object_t));

    if (game->is_a_boy == true)
        i->texture = sfTexture_createFromFile(SP_ASH_NO_RIGHT, NULL);
    else
        i->texture = sfTexture_createFromFile(SP_GIRL_NO_RIGHT, NULL);
    i->sprite = sfSprite_create();
    i->clock = sfClock_create();
    i->music = NULL;
    sfSprite_setScale(i->sprite, (sfVector2f){.x = 4, .y = 4});
    sfSprite_setTexture(i->sprite, i->texture, sfFalse);
    return i;
}
