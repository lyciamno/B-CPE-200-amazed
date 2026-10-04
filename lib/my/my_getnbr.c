/*
** EPITECH PROJECT, 2023
** my_getnbr
** File description:
** lib
*/

int my_getnbr(char const *str)
{
    int nb = 0;
    int sign = 1;
    int i = 0;
    int digit;

    while (str[i] != '\0' && (str[i] < '0' || str[i] > '9')) {
        if (str[i] == '-')
            sign = -sign;
        i++;
    }
    while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9')) {
        digit = str[i] - '0';
        if (nb > (2147483647 - digit) / 10)
            return 0;
        nb = nb * 10 + digit;
        i++;
    }
    while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
        i++;
    return nb * sign;
}
