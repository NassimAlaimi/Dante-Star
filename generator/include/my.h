/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

/* Struct */

typedef struct generator_t {
    int perfect;
    int y;
    int x;
    int xmax;
    int ymax;
    int **map;
    int nb_wall;
    /* direction */
    int d1;
    int d2;
} generator_s;

/* LIB FUNCTIONS */

int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_is_prime(int nb);
int my_isneg(int n);
int my_put_nbr(int nb);
void my_putchar(char c);
void my_putstr(char const *str);
void my_swap(int a, int b);
char *my_strupcase(char *str);
int word_check(char *str, char const *to_find, int i, char **sub_ptr);
char *my_strncpy(char *dest, char const *src, int n);
int my_strncmp(char const *s1, char const *s2, size_t n);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strlowcase(char *str);
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strcat(char *dest, char const *src);
char *my_strcapitalize(char *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isalpha(char const *str);
void my_sort_int_array(int *array, int size);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_atoi(const char *nptr);
int my_show_word_array(char **tab);
int my_array_len(char **array);
char *my_int_to_str(int nb);
int my_is_number(char c);
char *my_strdup(char const *src);
int my_is_char_in_str(char c, char *str);

/* Generator fonction */

void print_map(int **map, int xmax, int ymax);
int **map_gen(int **map, int xmax, int ymax, generator_s *generator);
int **malloc_map(int **map, int xmax, int ymax);
int check_error(int ac, char **av);
int **replace_map(int **map, int xmax, int ymax);
int **destroy_loop(int **map, generator_s *g);
int my_show_int_array(int *tab, int ac);
void print_end_map(int **map, int xmax, int ymax);
int *store_wall(int x, int y, generator_s *g, int **map);
void random_nbr(generator_s *g, int **map);
int count_destroy(int x, int y, generator_s *g, int **map);
int check_wall(generator_s *g, int **map);
int **do_imperfect_maze(int **map, generator_s *g, char **av);
int **c_map(int **map, generator_s *g, char **av);
#endif /* !MY_H_ */
