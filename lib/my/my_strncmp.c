/*
** EPITECH PROJECT, 2021
** my_strncmp
** File description:
** return value as 3 strcmp
*/

int my_strcmp(char const *s1, char const *s2);

int my_strncmp(char const *s1, char const *s2, int n)
{
    char s3[n];
    char s4[n];
    int i = 0;
    int j = 0;

    while (i != n) {
        s3[i] = s1[i];
        i = i + 1;
    }
    while (j != n) {
        s4[i] = s2[j];
        j = j + 1;
    }
    return (my_strcmp(s3, s4));
}
