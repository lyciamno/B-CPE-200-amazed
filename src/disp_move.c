/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-amazed-kelyan.l-inconnu
** File description:
** disp_move.c
*/

#include "../include/my.h"

int get_array_size(int **array_way)
{
    int nbr_way = 0;

    while (array_way[nbr_way] != NULL)
        nbr_way++;
    return nbr_way;
}

int *set_robot_pos(int **array_way, amazed_t *amz)
{
    int *rbt_pos = malloc(sizeof(int) * (amz->rbt_nbr));

    if (rbt_pos == NULL)
        return NULL;
    for (int i = 0; i < amz->rbt_nbr; i++)
        rbt_pos[i] = array_way[0][0];
    return rbt_pos;
}

int same_room(int actual_rbt, int way, int **array_way, amazed_t *amz)
{
    for (int i = 0; i < amz->distance - 1; i++) {
        if (actual_rbt == array_way[way][i])
            return array_way[way][i + 1];
    }
    return 84;
}

void move_robots(int **array_way, amazed_t *amz)
{
    int nbr_way = get_array_size(array_way);
    int *rbt_pos = set_robot_pos(array_way, amz);

    my_printf("#moves\n");
    while (rbt_pos[amz->rbt_nbr - 1] !=
        array_way[nbr_way - 1][amz->distance - 1]) {
        for (int i = 0; i < nbr_way; i++) {
            move_rbt(amz, rbt_pos, array_way, i);
        }
        my_printf("\n");
    }
}
