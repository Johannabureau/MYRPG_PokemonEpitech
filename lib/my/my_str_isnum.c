/*
** EPITECH PROJECT, 2021
** is num
** File description:
** return O
*/

int my_char_is_num(char str)
{
    if (str >= '0' && str <= '9') {
        return 1;
    } else {
        return 0;
    }
}

int my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (my_char_is_num(str[i]) == 0) {
            return 0;
        }
        i = i + 1;
    }
    return 1;
}
