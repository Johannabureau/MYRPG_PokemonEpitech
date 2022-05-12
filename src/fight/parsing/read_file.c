/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-johanna.bureau
** File description:
** read_file
*/

#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include "rpg.h"
#include "my.h"

static void set_string_poke(pokemon_t *pokemon, char **file)
{
    int x = 0;
    int y = 0;

    if (!pokemon || !file)
        return;
    x = my_getnbr(file[2]);
    while (file[2][0] != ' ')
        move_by_one(file[2], 0);
    move_by_one(file[2], 0);
    y = my_getnbr(file[2]);
    sfText_setString(pokemon->text[0], my_int_to_str(pokemon->lv));
    sfText_setString(pokemon->text[1], my_int_to_str(pokemon->xp));
    sfText_setString(pokemon->text[2], my_int_to_str(pokemon->pdv));
    sfText_setString(pokemon->text[3], pokemon->name);
    pokemon->texture = sfTexture_createFromFile(file[4],
            &(sfIntRect){x, y, 80, 80});
    sfSprite_setTexture(pokemon->sprite, pokemon->texture, sfTrue);
    sfSprite_setScale(pokemon->sprite, (sfVector2f){5, 5});
}

static int parse_poke_file(char **file, pokemon_t *pokemon)
{
    int lv = 0;

    if (!file || !pokemon)
        return 84;
    pokemon->name = file[0];
    pokemon->index = my_getnbr(file[6]);
    pokemon->pdv = my_getnbr(file[8]);
    pokemon->lv = my_getnbr(file[22]);
    pokemon->xp = my_getnbr(file[24]);
    lv = pokemon->lv;
    for (int i = 0; i < 6; i++) {
        pokemon->f_stat[i] = my_getnbr(file[8 + i]);
        pokemon->stat_level[i] = my_getnbr(file[15 + i]);
        pokemon->stat[i] = pokemon->f_stat[i] + (pokemon->stat_level[i] * lv);
    }
    if (!check_type(pokemon, file[26]) || check_atk(pokemon, file + 28) == 84)
        return 84;
    set_string_poke(pokemon, file);
    return 0;
}

static int read_poke_file(char *name, pokemon_t *pokemon)
{
    char buf[1024];
    int fd = open(name, O_RDONLY);
    int size = 0;

    if (fd == -1 || (size = read(fd, buf, 1024)) == -1)
        return 84;
    buf[size] = '\0';
    return parse_poke_file(my_str_to_word_array(buf), pokemon);
}

int read_poke_dir(pokemon_t *pokemon, char *filename)
{
    if (!pokemon)
        return 84;
    read_poke_file(my_strcat("assets/pokemon/stat/", filename), pokemon);
    return 0;
}
