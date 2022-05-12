/*
** EPITECH PROJECT, 2021
** is_prime
** File description:
** return_prime_or_not
*/

int its_may_prime(int nb, int i)
{
    while (i != nb / 2) {
        if ((nb % i) == 0) {
            return (0);
        }
        i = i + 2;
    }
    return (1);
}

int my_is_prime(int nb)
{
    int i = 3;

    if (nb == 0 || nb == 1 || nb > 2147483647 || nb % 2 == 0) {
        return (0);
    } else {
        return (its_may_prime(nb, i));
    }
}
