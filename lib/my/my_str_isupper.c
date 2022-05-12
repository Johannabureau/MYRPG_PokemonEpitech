/*
** EPITECH PROJECT, 2021
** is upper
** File description:
** return 0
*/

int my_char_is_upper(char str)
{
    if (str >= 'A' && str <= 'Z') {
        return 1;
    } else {
        return 0;
    }
}

int my_str_isupper(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (my_char_is_upper(str[i]) == 0) {
            return 0;
        }
        i = i + 1;
    }
    return 1;
}
