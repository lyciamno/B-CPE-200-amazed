/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-amazed-kelyan.l-inconnu
** File description:
** supp.c
*/

#include "../../include/my.h"

int is_alpha(amazed_t *s, int i, int mod)
{
    if (mod == 0) {
        if (s->inp[i] < '0' || s->inp[i] > '9')
            return 84;
    }
    if (mod == 1) {
        if ((s->inp[i] < '0' || s->inp[i] > '9') &&
            (s->inp[i] < 'a' || s->inp[i] > 'z') &&
            (s->inp[i] < 'A' || s->inp[i] > 'Z'))
            return 84;
    }
    return 0;
}

int cmt_start(amazed_t *s, int *i)
{
    if (s->inp[*i + 1] == 's' && s->inp[*i + 2] == 't' &&
        s->inp[*i + 3] == 'a' && s->inp[*i + 4] == 'r' &&
        s->inp[*i + 5] == 't' && (s->inp[*i + 6] == '\n' ||
        s->inp[*i + 6] == ' ')) {
        *i = skip_space_et_cmt(s, *i + 6);
        if (*i == -1) {
            *i = -700;
            return 0;
        }
        s->start_room = s->nb;
        *(i) = get_room_nbr(s, *(i));
        s->nb_of_start++;
        s->room_nbr++;
        return 0;
    }
    return 1;
}

int second_part(amazed_t *s)
{
    int m;

    for (int i = s->room_nbr + 2; i < s->room_nbr + s->link_nbr + 1; i++) {
        m = 0;
        for (int j = 1; j < s->room_nbr + 1; j++)
            m = my_strcmp(s->rooms[i][0], s->rooms[j][0]) == 1 ? 1 : m;
        if (m == 0) {
            s->nb = i;
            return 84;
        }
        m = 0;
        for (int j = 1; j < s->room_nbr + 1; j++)
            m = my_strcmp(s->rooms[i][1], s->rooms[j][0]) == 1 ? 1 : m;
        if (m == 0) {
            s->nb = i;
            return 84;
        }
    }
    return 0;
}

int malloc_array(amazed_t *s, int lines)
{
    int tmp_line = lines;

    s->room_nbr = 0;
    s->link_nbr = 0;
    s->nb = 0;
    s->nb_of_start = 0;
    s->nb_of_end = 0;
    s->rbt_nbr = 0;
    if (lines == -700)
        return 84;
    if (lines == 1)
        tmp_line++;
    s->rooms = malloc(sizeof(char **) * tmp_line);
    for (int i = 0; i < tmp_line - 1; i++) {
        s->rooms[i] = malloc(sizeof(char *) * 4);
        for (int j = 0; j < 4; j++)
            s->rooms[i][j] = malloc(sizeof(char) * 10);
    }
    return 0;
}

static int get_line_suit(amazed_t *amz, char *tmp, int total_bytes, int line)
{
    amz->inp = malloc(sizeof(char) * total_bytes);
    if ((line < 5 || hashtag(tmp) == 1) && line != 1) {
        free(tmp);
        amz->inp = NULL;
        return -700;
    }
    my_strcpy(amz->inp, tmp);
    clean_input(amz);
    free(tmp);
    return line;
}

int get_file(amazed_t *amz)
{
    char *buf = NULL;
    int total_bytes = 0;
    int line = 0;
    char *tmp = malloc(sizeof(char) * 1000000);
    size_t n = 0;

    tmp[0] = '\0';
    for (; n != -1; total_bytes++) {
        line++;
        n = getline(&buf, &n, stdin);
        if (n == -1)
            break;
        my_strcat(tmp, buf);
        for (int i = 0; buf[i] != '\n' && buf[i] != '\0'; i++)
            total_bytes++;
    }
    tmp = nbr_end(tmp);
    total_bytes--;
    line = get_line_suit(amz, tmp, total_bytes, line);
    return line;
}
