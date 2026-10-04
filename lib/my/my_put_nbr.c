/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** lib
*/

#include "my.h"

static int negativ_nbr(int nbr1, int nbr2)
{
    if (nbr1 == -2147483648)
        my_putchar('1' + nbr2 % 10);
    else
        my_putchar('0' + nbr2 % 10);
}

int my_put_nbr(int nb)
{
    int a = nb;

    if (nb == -2147483648)
        nb = nb + 1;
    if (nb < 0) {
        nb = nb * (-1);
        my_putchar('-');
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
    }
    negativ_nbr(a, nb);
}
