/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** printf
*/

#include "../../../include/my.h"
#include "../../../include/my_printf.h"

int flags(int i, const char *format, va_list args)
{
    for (int j = 0; j < 15; j++) {
        if (format[i + 1] == format_handlers[j].format) {
            format_handlers[j].f(args);
        }
    }
}

int my_printf(char *format, ...)
{
    va_list args;

    va_start(args, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%' && format[i + 1] != '\0') {
            flags(i, format, args);
        i++;
        } else {
            write(1, &format[i], 1);
        }
        va_end(args);
    }
}
