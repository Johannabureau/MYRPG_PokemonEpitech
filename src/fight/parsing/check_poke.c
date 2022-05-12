/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-johanna.bureau
** File description:
** type_poke
*/

#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"
#include "rpg.h"

void move_by_one(char *str, int i)
{
    if (str == NULL)
        return;
    while (str[i] != '\0') {
        str[i] = str[i + 1];
        i += 1;
    }
}

bool check_type(pokemon_t *pokemon, char *type)
{
    int slash = 0;

    if (!pokemon || !type)
        return false;
    for (int i = 0; type[i] != '\0'; i += 1)
        if (type[i] == '/')
            slash += 1;
    pokemon->type[0] = my_getnbr(type);
    if (slash == 0)
        return true;
    while (type[0] != '/')
        move_by_one(type, 0);
    move_by_one(type, 0);
    pokemon->type[1] = my_getnbr(type);
    return true;
}

static int parse_atk(pokemon_t *pokemon, char *filename, int nb)
{
    char buf[1024];
    char **tab = NULL;
    int fd = 0;
    int size = 0;

    if (pokemon == NULL)
        return 84;
    fd = open(my_strcat("assets/pokemon/atk/", filename), O_RDONLY);
    if (fd < -1 || (size = read(fd, buf, 1024)) < 0)
        return 84;
    buf[size] = '\0';
    tab = my_str_to_word_array(buf);
    if (!tab[0] || !tab[1] || !tab[2] || !tab[3] || !tab[4] || tab[5])
        return 84;
    pokemon->atk[nb].name = tab[0];
    pokemon->atk[nb].dmg = my_getnbr(tab[2]);
    pokemon->atk[nb].type = my_getnbr(tab[4]);
    return 0;
}

int check_atk(pokemon_t *pokemon, char **atks)
{
    DIR *dir = opendir("assets/pokemon/atk");

    if (!pokemon || !atks || !dir)
        return 84;
    closedir(dir);
    for (int i = 0; atks[i] != NULL; i++) {
        if (parse_atk(pokemon, atks[i], i) == 84)
            return 84;
        sfText_setString(pokemon->atk[i].text, pokemon->atk[i].name);
    }
    return 0;
}
