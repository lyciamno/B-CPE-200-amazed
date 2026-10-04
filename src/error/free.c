/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-amazed-kelyan.l-inconnu
** File description:
** free.c
*/

#include "../../include/my.h"

void free_all(amazed_t amz)
{
    int i;
    int j;

    free(amz.inp);
    i = 0;
    while (amz.rooms != NULL && amz.rooms[i] != NULL) {
        j = 0;
        while (amz.rooms[i][j] != NULL) {
            free(amz.rooms[i][j]);
            j++;
        }
        free(amz.rooms[i]);
        i++;
    }
    free(amz.rooms);
}
