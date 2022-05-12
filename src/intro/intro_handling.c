/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-johanna.bureau
** File description:
** intro_handling
*/

#include <SFML/System/Clock.h>
#include <SFML/Window/Keyboard.h>
#include "rpg.h"

static void intro_anim(game_object_t *object)
{
    float seconds = 0.0;
    sfIntRect rect;

    rect.width = 385;
    rect.height = 216;
    object->time = sfClock_getElapsedTime(object->clock);
    seconds = object->time.microseconds / 1000000.0;
    if (seconds > 0.1337) {
        if (object->left >= 16170) {
            object->left = 0;
            object->top += 216;
        }
        rect.left = object->left;
        rect.top = object->top;
        sfSprite_setTextureRect(object->sprite, rect);
        object->left += 385;
        sfClock_restart(object->clock);
    }
    return;
}

static int check_time(scene_t *scene, int intro, screen_t *screen)
{
    float seconds = 0.00;

    scene->time = sfClock_getElapsedTime(scene->clock);
    seconds = scene->time.microseconds / 1000000.0;
    if (seconds > 0.1) {
        if (sfKeyboard_isKeyPressed(sfKeyB) && intro == INTRO_2) {
            sfMusic_stop(scene->object[0][1]->music);
            screen->scene_type = MENU;
        }
        if ((sfKeyboard_isKeyPressed(sfKeyB) ||
                    (scene->object[0][0]->top >= 860))
                && screen->scene_type == INTRO_1) {
            sfMusic_stop(scene->object[0][0]->music);
            intro = INTRO_2;
            scene->object[0][0]->top = 0;
            sfMusic_play(scene->object[0][1]->music);
        }
        sfClock_restart(scene->clock);
    }
    return intro;
}

static int check_intro(scene_t *scene, screen_t *screen, int intro)
{
    if (intro == INTRO_2) {
        intro_anim(scene->object[0][1]);
        draw_sprite(scene->object[0][1]->sprite, screen);
    }
    if (intro == INTRO_1) {
        intro_anim(scene->object[0][0]);
        draw_sprite(scene->object[0][0]->sprite, screen);
    }
    intro = check_time(scene, intro, screen);
    return intro;
}

int intro_handling(scene_t *scene, screen_t *screen)
{
    static int intro = INTRO_1;

    intro = check_intro(scene, screen, intro);
    if (intro == INTRO_2)
        if (scene->object[0][1]->top >= 640)
            scene->object[0][1]->top = 216;
    return 0;
}
