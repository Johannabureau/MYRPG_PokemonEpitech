/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-johanna.bureau
** File description:
** choose_option_f
*/

#include "rpg.h"

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

static int is_decided(bool is_top, bool is_left, scene_t *scene, int *status)
{
    if (scene == NULL || status == NULL)
        return 84;
    if (sfKeyboard_isKeyPressed(sfKeyReturn) && is_top
            == true && is_left == false)
        status[0] = FI_BAG;
    if (sfKeyboard_isKeyPressed(sfKeyReturn) && is_top
            == false && is_left == true)
        status[0] = FI_POKEMON;
    if (sfKeyboard_isKeyPressed(sfKeyReturn) && is_top
            == true && is_left == true) {
        status[0] = FI_ATK;
        sfSprite_move(scene->object[0][1]->sprite, (sfVector2f){-1100.00,0.0});
    }
    return 0;
}

    int choose_option_f
(game_t *game, scene_t *scene, screen_t *screen, int *status)
{
    static bool is_top = true;
    static bool is_left = true;

    if (game == NULL || scene == NULL || screen == NULL || status == NULL)
        return 84;
    if (move_arrow_up_down_f(scene->object[0][1], &is_top) == 84 ||
            move_arrow_left_right_f(scene->object[0][1], &is_left) == 84)
        return 84;
    if (is_decided(is_top, is_left, scene, status) == 84)
        return 84;
    if (sfKeyboard_isKeyPressed(sfKeyReturn) && is_top
            == false && is_left == false) {
        screen->scene_type = GAME;
        sfRenderWindow_setView(screen->window, screen->view);
    }
    return 0;
}
