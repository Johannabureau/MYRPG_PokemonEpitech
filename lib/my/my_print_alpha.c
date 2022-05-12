/*
** EPITECH PROJECT, 2021
** my_print_alpha
** File description:
** alpha
*/

void my_putchar(char c);

void my_print_alpha(void)
{
    int print;

    print = 97;
    while (print < 123) {
        my_putchar(print);
        print = print + 1;
    }
}
