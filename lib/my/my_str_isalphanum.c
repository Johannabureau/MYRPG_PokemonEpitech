/*
** EPITECH PROJECT, 2021
** is num
** File description:
** return O
*/

int my_char_is_num(char str);
int my_char_is_alpha(char str);

int my_char_isalphanum(char letter)
{
    if (my_char_is_alpha(letter) || my_char_is_num(letter))
        return 1;
    return 0;
}

int my_str_isalphanum(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (my_char_isalphanum(str[i]) == 0) {
            return 0;
        }
        i = i + 1;
    }
    return 1;
}
