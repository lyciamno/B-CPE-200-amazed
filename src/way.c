/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-amazed-kelyan.l-inconnu
** File description:
** way.c
*/

#include "../include/my.h"

int check_way(amazed_t *amz, int *crt_lign, int *j, int *array)
{
    int i = 0;

    while (i < amz->room_nbr) {
        if (amz->mtr[*crt_lign][i] == -2) {
            amz->mtr[*crt_lign][i] = -3;
            *array = *crt_lign;
            *crt_lign = i;
            (*j)++;
            return 1;
        }
        i++;
    }
    return 0;
}

void find_go_way(amazed_t *amz, int **array_way, int a)
{
    int current_lign = amz->start_room;
    int stop = 0;
    int j = 0;
    int y = 0;

    while (!stop) {
        if (current_lign == amz->end_room)
            stop = 1;
        for (int i = 0; i < amz->room_nbr; i++)
            y += (amz->mtr[current_lign][i] == -2);
        if (y == 0)
            break;
        check_way(amz, &current_lign, &j, &array_way[a][j]);
        if (stop)
            break;
    }
}

void file_real_way(amazed_t *amz, int **array_way, int i, int **real_way)
{
    int a = 0;

    while (a < amz->distance) {
        if (a == amz->distance - 1)
            real_way[i][a] = amz->end_room;
        else
            real_way[i][a] = array_way[i][a];
        a++;
    }
}

void create_clean_arr(amazed_t *amz, int **array_way)
{
    int nbr_real_way = finally_way(amz, array_way);
    int **real_way = malloc(sizeof(int *) * (nbr_real_way + 1));
    int i = 0;

    while (i < nbr_real_way) {
        real_way[i] = malloc(sizeof(int) * (amz->distance + 1));
        file_real_way(amz, array_way, i, real_way);
        i++;
    }
    real_way[nbr_real_way] = NULL;
    amz->array_way = real_way;
}

int find_way(amazed_t *amz)
{
    int current_lign = 0;
    int **array_way = NULL;
    int i = 0;

    amz->start_room = amz->start_room - 1;
    amz->end_room = amz->end_room - 1;
    amz->distance = find_distance(amz);
    amz->nbr_way = 0;
    current_lign = amz->start_room;
    i = amz->distance;
    cal_nbr_way(amz, current_lign, i);
    if (amz->nbr_way == 0)
        return 84;
    array_way = malloc(sizeof(int *) * (amz->nbr_way + 1));
    for (int a = 0; a < amz->nbr_way; a++)
        array_way[a] = malloc(sizeof(int) * (amz->distance - 1));
    file_way(amz, array_way);
    create_clean_arr(amz, array_way);
    return 0;
}
