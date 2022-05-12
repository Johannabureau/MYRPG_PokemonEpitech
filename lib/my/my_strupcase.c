/*
** EPITECH PROJECT, 2021
** my_strupcase
** File description:
** upcase
*/

char *my_strupcase(char *str)
{
    int i = 0;
    int temp = 0;

    while (str[i] != '\0') {
        temp = str[i];
        if (97 < temp && temp > 122) {
            str[i] = temp - 32;
        }
        i = i + 1;
    }
    temp = str[i];
    return (str);
}
