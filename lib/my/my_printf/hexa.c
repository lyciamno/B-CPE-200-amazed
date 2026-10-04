/*
** EPITECH PROJECT, 2023
** B-CPE-101-STG-1-1-myprintf-alexandre.coelho
** File description:
** hexa.c
*/

#include "../../../include/my.h"
#include "../../../include/my_printf.h"

int my_put_nbr_hexa_lower(unsigned long n)
{
    int remainder = n % 16;

    if (n < 16) {
        if (n < 10) {
            my_putchar('0' + n);
        } else {
            my_putchar('a' + (n - 10));
        }
    } else {
        my_put_nbr_hexa_lower(n / 16);
            if (remainder < 10) {
                my_putchar('0' + remainder);
            } else {
                my_putchar('a' + (remainder - 10));
        }
    }
}

int my_put_nbr_hexa(unsigned int n)
{
    int remainder = n % 16;

    if (n < 16) {
        if (n < 10) {
            my_putchar('0' + n);
        } else {
            my_putchar('A' + (n - 10));
        }
    } else {
        my_put_nbr_hexa(n / 16);
        if (remainder < 10) {
            my_putchar('0' + remainder);
        } else {
            my_putchar('A' + (remainder - 10));
        }
    }
}

void printfxl(va_list args)
{
    int x = va_arg(args, unsigned int);

    my_put_nbr_hexa_lower(x);
}

void printfx(va_list args)
{
    int X = va_arg(args, unsigned int);

    my_put_nbr_hexa(X);
}
