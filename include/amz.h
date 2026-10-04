/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-amazed-kelyan.l-inconnu
** File description:
** amz.h
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "struct.h"

#ifndef AMZ_H_
    #define AMZ_H_

void free_all(amazed_t amz);
int error_handle(amazed_t *s, int i, int line);
char *nbr_end(char *tmp);
int skip(amazed_t *amz, int i);
int check_cmd_sec(amazed_t *s, int i);
void no_cmd(amazed_t *s);
int hashtag(char *tmp);
int skip_space_et_cmt(amazed_t *s, int i);
int get_room_nbr(amazed_t *amz, int i);
int find_rbt_n(amazed_t *amz, int *i, int line);
int is_alpha(amazed_t *s, int i, int mod);
int cmt_start(amazed_t *s, int *i);
int second_part(amazed_t *amz);
int malloc_array(amazed_t *s, int lines);
int get_file(amazed_t *amz);
int a_mazed(amazed_t *amz);
int get_array_size(int **array_way);
int same_room(int actual_rbt, int way, int **array_way, amazed_t *amz);
void move_robots(int **array_way, amazed_t *amz);
void create_array(amazed_t *amz, int room_alone);
int array_size(char **array_way);
int direct_way(amazed_t *amz);
void cal_nbr_way(amazed_t *amz, int current_lign, int i);
void file_way(amazed_t *amz, int **array_way);
int finally_way(amazed_t *amz, int **array_way);
void find_path(amazed_t *amz);
void init_model(amazed_t *amz);
void fill_model(amazed_t *amz, int **links);
void move_rbt(amazed_t *amz, int *rbt_pos, int **array_way, int i);
void find_go_way(amazed_t *amz, int **array_way, int a);
int find_way(amazed_t *amz);
int find_distance(amazed_t *amz);
int parse_link_suit(amazed_t *s, int i, int k);
int error_handle_suit(amazed_t *s, int i, int line);
int get_room_nbr_suit(amazed_t *s, int i);
int find_rbt_n_suit(amazed_t *amz, int *i, int line);
static int get_line_suit(amazed_t *amz, char *tmp, int total_bytes, int line);
int validate_start_and_end(amazed_t *amz);

#endif
