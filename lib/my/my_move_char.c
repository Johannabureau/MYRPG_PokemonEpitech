/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-leandre.godet
** File description:
** my_move_char
*/

char *my_move_char_by_one(char *str, int pos)
{
    while (str[pos] != '\0') {
        str[pos] = str[pos + 1];
        pos += 1;
    }
    return str;
}
