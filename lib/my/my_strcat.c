/*
** EPITECH PROJECT, 2023
** my_strcat
** File description:
** lib
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = my_strlen(dest);
    int y = 0;

    for (; src[y] != '\0'; y++)
        dest[i + y] = src[y];
    dest[y + i] = '\0';
    return dest;
}
