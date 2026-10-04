/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-amazed-kelyan.l-inconnu
** File description:
** amazed.c
*/

#include "../include/my.h"

int find_romm_nbr(char *room_name, char **rooms)
{
    int i = 0;

    while (rooms[i] != NULL) {
        if (!my_strcmp(room_name, rooms[i]))
            return i;
        i++;
    }
    return -1;
}

void set_links(amazed_t *amz, int **links, int i)
{
    int idx = 0;

    while (amz->rooms[idx + i] != NULL) {
        links[idx] = malloc(sizeof(int) * 2);
        links[idx][0] = find_romm_nbr(amz->rooms[idx + i][0],
        amz->rooms_names);
        links[idx][1] = find_romm_nbr(amz->rooms[idx + i][1],
        amz->rooms_names);
        idx++;
    }
    links[idx] = NULL;
}

void set_rooms(int *i, amazed_t *amz)
{
    while (*i < amz->room_nbr + 1) {
        amz->rooms_names[*i - 1] = malloc(sizeof(char) *
        (my_strlen(amz->rooms[*i][0]) + 1));
        my_strcpy(amz->rooms_names[*i - 1], amz->rooms[*i][0]);
        (*i)++;
    }
    amz->rooms_names[amz->room_nbr] = NULL;
}

int run_amazed(amazed_t *amz)
{
    int room_alone = direct_way(amz);

    if (room_alone != 0) {
        create_array(amz, room_alone);
        move_robots(amz->array_way, amz);
        return 0;
    } else {
        if (find_way(amz) == 84)
            return 84;
        move_robots(amz->array_way, amz);
    }
    return 0;
}

int a_mazed(amazed_t *amz)
{
    int i = 0;
    int idx = 0;
    int **links = NULL;

    if (get_file(amz) != 0)
        return 84;
    if (validate_start_and_end(amz) != 0)
        return 84;
    return 0;
    init_model(amz);
    for (; amz->rooms[idx][2][0] != '\0'; idx++);
    amz->rooms_names = malloc(sizeof(char *) * (amz->room_nbr + 1));
    set_rooms(&i, amz);
    idx = 0;
    for (; amz->rooms[i + idx] != NULL; idx++);
    links = malloc(sizeof(int *) * (idx + 1));
    set_links(amz, links, i);
    fill_model(amz, links);
    find_path(amz);
    return (run_amazed(amz));
}
