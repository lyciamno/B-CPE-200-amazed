/*
** EPITECH PROJECT, 2023
** my_strcmp
** File description:
** day06 - task 06
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    for (; i < n - 1 && s1[i] == s2[i]; i++);
    if (s1[i] - s2[i] < 0)
        return (-1);
    else if (s1[i] - s2[i] > 0)
        return (1);
    else
        return (0);
}
