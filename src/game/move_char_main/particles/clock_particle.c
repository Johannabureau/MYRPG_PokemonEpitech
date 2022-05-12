/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-johanna.bureau
** File description:
** clock_particle
*/

#include "rpg.h"
#include "move_main_char.h"

int clock_particle(scene_t *scene, screen_t *screen, game_t *game)
{
    static sfTime time;
    float seg = 0.0;
    static sfClock *clock = NULL;

    if (clock == NULL)
        clock = sfClock_create();
    if (clock == NULL)
        return 84;
    time = COLCK_ELAPSE(clock);
    seg = time.microseconds / 1000000.0;
    if (seg > 0.02) {
        load_particle(screen, scene, game);
        sfClock_restart(clock);
    }
    return 0;
}
