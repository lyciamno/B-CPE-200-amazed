/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-amazed-kelyan.l-inconnu
** File description:
** move.c
*/

#include "../include/my.h"

void run_two(int a, int *rbt_pos, int *y)
{
    if (rbt_pos[a] == 0)
        (*y)++;
}

void space(int a, int i, int j)
{
    if ((a != 0 && i != 0) || j != 0)
        my_printf(" ");
}

void move_rbt(amazed_t *amz, int *rbt_pos, int **array_way, int i)
{
    int a = 0;
    int y = 0;
    int tmp = 0;
    int j = 0;

    while (a < amz->rbt_nbr) {
        tmp = same_room(rbt_pos[a], i, array_way, amz);
        if (y == 0 && tmp != 84) {
            space(a, i, j);
            my_printf("P%d-%s", a + 1, amz->rooms_names[tmp]);
            run_two(a, rbt_pos, &y);
            rbt_pos[a] = tmp;
            j++;
        }
        a++;
    }
}
