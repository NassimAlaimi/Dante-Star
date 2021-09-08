/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-dante-baptiste.friboulet
** File description:
** make_map
*/

#include "my.h"

int **make_wall(int **map, int xmax, int ymax, generator_s *g)
{
    int x = 0;
    int y = 0;
    int nb = 1;

    for (y = 0; y <= ymax; y++) {
        for (x = 0; x <= xmax; x++) {
            if (x == 0 && y == 0) {
                map[y][x] = nb;
                nb++;
            } else if (x % 2 == 0 || y % 2 == 0) {
                map[y][x] = -1;
                g->nb_wall++;
            } else {
                map[y][x] = nb;
                nb++;
            }
        }
    }
    return (map);
}

int **map_gen(int **map, int xmax, int ymax, generator_s *generator)
{
    generator->nb_wall = 0;
    map = make_wall(map, xmax, ymax, generator);
}