/*
** EPITECH PROJECT, 2023
** B-CPE-100-STG-1-1-cpoolday06-yousra.el-halimi
** File description:
** lib
*/

char *my_strcpy(char *dest, char const *src)
{
    int j = 0;

    for (; src[j] != '\0'; j++)
        dest[j] = src[j];
    dest[j] = '\0';
    return dest;
}
