/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-johanna.bureau
** File description:
** keybord_handling
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Keyboard.h>
#include <stdio.h>
#include "rpg.h"
#include "my.h"

static bool check_if_visible(screen_t *screen)
{
    char c = '\0';
    if (screen == NULL)
        return true;
    c = screen->event.text.unicode;
    if (c == 127 || sfKeyboard_isKeyPressed(sfKeyBackspace))
        return true;
    if ((c >= 0 && c < '0') || (c > '9' && c < 'A') ||
            (c > 'Z' && c < 'a') || (c > 'z' && c < 127))
        return false;
    return true;
}

    static int check_key
(screen_t *screen, game_t *game, int *i, scene_t *scene)
{
    if (screen == NULL || game == NULL || i == NULL || scene == NULL)
        return 84;
    if (check_if_visible(screen) == false)
        return 0;
    game->start->player_name[*i] = screen->event.text.unicode;
    sfClock_restart(scene->object[0][0]->clock);
    if ((screen->event.text.unicode == 127 ||
                sfKeyboard_isKeyPressed(sfKeyBackspace)) && *i > 0) {
        game->start->player_name[*i] = '\0';
        i[0]--;
        game->start->player_name[*i] = '\0';
        return 0;
    }
    i[0]++;
    return 0;
}

    static int set_clok_name
(screen_t *screen, game_t *game, int *state, scene_t *scene)
{
    static int i = 0;

    if (screen == NULL || game == NULL || state == NULL || scene == NULL)
        return 84;
    if (screen->event.type == sfEvtTextEntered) {
        if ((sfKeyboard_isKeyPressed(sfKeyReturn) || i >= 6) && i != 0) {
            state[0] = INTRO_G_GENDER;
            return 0;
        }
        if (check_key(screen, game, &i, scene) == 84)
            return 84;
    }
    return 0;
}

int key_handling(scene_t *scene, screen_t *screen, game_t *game, int *state)
{
    float seconds = 0.0;

    if (scene == NULL || screen == NULL || game == NULL)
        return 84;
    if (game->start->player_name == NULL)
        return 84;
    scene->object[0][0]->time = sfClock_getElapsedTime
        (scene->object[0][0]->clock);
    seconds = scene->object[0][0]->time.microseconds / 1000000.0;
    if (seconds > 0.2) {
        if (set_clok_name(screen, game, state, scene) == 84)
            return 84;
        sfText_setString(scene->object[0][0]->text, game->start->player_name);
    }
    return 0;
}
