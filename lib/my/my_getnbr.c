/*
** EPITECH PROJECT, 2021
** getnbg
** File description:
** return number
*/
#include <stddef.h>

int my_strlen(char const *str);
int my_put_nbr(int nb);

int count_int_lenth(int i, char const *str)
{
    int j = 1;
    int k = i;
    while (str[k] >= '0' && str[k] <= '9' && str[k] != '\0') {
        j = j * 10;
        k = k + 1;
    }
    return (j);
}

int append_nbr(int j, int i, char const *str)
{
    int number = 0;
    int k = 0;

    while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0') {
        j = j / 10;
        number = number + (str[i] - '0') * j;
        i = i + 1;
        k = k + 1;
    }
    if (k > 10)
        return (0);
    return (number);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int j = 1;
    int number = 0;
    int count = 0;

    while (str[i] != '\0' && (str[i] < '0' || str[i] > '9')) {
        if (str[i] == '-')
            count = count + 1;
        i = i + 1;
    }
    j = count_int_lenth(i, str);
    if (j == 0)
        return (0);
    number = append_nbr(j, i, str);
    if (count % 2 == 1)
        number = number * - 1;
    return (number);
}
