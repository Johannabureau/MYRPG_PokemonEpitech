/*
** EPITECH PROJECT, 2021
** my_swap
** File description:
** swap two number
*/

void my_putchar(char c);

void my_swap(int *a, int *b)
{
    int c = *a;

    *a = *b;
    *b = c;
}
