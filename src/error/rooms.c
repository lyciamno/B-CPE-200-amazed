/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-amazed-kelyan.l-inconnu
** File description:
** rooms.c
*/

#include "../../include/my.h"

int skip_space_et_cmt(amazed_t *s, int i)
{
    int y = 0;

    while (s->inp[i] != '\n' && s->inp[i] != '\0') {
        if (s->inp[i] == '#' && s->inp[i + 1] != '#') {
            i += 2;
            y = 1;
        }
        if (s->inp[i] != ' ' && y == 0)
            return -1;
        i++;
    }
    return i + 1;
}

int get_room_nbr(amazed_t *s, int i)
{
    int k = 0;
    int j = 0;
    int n_s = 0;

    for (; s->inp[i] != '\n' && n_s < 3; i++) {
        for (j = 0; s->inp[i] != ' ' && s->inp[i] != '\n'; i++) {
            s->rooms[s->nb][k][j] = s->inp[i];
            j++;
        }
        s->rooms[s->nb][k][j] = '\0';
        k++;
        if (s->inp[i] == ' ')
            n_s++;
        if (s->inp[i] == '\n')
            break;
    }
    s->rooms[s->nb][k] = NULL;
    return get_room_nbr_suit(s, i);
}

int get_room_nbr_suit(amazed_t *s, int i)
{
    int k = 0;
    int j = 0;
    int n_s = 0;

    if (n_s > 2) {
        i = skip_space_et_cmt(s, i);
        if (i == -1)
            return -700;
        s->nb++;
        return i;
    }
    s->nb++;
    return i + 1;
}

static int robot_end(amazed_t *amz, int *i, int save)
{
    if (save != 0) {
        amz->rooms[amz->nb][0][save] = '\0';
        amz->rooms[amz->nb][1] = NULL;
        amz->nb++;
    } else {
        amz->rooms[amz->nb][0][*i] = '\0';
        amz->rooms[amz->nb][1] = NULL;
        amz->nb++;
        (*i)++;
    }
    amz->rbt_nbr = my_getnbr(amz->rooms[0][0]);
}

int find_rbt_n(amazed_t *amz, int *i, int line)
{
    int save = 0;

    amz->rbt_nbr = 0;
    for (; amz->inp[*i] != '\n' && amz->inp[*i] != '\0'; (*i)++) {
        if (amz->inp[*i] == ' ') {
            save = *i;
            *i = skip_space_et_cmt(amz, *i);
            break;
        }
        if (amz->inp[*i] < '0' || amz->inp[*i] > '9')
            return 84;
        amz->rooms[0][0][*i] = amz->inp[*i];
    }
    if (*i == -1)
        return 84;
    robot_end(amz, i, save);
    return find_rbt_n_suit(amz, i, line);
}

int find_rbt_n_suit(amazed_t *amz, int *i, int line)
{
    if (amz->rbt_nbr >= 1 && line == 1) {
        my_printf("robots:%d\n", amz->rbt_nbr);
        return 84;
    }
    return 0;
}
