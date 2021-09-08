/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-dante-baptiste.friboulet
** File description:
** do_wall
*/

#include "my.h"

int **c_map(int **map, generator_s *g, char **av)
{
    srand(time(NULL));
    int tmp = rand()%2;

    if (my_atoi(av[1]) % 2 != 0 && my_atoi(av[2]) % 2 != 0) {
        if (tmp == 1)
            map[g->ymax][g->xmax-1] = 1;
        else
            map[g->ymax-1][g->xmax] = 1;
    }
    return (map);
}

int check_wall(generator_s *g, int **map)
{
    int x = 0;
    int y = 0;

    for (y = 0; y <= g->ymax; y++) {
        for (x = 0; x <= g->xmax; x++) {
            if (map[y][x] != -1 && map[y][x] != 1) {
                return (0);
            }
        }
    }
    return (1);
}

int count_destroy(int x, int y, generator_s *g, int **map)
{
    int counter = 0;
    int tmp = map[y][x];

    if (x != g->xmax && tmp != map[y][x+1] && map[y][x+1] != -1)
        counter++;
    if (x != 0 && tmp != map[y][x-1] && map[y][x-1] != -1)
        counter++;
    if (y != g->ymax && tmp != map[y+1][x] && map[y+1][x] != -1)
        counter++;
    if (y != 0 && tmp != map[y-1][x] && map[y-1][x] != -1)
        counter++;
    return (counter);
}

void random_nbr(generator_s *g, int **map)
{
  
    while (map[g->y][g->x] != -1) {
        g->x = rand()%(g->xmax+1);
        g->y = rand()%(g->ymax+1);
    }
}

int *store_wall(int x, int y, generator_s *g, int **map)
{
    int tmp = map[y][x];
    int *tab = malloc(sizeof(int)*count_destroy(x, y, g, map));
    int counter = 0;

    if (x != g->xmax && tmp != map[y][x+1] && map[y][x+1] != -1) {
        tab[counter] = 1;
        counter++;
    }
    if (x != 0 && tmp != map[y][x-1] && map[y][x-1] != -1) {
        tab[counter] = 2;
        counter++;
    }
    if (y != g->ymax && tmp != map[y+1][x] && map[y+1][x] != -1) {
        tab[counter] = 4;
        counter++;
    }
    if (y != 0 && tmp != map[y-1][x] && map[y-1][x] != -1)
        tab[counter] = 3;
    return (tab);
}