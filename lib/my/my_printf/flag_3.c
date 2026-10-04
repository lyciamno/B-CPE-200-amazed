/*
** EPITECH PROJECT, 2023
** B-CPE-101-STG-1-1-myprintf-alexandre.coelho
** File description:
** flag_3.c
*/

#include "../../../include/my.h"
#include "../../../include/my_printf.h"

void printfp(va_list args)
{
    long p = va_arg(args, unsigned long);

    my_putchar('0');
    my_putchar('x');
    my_put_nbr_hexa_lower(p);
}

void printfg(va_list args)
{
    double value = va_arg(args, double);

    my_put_g(value);
}
