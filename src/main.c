/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-amazed-kelyan.l-inconnu
** File description:
** main.c
*/

#include "../include/my.h"

int validate_start_and_end(amazed_t *amz)
{
    if (amz->start_count > 1) {
        return 84;
    }
    if (amz->end_count > 1) {
        return 84;
    }
    if (!amz->has_start) {
        return 84;
    }
    if (!amz->has_end) {
        return 84;
    }
    return 0;
}

int find_distance(amazed_t *amz)
{
    int i = 0;

    while (i < amz->room_nbr) {
        if (amz->mtr[amz->start_room][i] != -1)
            return (amz->mtr[amz->start_room][i]);
        i++;
    }
    return 0;
}

void print_rooms_and_tunnels(amazed_t *amz, int plus)
{
    int o = 0;
    int ok = 0;
    int op = 0;
    int i = 0;

    while (amz->inp[i] != '\0') {
        if (o == 1 && ok == 0) {
            my_printf("#rooms\n");
            ok = 1;
        }
        if (o == amz->room_nbr + 3 && op == 0 && amz->nb_of_start == 1 &&
            amz->nb_of_end == 1) {
            my_printf("#tunnels\n");
            op = 1;
        }
        o = amz->inp[i] == '\n' ? o + 1 : o;
        my_printf("%c", amz->inp[i]);
        i++;
    }
}

int print(amazed_t *amz, int line)
{
    int plus = 0;

    if (amz->rbt_nbr < 1 || line == 1)
        return 84;
    my_printf("#number_of_robots\n");
    if (amz->nb > 1)
        plus = 2;
    print_rooms_and_tunnels(amz, plus);
}

int main(void)
{
    amazed_t amz = {0};
    int line = get_file(&amz);

    if (line == -700 || malloc_array(&amz, line) == 84 ||
        error_handle(&amz, 0, line) == 84 ||
        second_part(&amz) == 84) {
        print(&amz, line);
        free_all(amz);
        return 84;
    }
    print(&amz, line);
    if (a_mazed(&amz) == 84) {
        free_all(amz);
        return 84;
    }
    free_all(amz);
    return 0;
}
