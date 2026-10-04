/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-amazed-kelyan.l-inconnu
** File description:
** parsing.c
*/

#include "../../include/my.h"

char *nbr_end(char *tmp)
{
    int i;

    for (i = 0; tmp[i] != '\0'; i++) {
        if (tmp[i + 1] == '\0' && tmp[i] != '\n') {
            tmp[i + 1] = '\n';
            tmp[i + 2] = '\0';
            break;
        }
    }
    return tmp;
}

int skip(amazed_t *amz, int i)
{
    while (amz->inp[i] == ' ')
        i++;
    return i;
}

int check_cmd_sec(amazed_t *s, int i)
{
    if (s->inp[i + 1] == 'e' && s->inp[i + 2] == 'n' &&
        s->inp[i + 3] == 'd' && (s->inp[i + 4] == ' ' ||
        s->inp[i + 4] == '\n')) {
        i = skip_space_et_cmt(s, i + 4);
        if (i == -1)
            i = -700;
        s->end_room = s->nb;
        i = get_room_nbr(s, i);
        s->nb_of_end++;
        s->room_nbr++;
        return i;
    }
}

void no_cmd(amazed_t *s)
{
    int y = 0;

    if ((s->nb_of_start < 1 || s->nb_of_end < 1) && s->room_nbr > 0) {
        for (int i = 0; s->inp[i] != '-' && s->inp[i] != '\0'; i++)
            y += (s->inp[i] == '\n');
    }
    s->nb = y - 2;
}

int hashtag(char *tmp)
{
    int hashtag = 0;

    for (int i = 0; tmp[i] != '\0'; i++)
        hashtag = tmp[i] == '#' ? hashtag + 1 : hashtag;
    if (hashtag >= 4)
        return 0;
    else
        return 1;
}
