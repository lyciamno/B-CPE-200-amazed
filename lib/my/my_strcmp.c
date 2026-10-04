/*
** EPITECH PROJECT, 2023
** my_strcmp
** File description:
** lib
*/

int my_strcmp(char const *s1, char const *s2)
{
    int y;
    int resultat;

    for (y = 0; s1[y] == s2[y] && s1[y] != '\0' && s2[y] != '\0'; y++);
    resultat = s1[y] - s2[y];
    return resultat;
}
