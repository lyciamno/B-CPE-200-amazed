/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-amazed-kelyan.l-inconnu
** File description:
** disp_way.c
*/

#include "../include/my.h"

void create_array(amazed_t *amz, int room_alone)
{
    amz->array_way = malloc(sizeof(int *));
    amz->array_way[0] = malloc(sizeof(int) * 2);
    amz->array_way[0][0] = amz->start_room - 1;
    amz->array_way[0][1] = amz->end_room - 1;
    amz->distance = 2;
    return;
}

int array_size(char **array)
{
    int size = 0;

    for (; array[size] != NULL; size++)
    return size;
}

int simple_way(amazed_t *amz, char **array)
{
    int value1 = my_getnbr(array[0]);
    int value2 = my_getnbr(array[1]);

    if ((value1 == amz->start_room - 1 && value2 == amz->end_room - 1) ||
        (value2 == amz->start_room - 1 && value1 == amz->end_room - 1)) {
        return 0;
    }
    return 1;
}

int direct_way(amazed_t *amz)
{
    int y;

    for (int i = 0; amz->rooms[i]; i++) {
        y = 1;
        if (array_size(amz->rooms[i]) == 4)
            y = simple_way(amz, amz->rooms[i]);
        if (y == 0)
            return i;
    }
    return 0;
}
