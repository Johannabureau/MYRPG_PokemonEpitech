/*
** EPITECH PROJECT, 2021
** my_strupcase
** File description:
** upcase
*/

char *my_strlowcase(char *str)
{
    int i = 0;
    int temp = 0;

    while (str[i] != '\0') {
        temp = str[i];
        if ( temp >= 65 && temp <= 90) {
            str[i] = temp + 32;
        }
        i = i + 1;
    }
    return (str);
}
