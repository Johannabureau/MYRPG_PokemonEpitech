/*
** EPITECH PROJECT, 2021
** prome_sup
** File description:
** find prime numbre sup
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    if (my_is_prime(nb) == 1) {
        return (nb);
    } else {
        my_find_prime_sup(nb +1);
    }
    return 0;
}
