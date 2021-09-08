/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-dante-baptiste.friboulet
** File description:
** inperfect_maze
*/

#include "my.h"

int count_wall(int **map, int xmax, int ymax)
{
    int c = 0;
    int x = 0;
    int y = 0;

    for (y = 0; y <= ymax; y++) {
        for (x = 0; x <= xmax; x++) {
            if (map[y][x] == -1) {
                c++;
            }
        }
    }
    return (c);
}

int **do_imperfect_maze(int **map, generator_s *g, char **av)
{
    srand(time(NULL));
    int c = count_wall(map, g->xmax, g->ymax);
    int cmp = rand()%((7*c%100));

    if (cmp < c) {
        for (int i = 0; i != cmp; i++) {
            while (map[g->y][g->x] != -1) {
                g->x = rand()%(g->xmax+1);
                g->y = rand()%(g->ymax+1);
            }
            map[g->y][g->x] = 1;
        }
    }
    return (map);
}