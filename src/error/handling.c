/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-amazed-kelyan.l-inconnu
** File description:
** error_handling.c
*/

#include "../../include/my.h"

static int parse_link(amazed_t *s, int i, int k)
{
    while (s->inp[i] != '-') {
        if (is_alpha(s, i, 1) == 84)
            return -700;
        s->rooms[s->nb][0][k] = s->inp[i];
        k++;
        i++;
    }
    s->rooms[s->nb][0][k] = '\0';
    return parse_link_suit(s, i + 1, 0);
}

int parse_link_suit(amazed_t *s, int i, int k)
{
    k = 0;
    while (s->inp[i] != ' ' && s->inp[i] != '\n' && s->inp[i] != '\0') {
        if (is_alpha(s, i, 1) == 84 && s->inp[i] != '\n' && s->inp[i] != '\0')
            return -700;
        s->rooms[s->nb][1][k] = s->inp[i];
        k++;
        i++;
    }
    s->rooms[s->nb][1][k] = '\0';
    if (s->inp[i] == ' ') {
        if (skip_space_et_cmt(s, i) == -1)
            return -700;
        s->nb++;
        return i;
    }
    s->nb++;
    return i + 1;
}

static int check_cmt(amazed_t *s, int j)
{
    int n_s = 0;
    int i = j;

    for (; s->inp[i] != '\n' && n_s < 3 && s->inp[i] != '\0'; i++) {
        if (n_s == 0 && is_alpha(s, i, 1) == 84 && s->inp[i] != ' ')
            return 1;
        if (n_s > 0 && is_alpha(s, i, 0) == 84 && s->inp[i] != ' ')
            return 1;
        n_s = s->inp[i] == ' ' ? n_s + 1 : n_s;
        if (n_s > 2)
            i = skip_space_et_cmt(s, i);
        if (i == -1)
            return 1;
    }
    return 0;
}

static int check_nbr(amazed_t *s, int i)
{
    int save = i;
    int error;

    while (is_alpha(s, i, 1) != 84)
        i++;
    if (s->inp[i] == '-') {
        i = parse_link(s, save, 0);
        s->link_nbr++;
        return i;
    }
    if (s->inp[i] == ' ') {
        error = check_cmt(s, save);
        if (error == 1)
            return -700;
        i = get_room_nbr(s, save);
        s->room_nbr++;
        return i;
    }
    return -700;
}

static int check_cmd(amazed_t *s, int i)
{
    int result;

    if (s->inp[i] != '#') {
        while (s->inp[i] != '\n')
            i++;
        return i + 1;
    } else {
        if (cmt_start(s, &i) == 0)
            return i;
        result = check_cmd_sec(s, i);
        if (result != -700)
            return result;
        return -700;
    }
}

int error_handle(amazed_t *s, int i, int line)
{
    if (find_rbt_n(s, &i, line) == 84 || s->rbt_nbr < 1)
        return 84;
    return error_handle_suit(s, i, line);
}

int error_handle_suit(amazed_t *s, int i, int line)
{
    while (s->inp[i] != '\0' && i != -700) {
        if (s->inp[i] == ' ')
            i = skip(s, i);
        if (is_alpha(s, i, 1) == 84 && s->inp[i] != '#')
            return 84;
        if (is_alpha(s, i, 1) == 0)
            i = check_nbr(s, i);
        if (i == -700)
            return 84;
        if (s->inp[i] == '#')
            i = check_cmd(s, (i + 1));
        if (is_alpha(s, i, 1) == 84 && s->inp[i] != '#' && s->inp[i] != ' ')
            s->rooms[s->nb] = NULL;
    }
    if (i == -700 || s->nb_of_start != 1 || s->nb_of_end != 1 ||
        s->link_nbr > (s->room_nbr * s->room_nbr)) {
            no_cmd(s);
            return 84;
    }
    return 0;
}
