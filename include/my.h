/*
** EPITECH PROJECT, 2023
** B-CPE-100-STG-1-1-cpoolday09-yousra.el-halimi
** File description:
** my.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <grp.h>
#include <pwd.h>
#include <time.h>
#include "my_printf.h"
#include "struct.h"
#include "amz.h"

#ifndef MY_H_
    #define MY_H_

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
int my_strcasecmp(const char *s1, const char *s2);
char *my_strcat(char *dest, char const *src);
int my_strncmp(char const *s1, char const *s2, int n);
void clean_input(amazed_t *amz);

#endif /*MY_H*/
