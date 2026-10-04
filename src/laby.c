/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-amazed-kelyan.l-inconnu
** File description:
** laby.c
*/

#include "../include/my.h"

static void update_weight(int weight, int *y, amazed_t *amz)
{
    int k = 0;

    while (k < amz->room_nbr) {
        if (amz->mtr[amz->i][amz->j] == weight) {
            amz->mtr[amz->j][k] =
            (amz->mtr[amz->j][k] == 0) ?
            weight + 1 : amz->mtr[amz->j][k];
            (*y)++;
        }
        k++;
    }
}

static void algo(amazed_t *amz, int weight)
{
    int y = 0;

    for (amz->i = 0; amz->i < amz->room_nbr; amz->i++)
        for (amz->j = 0; amz->j < amz->room_nbr; amz->j++)
            update_weight(weight, &y, amz);
    if (y != 0)
        algo(amz, weight + 1);
}

void find_path(amazed_t *amz)
{
    int current = amz->end_room - 1;
    int weight = 1;

    for (int i = 0; i < amz->room_nbr; i++)
        if (amz->mtr[current][i] == 0)
            amz->mtr[current][i] = weight;
    algo(amz, weight);
}
