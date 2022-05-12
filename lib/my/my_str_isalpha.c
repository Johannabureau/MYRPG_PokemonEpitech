/*
** EPITECH PROJECT, 2021
** is alpha
** File description:
** return 0
*/

int my_char_is_alpha(char str)
{
    if ((str >= 'A' && str <= 'Z') || (str >= 'a' && str <= 'z')) {
        return 1;
    } else {
        return 0;
    }
}

int my_str_isalpha(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (my_char_is_alpha(str[i]) == 0) {
            return 0;
        }
        i = i + 1;
    }
    return 1;
}
