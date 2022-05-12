/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** load_map
*/

#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include "map.h"
#include "rpg.h"
#include "my.h"

static bool load_map_in_mem(game_t *game, int fd, int index)
{
    char *file = malloc(sizeof(char) * 10024);
    int size = 0;

    if (fd < 0 || !file || !game) {
        free(file);
        close(fd);
        return false;
    }
    size = read(fd, file, 10024);
    if (size < 0)
        return false;
    file[size] = '\0';
    game->map[index] = my_load_inmem_array(file);
    close(fd);
    free(file);
    return true;
}

static bool check_map_exist(game_t *game)
{
    const char *maps[] = {MAP_PELLET_VIRIDIAN, SALON_START, SALON_RIVAL,
        OAK_LAB, VIRIDIAN_PC_DOWN, VIRIDIAN_MART, VIRIDIAN_HOOSE1,
        VIRIDIAN_HOOSE2, R2_PEWTER, CHAMBRE_START, VIRIDIAN_PC_UP,
        ARENE_MAP, NULL};
    int fd = 0;

    for (int i = 0; maps[i] != NULL; i++) {
        fd = open(maps[i], O_RDONLY);
        if (!load_map_in_mem(game, fd, i))
            return false;
    }
    return true;
}

int initialize_map(game_t *game, scene_t *scene)
{
    game->map = malloc(sizeof(char **) * 14);

    if (!check_map_exist(game))
        return 84;
    game->map[13] = NULL;
    game->index = 0;
    game->player_start = get_player_pos(game);
    game->player_pos.x = 0;
    game->player_pos.y = 0;
    game->as_a_pokemon = false;
    if (!load_sprite_map(scene))
        return 84;
    scene->object[0][0]->clock = sfClock_create();
    return 0;
}
