/*
** EPITECH PROJECT, 2021
** my_print_digits
** File description:
** print digit
*/

void my_putchar(char c);

void my_print_digits(void)
{
    int print;

    print = 48;
    while (print < 58) {
        my_putchar(print);
        print = print + 1;
    }
    my_putchar('\n');
}
