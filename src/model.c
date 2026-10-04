/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-amazed-kelyan.l-inconnu
** File description:
** mtr.c
*/

#include "../include/my.h"

void init_model(amazed_t *amz)
{
    int i = 0;
    int a = 0;

    amz->mtr = malloc(sizeof(int *) * (amz->room_nbr + 1));
    while (i < amz->room_nbr) {
        amz->mtr[i] = malloc(sizeof(int) * (amz->room_nbr));
        a = 0;
        while (a < amz->room_nbr) {
            amz->mtr[i][a] = -1;
            a++;
        }
        i++;
    }
    amz->mtr[amz->room_nbr] = NULL;
}

void fill_model(amazed_t *amz, int **links)
{
    int i = 0;
    int x;
    int y;

    while (i < amz->link_nbr) {
        x = links[i][0];
        y = links[i][1];
        amz->mtr[y][x] = 0;
        amz->mtr[x][y] = 0;
        i++;
    }
}
