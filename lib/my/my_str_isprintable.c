/*
** EPITECH PROJECT, 2021
** is printable
** File description:
** return 0
*/

int my_char_is_printable(char str)
{
    if (str >= ' ' && str <= '~') {
        return 1;
    } else {
        return 0;
    }
}

int my_str_isprintable(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (my_char_is_printable(str[i]) == 0) {
            return 0;
        }
        i = i + 1;
    }
    return 1;
}
