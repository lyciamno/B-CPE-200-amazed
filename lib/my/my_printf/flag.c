/*
** EPITECH PROJECT, 2023
** function
** File description:
** function
*/

#include "../../../include/my.h"
#include "../../../include/my_printf.h"

void printfs(va_list args)
{
    char *str = va_arg(args, char *);

    my_putstr(str);
}

void printfc(va_list args)
{
    int c = va_arg(args, int);

    my_putchar(c);
}

void printfd(va_list args)
{
    my_put_nbr(va_arg(args, int));
}

void printfi(va_list args)
{
    int i = va_arg(args, int);

    my_put_nbr(i);
}

void printfpc(va_list args)
{
    my_putchar('%');
}
