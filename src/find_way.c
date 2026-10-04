/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-amazed-kelyan.l-inconnu
** File description:
** find_way.c
*/

#include "../include/my.h"

void cal_nbr_way(amazed_t *amz, int current_lign, int i)
{
    for (int a = 0; a < amz->room_nbr; a++) {
        if (amz->mtr[current_lign][a] == 1) {
            amz->nbr_way++;
            return;
        }
        if (amz->mtr[current_lign][a] == i &&
        amz->mtr[a][current_lign] == i - 1) {
            cal_nbr_way(amz, a, i - 1);
        }
    }
}

int start_nbr_way(int start, amazed_t *amz)
{
    int result = 0;
    int i = 0;

    while (i < amz->room_nbr) {
        if (amz->mtr[start][i] >= 0)
            result++;
        i++;
    }
    return result;
}

void rec_way(amazed_t *amz, int **array_way, int current_lign)
{
    int i = 0;

    while (i < amz->room_nbr) {
        if (amz->mtr[current_lign][i] == 1)
            amz->stop_rec = 1;
        if (amz->stop_rec == 1)
            return;
        if (amz->mtr[current_lign][i] >= 2 &&
            amz->mtr[i][current_lign] ==
            amz->mtr[current_lign][i] - 1) {
            amz->mtr[current_lign][i] = -2;
            rec_way(amz, array_way, i);
        }
        i++;
    }
}

void file_way(amazed_t *amz, int **array_way)
{
    int start = amz->start_room;
    int *way;
    int a = 0;
    int value = start_nbr_way(start, amz);

    amz->stop_rec = 0;
    while (value > 0) {
        amz->stop_rec = 0;
        rec_way(amz, array_way, start);
        find_go_way(amz, array_way, a);
        a++;
        if (a == amz->nbr_way)
            break;
        value = start_nbr_way(start, amz);
    }
}

int finally_way(amazed_t *amz, int **array_way)
{
    int start_room = amz->start_room;
    int nbr_real_way = 0;
    int y = 0;

    for (int a = 0; a < amz->nbr_way; a++) {
        y = 0;
        for (int i = 0; i < amz->distance - 1; i++) {
            y += (array_way[a][i] == start_room);
        }
        if (y == 1)
            nbr_real_way++;
    }
    return (nbr_real_way);
}
