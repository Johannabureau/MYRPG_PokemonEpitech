/*
** EPITECH PROJECT, 2021
** square_root
** File description:
** comput_square_root
*/

int my_compute_square_root(int nb)
{
    int squared = 1;
    while (squared * squared != nb) {
        if (squared == (nb / 2)) {
            return (0);
        } else if (squared < 0) {
            return (0);
        } else {
            squared = squared + 1;
        }
    }
    return (squared);
}
