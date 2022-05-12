/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** load_map_sprite
*/

#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include "map.h"
#include "rpg.h"

static bool is_sprite_exist(void)
{
    const char *maps[] = {PALLET_VIRIDIAN_SP, VIRIDIAN_HOUSE_SP, PALLET_SP,
        PALLET_VIRIDIAN_TOI_SP, VIRIDIAN_ARENE, NULL};
    int fd = 0;

    for (int i = 1; maps[i] != NULL; i++) {
        fd = open(maps[i], O_RDONLY);
        if (fd < 0)
            return false;
        close(fd);
    }
    return true;
}

static bool malloc_sprite(scene_t *scene, int nb_sprite)
{
    if (scene == NULL)
        return false;
    scene->object = malloc(sizeof(game_object_t **) * 5);
    if (scene->object == NULL)
        return false;
    scene->object[0] = malloc(sizeof(game_object_t *) * (nb_sprite + 1));
    if (scene->object[0] == NULL)
        return false;
    for (int j = 0; j < nb_sprite; j++) {
        scene->object[0][j] = malloc(sizeof(game_object_t));
        if (scene->object[0][j] == NULL)
            return false;
    }
    scene->object[0][nb_sprite] = NULL;
    scene->object[4] = NULL;
    return true;
}

static bool load_map_spite(scene_t *scene, int err)
{
    if (!scene || !scene->object || !scene->object[0])
        return false;
    err += INIT_MAP(((sfIntRect){0, 0, 784, 2170}), PALLET_VIRIDIAN_SP, 0);
    err += INIT_MAP(((sfIntRect){0, 0, 185, 152}), PALLET_SP, 1);
    err += INIT_MAP(((sfIntRect){185, 0, 215, 152}), PALLET_SP, 2);
    err += INIT_MAP(((sfIntRect){0, 170, 216, 155}), PALLET_SP, 3);
    err += INIT_MAP(((sfIntRect){215, 170, 220, 220}), PALLET_SP, 4);
    err += INIT_MAP(((sfIntRect){279, 0, 241, 150}), VIRIDIAN_HOUSE_SP, 5);
    err += INIT_MAP(((sfIntRect){32, 0, 247, 150}), VIRIDIAN_HOUSE_SP, 6);
    err += INIT_MAP(((sfIntRect){0, 150, 180, 135}), VIRIDIAN_HOUSE_SP, 7);
    err += INIT_MAP(((sfIntRect){180, 150, 180, 140}), VIRIDIAN_HOUSE_SP, 8);
    err += INIT_MAP(((sfIntRect){360, 150, 180, 140}), VIRIDIAN_HOUSE_SP, 9);
    err += INIT_MAP(((sfIntRect){0, 0, 212, 200}), VIRIDIAN_ARENE, 10);
    err += INIT_MAP(((sfIntRect){0, 0, 784, 2170}),
            PALLET_VIRIDIAN_TOI_SP, PALLET_VIRIDIAN_TOIT);
    return (err > 0) ? false : true;
}

bool load_sprite_map(scene_t *scene)
{
    if (!is_sprite_exist() || !scene || !malloc_sprite(scene, NB_SPRITE) ||
            !load_map_spite(scene, 0) || !mouve_sprite_map(scene))
        return false;
    scene->index = PALLET_VIRIDIAN;
    scene->clock = sfClock_create();
    if (scene->clock == NULL)
        return false;
    return true;
}
