/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-amazed-kelyan.l-inconnu
** File description:
** struct.h
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

typedef struct amazed {
    int i;
    int j;
    int nb;
    int has_start;
    int has_end;
    int start_count;
    int end_count;
    int nb_of_start;
    int nb_of_end;
    int start_room;
    int end_room;
    int room_nbr;
    int rbt_nbr;
    int link_nbr;
    int nbr_way;
    int distance;
    int stop_rec;
    int **mtr;
    int **array_way;
    char *inp;
    char **rooms_names;
    char ***rooms;
} amazed_t;

#endif
