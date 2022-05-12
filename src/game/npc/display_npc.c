/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-johanna.bureau
** File description:
** display_npc
*/

#include "move_main_char.h"
#include "map.h"

static void display_pokeball(scene_t *scene, screen_t *screen)
{
    if (!scene->choose[0])
        DRAW_SP_MAP(scene->object[2][5]);
    if (!scene->choose[1])
        DRAW_SP_MAP(scene->object[2][6]);
    if (!scene->choose[2])
        DRAW_SP_MAP(scene->object[2][7]);
}

void display_sp_npc(scene_t *scene, screen_t *screen)
{
    if (!scene || !screen)
        return;
    DRAW_SP_MAP(scene->object[2][0]);
    DRAW_SP_MAP(scene->object[2][1]);
    DRAW_SP_MAP(scene->object[2][8]);
    DRAW_SP_MAP(scene->object[2][9]);
    DRAW_SP_MAP(scene->object[2][10]);
    make_smoke_fireplace(screen->fb_smoke, 10, 10);
    PIX_UPDATE(screen->fb_smoke->texture, screen->fb_smoke->pixels);
    sfRenderWindow_drawSprite(screen->window, screen->fb_smoke->sprite,
            NULL);
}

int display_npc(scene_t *scene, screen_t *screen)
{
    if (scene->index == PALLET_VIRIDIAN)
        display_sp_npc(scene, screen);
    if (scene->index == OAK_LABORATORY) {
        DRAW_SP_MAP(scene->object[2][2]);
        display_pokeball(scene, screen);
    }
    if (scene->index == START_SALON)
        DRAW_SP_MAP(scene->object[2][4]);
    if (scene->index == VIR_ARENE)
        DRAW_SP_MAP(scene->object[2][11]);
    text_char(scene, screen);
    if (scene->index == PALLET_VIRIDIAN)
        DRAW_SP_MAP(scene->object[0][PALLET_VIRIDIAN_TOIT]);
    return 0;
}
