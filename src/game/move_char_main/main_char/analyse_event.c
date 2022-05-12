/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-johanna.bureau
** File description:
** analyse_event
*/

#include "map.h"
#include "rpg.h"
#include "move_main_char.h"

void check_png_talk(screen_t *screen, scene_t *scene)
{
    sfVector2f pos = sfSprite_getPosition(scene->object[1][2]->sprite);

    if (scene->index == OAK_LABORATORY && pos.x < 760.0 && pos.x > 540.0 &&
    pos.y < -160.0 && pos.y > -280.0 && screen->event.key.code == sfKeyX) {
        screen->scene_type = TEXT;
        scene->text = TEXT1;
    }
    return;
}

void event_mouve(screen_t *screen, scene_t *scene)
{
    if (screen->scene_type == TEXT && screen->event.key.code == sfKeyX &&
                screen->event.type == sfEvtKeyPressed) {
        screen->scene_type = GAME;
        return;
    }
    if (screen->event.type == sfEvtKeyPressed && screen->scene_type == GAME) {
        move_main_char_right(scene, screen);
        check_png_talk(screen, scene);
    }
    if (screen->event.type == sfEvtKeyReleased)
        no_move_main_char(scene, screen);
    return;
}
