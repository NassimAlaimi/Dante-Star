/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-dante-baptiste.friboulet
** File description:
** utils
*/

#include "my.h"

int **fill_map(int **map, int xmax, int ymax, char **c_map)
{
    for (int i = 0; i < ymax; i++) {
        for (int j = 0; j < xmax; j++) {
            if (c_map[i][j] == 'X') {
                map[i][j] = -1;
            }
        }
    }
    return (map);
}

void print_map(int **map, int xmax, int ymax)
{
    int x = 0;
    int y = 0;

    for (y = 0; y < ymax; y++) {
        for (x = 0; x < xmax; x++) {
            x != xmax-1 ? printf("%i ", map[y][x]) : printf("%i\n", map[y][x]);
        }
    }
}

int **malloc_map(int **map, int xmax, int ymax)
{
    map = malloc(sizeof(int*) * ymax);
    for (int i = 0; i <= ymax; i++)
        map[i] = malloc(sizeof(int) * xmax - 1);
    return (map);
}