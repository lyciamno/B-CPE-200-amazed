/*
** EPITECH PROJECT, 2023
** B-CPE-101-STG-1-1-myprintf-alexandre.coelho
** File description:
** function_science.c
*/

#include "../../../include/my.h"
#include "../../../include/my_printf.h"

static int my_sup_science(double nb, int c)
{
    my_put_float(nb);
    my_putstr("e+");
    if (c < 10)
        my_putchar('0');
    my_put_nbr(c);
}

static int my_min_science(double nb, int c)
{
    my_put_float(nb);
    my_putstr("e-");
    if (c < 10)
        my_putchar('0');
    my_put_nbr(c);
}

int my_put_science(double nb)
{
    int c = 0;

    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    if (nb < 1) {
        while (nb < 1) {
            nb = nb * 10;
            c++;
        }
        my_min_science(nb, c);
    } else {
        while (nb > 10) {
            nb = nb / 10;
            c++;
        }
        my_sup_science(nb, c);
    }
}

static int my_sup_science2(double nb, int cpt)
{
    my_put_float(nb);
    my_putstr("E+");
    if (cpt < 10)
        my_putchar('0');
    my_put_nbr(cpt);
}

static int my_min_science2(double nb, int cpt)
{
    my_put_float(nb);
    my_putstr("E-");
    if (cpt < 10)
        my_putchar('0');
    my_put_nbr(cpt);
}

int my_put_majscience(double nb)
{
    int cpt = 0;

    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    if (nb < 1) {
        while (nb < 1) {
            nb = nb * 10;
            cpt++;
        }
        my_min_science2(nb, cpt);
    } else {
        while (nb > 10) {
            nb = nb / 10;
            cpt++;
        }
        my_sup_science2(nb, cpt);
    }
}
