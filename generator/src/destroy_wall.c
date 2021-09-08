/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-dante-baptiste.friboulet
** File description:
** destroy_wall
*/

#include "my.h"

void d_rand(generator_s *g, int *arr, int tmp)
{
    if (tmp == 2) {
        g->d1 = arr[0];
        g->d2 = arr[1];
    } else {
        g->d1 = arr[rand()%tmp];
        g->d2 = arr[rand()%tmp];
        while (g->d1 == g->d2) {
            g->d1 = arr[rand()%tmp];
            g->d2 = arr[rand()%tmp];
        }
    }
}

int set_d(generator_s *g, int **map, int d)
{
    if (d == 1) {
        return (map[g->y][g->x+1]);
    }
    if (d == 2){
        return (map[g->y][g->x-1]);
    }
    if (d == 3) {
        return (map[g->y-1][g->x]);
    }
    if (d == 4) {
        return (map[g->y+1][g->x]);
    }
}

int **do_map(int d1, int d2, generator_s *g, int **map)
{
    int x = 0;
    int y = 0;

    for (y = 0; y <= g->ymax; y++) {
        for (x = 0; x <= g->xmax; x++) {
            if (map[y][x] == d2)
                map[y][x] = d1;
        }
    }
    return (map);
}

int **destroy_wall(int **map, generator_s *g)
{
    int d1 = set_d(g, map, g->d1);
    int d2 = set_d(g, map, g->d2);
    int tmp;

    if (d1 > d2) {
        tmp = d2;
        d2 = d1;
        d1 = tmp;
    }
    if (d1 != d2 && d1 != -1 && d2 != -1 && d1 != 0 && d2 != 0) {
        map[g->y][g->x] = d1;
        map = do_map(d1, d2, g, map);
    }
    return (map);
}

int **destroy_loop(int **map, generator_s *g)
{
    srand(time(NULL));
    int tmp = 0;
    int *direction_array;

    while (check_wall(g, map) != 1) {
        random_nbr(g, map);
        tmp = count_destroy(g->x, g->y, g, map);
        if (tmp >= 2) {
            direction_array = store_wall(g->x, g->y, g, map);
            d_rand(g, direction_array, tmp);
            map = destroy_wall(map, g);
        }
    }
    return (map);
}