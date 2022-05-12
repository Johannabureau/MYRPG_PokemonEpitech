/*
** EPITECH PROJECT, 2021
** islower
** File description:
** return o
*/

int my_char_is_lower(char str)
{
    if (str >= 'a' && str <= 'z') {
        return 1;
    } else {
        return 0;
    }
}

int my_str_islower(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (my_char_is_lower(str[i]) == 0) {
            return 0;
        }
        i = i + 1;
    }
    return 1;
}
