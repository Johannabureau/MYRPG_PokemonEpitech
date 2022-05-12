/*
** EPITECH PROJECT, 2021
** my_print_reval
** File description:
** revalpha
*/

void my_putchar(char c);

void my_print_revalpha(void)
{
    int print;

    print = 122;
    while (print > 96) {
        my_putchar(print);
        print = print - 1;
    }
}
