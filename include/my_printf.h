/*
** EPITECH PROJECT, 2023
** my_printf.h
** File description:
** printf
*/

#ifndef MY_PRINTF_H
    #define MY_PRINTF_H

    #include <stdio.h>
    #include <stdarg.h>
    #include <unistd.h>
    #include <stdlib.h>

void printfs(va_list args);
void printfc(va_list args);
void printfd(va_list args);
void printfi(va_list args);
void printfx(va_list args);
void printfxl(va_list args);
void printfo(va_list args);
void printfpc(va_list args);
void printff(va_list args);
void printfe(va_list args);
void printfe_up(va_list args);
void printfu(va_list args);
void printfp(va_list args);
void printfg(va_list args);

int my_printf(char *format, ...);
int my_put_float(double nb);
int my_put_nbr_octal(unsigned int n);
int my_put_nbr_hexa_lower(unsigned long n);
int my_put_nbr_hexa(unsigned int n);
int my_put_science(double nb);
int my_put_majscience(double nb);
int my_put_nbr_u(unsigned int nb);
int my_put_g(double nb);

struct FormatSpecifier {
    char format;
    void (*f)(va_list);
};

static struct FormatSpecifier format_handlers[15] = {
    {'s', &printfs},
    {'c', &printfc},
    {'d', &printfd},
    {'i', &printfi},
    {'x', &printfxl},
    {'X', &printfx},
    {'%', &printfpc},
    {'o', &printfo},
    {'f', &printff},
    {'F', &printff},
    {'e', &printfe},
    {'E', &printfe_up},
    {'u', &printfu},
    {'p', &printfp},
    {'g', &printfg}
};

#endif
