/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-johanna.bureau
** File description:
** load_npc
*/

#include "rpg.h"
#include "move_main_char.h"

static bool malloc_sprite(scene_t *scene)
{
    scene->object[2] = malloc(sizeof(game_object_t *) * 20);
    if (scene->object[2] == NULL)
        return false;
    for (int j = 0; j < 20; j++) {
        scene->object[2][j] = malloc(sizeof(game_object_t));
        if (scene->object[2][j] == NULL)
            return false;
    }
    return true;
}

static void scale_sprite_setposition(scene_t *scene)
{
    sfSprite_scale(scene->object[2][0]->sprite, (sfVector2f){4, 4});
    sfSprite_setPosition(scene->object[2][0]->sprite, (sfVector2f){500, 550});
    sfSprite_scale(scene->object[2][1]->sprite, (sfVector2f){4, 4});
    sfSprite_setPosition(scene->object[2][1]->sprite, (sfVector2f){200, 300});
    sfSprite_scale(scene->object[2][2]->sprite, (sfVector2f){4, 4});
    sfSprite_setPosition(scene->object[2][2]->sprite, (sfVector2f){600, -220});
    sfSprite_scale(scene->object[2][3]->sprite, (sfVector2f){4, 4});
    sfSprite_setPosition(scene->object[2][3]->sprite, (sfVector2f){-200, 150});
    sfSprite_scale(scene->object[2][4]->sprite, (sfVector2f){4, 4});
    sfSprite_setPosition(scene->object[2][4]->sprite, (sfVector2f){250, -300});
    sfSprite_scale(scene->object[2][5]->sprite, (sfVector2f){2, 2});
    sfSprite_setPosition(scene->object[2][5]->sprite, (sfVector2f){790, -200});
    sfSprite_scale(scene->object[2][6]->sprite, (sfVector2f){2, 2});
    sfSprite_setPosition(scene->object[2][6]->sprite, (sfVector2f){855, -200});
    sfSprite_scale(scene->object[2][7]->sprite, (sfVector2f){2, 2});
    sfSprite_setPosition(scene->object[2][7]->sprite, (sfVector2f){920, -200});
    sfSprite_scale(scene->object[2][8]->sprite, (sfVector2f){4, 4});
    sfSprite_setPosition(scene->object[2][8]->sprite, (sfVector2f){420, -980});
}

static void scale_sprite_setposition_vilain(scene_t *scene)
{
    sfSprite_scale(scene->object[2][9]->sprite, (sfVector2f){4, 4});
    sfSprite_setPosition(scene->object[2][9]->sprite,
            (sfVector2f){-150, -1650});
    sfSprite_scale(scene->object[2][10]->sprite, (sfVector2f){4, 4});
    sfSprite_setPosition(scene->object[2][10]->sprite,
            (sfVector2f){550, -2950});

    sfSprite_scale(scene->object[2][11]->sprite, (sfVector2f){4, 4});
    sfSprite_setPosition(scene->object[2][11]->sprite,
            (sfVector2f){1164, -5328});
    return;
}

static bool init_npc(scene_t *scene)
{
    int err = 0;

    err += INIT_NPC(((sfIntRect){0, 0, 17, 22}), SP_NPC_PALLET_1, 0);
    err += INIT_NPC(((sfIntRect){0, 0, 17, 22}), SP_NPC_PALLET_2, 1);
    err += INIT_NPC(((sfIntRect){0, 0, 17, 22}), SP_NPC_PALLET_3, 2);
    err += INIT_NPC(((sfIntRect){0, 0, 130, 49}), SP_TEXT_FRAME, 3);
    err += INIT_NPC(((sfIntRect){0, 0, 17, 22}), SP_NPC_PALLET_4, 4);
    err += INIT_NPC(((sfIntRect){0, 0, 17, 22}), SP_POKEBALL_PALLET, 5);
    err += INIT_NPC(((sfIntRect){0, 0, 17, 22}), SP_POKEBALL_PALLET, 6);
    err += INIT_NPC(((sfIntRect){0, 0, 17, 22}), SP_POKEBALL_PALLET, 7);
    err += INIT_NPC(((sfIntRect){0, 0, 17, 22}), SP_NCP_VILAIN_1, 8);
    err += INIT_NPC(((sfIntRect){0, 0, 17, 22}), SP_NCP_VILAIN_2, 9);
    err += INIT_NPC(((sfIntRect){0, 0, 17, 22}), SP_NCP_VILAIN_3, 10);
    err += INIT_NPC(((sfIntRect){0, 0, 17, 22}), SP_BOSS, 11);
    return (err > 0) ? false : true;
}

bool load_sprite(scene_t *scene)
{
    int err = 0;

    malloc_sprite(scene);
    if (!scene->object || !scene || !scene->object[2])
        return false;
    init_npc(scene);
    scale_sprite_setposition_vilain(scene);
    scale_sprite_setposition(scene);
    return (err > 0) ? false : true;
}
