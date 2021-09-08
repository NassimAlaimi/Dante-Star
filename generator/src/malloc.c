/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-dante-baptiste.friboulet
** File description:
** malloc
*/

#include "my.h"

int **malloc_map(int **map, int xmax, int ymax)
{
    map = malloc(sizeof(int*)*(ymax+2));
    for (int i = 0; i <= ymax+2; i++)
        map[i] = malloc(sizeof(int)*(xmax+2));
    return (map);
}