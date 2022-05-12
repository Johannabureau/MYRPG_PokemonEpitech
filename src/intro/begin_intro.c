/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-johanna.bureau
** File description:
** begin_intro
*/

#include <stdio.h>
#include "rpg.h"

int begin_intro(scene_t *scene, screen_t *screen)
{
    static bool init_intro = false;

    if (init_intro == false) {
        if (load_intro(scene) == 84)
            return 84;
        init_intro = true;
    }
    intro_handling(scene, screen);
    return 0;
}
