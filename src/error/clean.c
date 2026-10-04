/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-amazed-kelyan.l-inconnu
** File description:
** clean.c
*/

#include "../../include/my.h"

void copy(amazed_t *amz, char *cleaned, int *j, int *i)
{
    while (amz->inp[*i] != '\n' && amz->inp[*i] != '\0') {
        cleaned[*j] = amz->inp[*i];
        (*j)++;
        (*i)++;
    }
    if (amz->inp[*i] == '\n') {
        cleaned[*j] = amz->inp[*i];
        (*j)++;
        (*i)++;
    }
}

void handle_comment(amazed_t *amz, char *cleaned, int *j, int *i)
{
    if ((my_strncmp(&amz->inp[*i], "##start", 7) == 0)
        || (my_strncmp(&amz->inp[*i], "##end", 5) == 0)) {
        copy(amz, cleaned, j, i);
    } else {
        while (amz->inp[*i] != '\n' && amz->inp[*i] != '\0') {
            (*i)++;
        }
        if (amz->inp[*i] == '\n') {
            (*i)++;
        }
    }
}

void clean_input(amazed_t *amz)
{
    int i = 0;
    int j = 0;
    char *cleaned = (char *)malloc(sizeof(char) * (my_strlen(amz->inp) + 1));

    if (!cleaned) {
        my_printf("alloc failed.\n");
        return;
    }
    while (amz->inp[i] != '\0') {
        if (amz->inp[i] == '#') {
            handle_comment(amz, cleaned, &j, &i);
        } else {
            cleaned[j] = amz->inp[i];
            j++;
            i++;
        }
    }
    cleaned[j] = '\0';
    free(amz->inp);
    amz->inp = cleaned;
}
