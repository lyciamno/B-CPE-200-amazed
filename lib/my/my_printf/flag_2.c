/*
** EPITECH PROJECT, 2023
** function
** File description:
** function
*/

#include "../../../include/my.h"
#include "../../../include/my_printf.h"

void printfo(va_list args)
{
    int o = va_arg(args, unsigned int);

    my_put_nbr_octal(o);
}

void printff(va_list args)
{
    double f = va_arg(args, double);

    my_put_float(f);
}

void printfe(va_list args)
{
    double e = va_arg(args, double);

    my_put_science(e);
}

void printfe_up(va_list args)
{
    double E = va_arg(args, double);

    my_put_majscience(E);
}

void printfu(va_list args)
{
    int u = va_arg(args, unsigned int);

    my_put_nbr_u(u);
}
