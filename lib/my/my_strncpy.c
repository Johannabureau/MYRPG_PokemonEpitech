/*
** EPITECH PROJECT, 2021
** strncpy
** File description:
** copy n char from a string
*/

int my_strlen(const char *str);

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (i != n) {
        if (i > my_strlen(src)) {
            dest[i] = '\0';
        } else {
            dest[i] = src[i];
        }
        i = i + 1;
    }
    dest[i] = '\0';
    return dest;
}
