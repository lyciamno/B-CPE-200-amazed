/*
** EPITECH PROJECT, 2023
** B-CPE-101-STG-1-1-myprintf-alexandre.coelho
** File description:
** fonction_put.c
*/

#include "../../../include/my.h"
#include "../../../include/my_printf.h"

int my_put_nbr_u(unsigned int nb)
{
    if (nb >= 0 && nb <= 9) {
        my_putchar(nb + 48);
    } else if (nb > 9) {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + 48);
    }
    return (0);
}

int my_put_float(double nb)
{
    int decimal = 0;
    int entier = nb;
    int division;

    my_put_nbr(entier);
    my_putchar('.');
    decimal = (nb - entier) * 1000001;
    if (decimal < 0) {
        decimal = -decimal;
        my_putchar('0');
    }
    division = 100000;
    for (int i = 0; i < 5; i++) {
        if (decimal < division)
            my_putchar('0');
        division = division / 10;
    }
    my_put_nbr(decimal);
}

int my_put_nbr_octal(unsigned int n)
{
    if (n < 8) {
        my_putchar('0' + n);
    } else {
        my_put_nbr_octal(n / 8);
        my_putchar('0' + (n % 8));
    }
}

int my_put_g(double nb)
{
    double absolut;

    if (nb < 0)
        absolut = -nb;
    else
        absolut = nb;
    if (absolut < 0.1 || absolut >= 1000000.0)
        my_put_science(nb);
    else
        my_put_float(nb);
}
