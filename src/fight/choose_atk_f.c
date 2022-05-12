/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-johanna.bureau
** File description:
** choose_atk_f
*/

#include "rpg.h"
#include <SFML/Graphics/Sprite.h>
#include <SFML/Window/Keyboard.h>

static int move_arrow_up_down_f(game_object_t *object, bool *is_top)
{
    if (object == NULL)
        return 84;
    if (sfKeyboard_isKeyPressed(sfKeyUp) && *is_top == false) {
        sfSprite_move(object->sprite, (sfVector2f){0.00, -100.00});
        is_top[0] = true;
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown) && *is_top == true) {
        sfSprite_move(object->sprite, (sfVector2f){0.00, 100.00});
        is_top[0] = false;
    }
    return 0;
}

static int move_arrow_left_right_f(game_object_t *object, bool *is_left)
{
    if (object == NULL)
        return 84;
    if (sfKeyboard_isKeyPressed(sfKeyLeft) && *is_left == false) {
        sfSprite_move(object->sprite, (sfVector2f){-360.00, 0.00});
        is_left[0] = true;
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight) && *is_left == true) {
        sfSprite_move(object->sprite, (sfVector2f){360.00, 0.00});
        is_left[0] = false;
    }
    return 0;
}

    static int is_decided_second
(bool *is_top, bool *is_left, scene_t *scene, game_t *game)
{
    if (scene == NULL || game == NULL || is_top == NULL || is_left == NULL)
        return 84;
    if (sfKeyboard_isKeyPressed(sfKeyReturn) && *is_top
            == false && *is_left == true) {
        game->your_turn = false;
        if (atk_player(game, &game->start->pokemon_inv[0].atk[2]) == 84)
            return 84;
    }
    if (sfKeyboard_isKeyPressed(sfKeyReturn) && *is_top
            == true && *is_left == true) {
        game->your_turn = false;
        if (atk_player(game, &game->start->pokemon_inv[0].atk[0]) == 84)
            return 84;
    }
    return 0;
}

    static int is_decided
(bool *is_top, bool *is_left, scene_t *scene, game_t *game)
{
    if (scene == NULL || game == NULL || is_top == NULL || is_left == NULL)
        return 84;
    if (sfKeyboard_isKeyPressed(sfKeyReturn) && *is_top
            == false && *is_left == false) {
        game->your_turn = false;
        if (atk_player(game, &game->start->pokemon_inv[0].atk[3]) == 84)
            return 84;
    }
    if (sfKeyboard_isKeyPressed(sfKeyReturn) && *is_top
            == true && *is_left == false) {
        game->your_turn = false;
        if (atk_player(game, &game->start->pokemon_inv[0].atk[1]) == 84)
            return 84;
    }
    if (is_decided_second(is_top, is_left, scene, game) == 84)
        return 84;
    return 0;
}

int choose_atk_f(game_t *game, scene_t *scene, screen_t *screen, int *status)
{
    static bool is_top = true;
    static bool is_left = true;

    if (game == NULL || scene == NULL || screen == NULL || status == NULL)
        return 84;
    if (move_arrow_up_down_f(scene->object[0][1], &is_top) == 84 ||
            move_arrow_left_right_f(scene->object[0][1], &is_left) == 84)
        return 84;
    if (is_decided(&is_top, &is_left, scene, game) == 84)
        return 84;
    if (sfKeyboard_isKeyPressed(sfKeyB)) {
        sfSprite_setPosition(scene->object[0][1]->sprite,
                (sfVector2f){1135, 800});
        status[0] = FI_CHOICE;
        is_top = true;
        is_left = true;
    }
    return 0;
}
