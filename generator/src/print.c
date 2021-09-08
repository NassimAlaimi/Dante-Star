/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-dante-baptiste.friboulet
** File description:
** print
*/

#include "my.h"

void print_end_map(int **map, int xmax, int ymax)
{
    int x = 0;
    int y = 0;

    for (y = 0; y <= ymax; y++) {
        for (x = 0; x <= xmax; x++) {
            x != xmax ? printf("%c", map[y][x]) : y != ymax ? printf("%c\n", map[y][x]) : printf("*");
        }
    }
}

void print_map(int **map, int xmax, int ymax)
{
    int x = 0;
    int y = 0;

    for (y = 0; y <= ymax; y++) {
        for (x = 0; x <= xmax; x++) {
            x != xmax ? printf("%i ", map[y][x]) : printf("%i\n", map[y][x]);
        }
    }
}

int **replace_map(int **map, int xmax, int ymax)
{
    int x = 0;
    int y = 0;

    for (y = 0; y <= ymax; y++) {
        for (x = 0; x <= xmax; x++)
            if (map[y][x] == -1)
                map[y][x] = 88;
            else
                map[y][x] = 42;
    }
    return (map);
}