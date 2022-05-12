/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-johanna.bureau
** File description:
** into_g_handling
*/

#include <SFML/Graphics/Sprite.h>
#include <SFML/Window/Keyboard.h>
#include <unistd.h>
#include "rpg.h"

    static int
user_name_handling(scene_t *scene, game_t *game, screen_t *screen, int *state)
{
    if (scene == NULL || game == NULL || screen == NULL || state == NULL)
        return 84;
    key_handling(scene, screen, game ,state);
    return 0;
}

static int gender_handling(scene_t *scene, screen_t *screen, game_t *game)
{
    static bool is_top = true;
    static int i = 0;

    if (scene == NULL || game == NULL || screen == NULL)
        return 84;
    if (sfKeyboard_isKeyPressed(sfKeyReturn) && i > 5)
        screen->scene_type = GAME;
    if (sfKeyboard_isKeyPressed(sfKeyUp) && !is_top) {
        sfSprite_move(scene->object[0][2]->sprite, (sfVector2f){0.00,-75.00});
        is_top = true;
        game->is_a_boy = true;
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown) && is_top) {
        sfSprite_move(scene->object[0][2]->sprite, (sfVector2f){0.00,75.00});
        is_top = false;
        game->is_a_boy = false;
    }
    i++;
    return 0;
}

    static int
gender_handling_clock(scene_t *scene, screen_t *screen, game_t *game)
{
    float seconds = 0.0;

    if (scene == NULL || game == NULL || screen == NULL)
        return 84;
    scene->object[0][1]->time = sfClock_getElapsedTime
        (scene->object[0][1]->clock);
    seconds = scene->object[0][1]->time.microseconds / 1000000.0;
    if (seconds > 0.2) {
        if (gender_handling(scene, screen, game) == 84)
            return 84;
    }
    return 0;
}

int intro_g_handling(scene_t *scene, game_t *game, screen_t *screen)
{
    static int state = INTRO_G_NAME;

    if (scene == NULL || game == NULL)
        return 84;
    if (state == INTRO_G_NAME) {
        if (user_name_handling(scene, game, screen, &state) == 84)
            return 84;
        draw_sprite(scene->object[0][0]->sprite, screen);
        if (game->start->player_name[0] != '\0')
            sfRenderWindow_drawText
                (screen->window, scene->object[0][0]->text, NULL);
    }
    if (state == INTRO_G_GENDER) {
        if (gender_handling_clock(scene, screen, game) == 84)
            return 84;
        draw_sprite(scene->object[0][1]->sprite, screen);
        draw_sprite(scene->object[0][2]->sprite, screen);
    }
    return 0;
}
