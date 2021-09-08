/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


//   solver   //

typedef struct solve_s {
    int maze_len;
    int maze_wid;
    char **c_maze;
    char **og_maze;
    int **i_maze;
    int **temp;

    int distance;

    int up;
    int down;
    int left;
    int right;
} solve_t;

int check_error(int ac, char **av, solve_t *solve);
int **malloc_map(int **map, int xmax, int ymax);
void print_map(int **map, int xmax, int ymax);
int **fill_map(int **map, int xmax, int ymax, char **c_map);
int solver(solve_t *solve);
int solved_way(solve_t *solve);
//   solver   //


//my.c
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);
int my_strlen(char const *str);
int my_perror(char *str);
int my_atoi(char *str);
char **my_str_to_word_array(char const *str);
void my_putarr(char **array);
void my_put_2d_int_array(solve_t *solve);

#endif /* !MY_H_ */
