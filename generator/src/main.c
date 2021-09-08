/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-dante-baptiste.friboulet
** File description:
** main
*/

#include "my.h"

void print_one_map(int xmax, int ymax)
{
    int x = 0;
    int y = 0;

    for (y = 0; y <= ymax; y++) {
        for (x = 0; x <= xmax; x++) {
            printf("*");
        }
        if (y != ymax)
            printf("\n");
    }
}

int main(int ac, char **av)
{
    if (check_error(ac, av) == -1)
        return (84);
    generator_s *generator = malloc(sizeof(*generator));
    generator->ymax = atoi(av[1])-1;
    generator->xmax = atoi(av[2])-1;
    int **map = malloc_map(map, generator->xmax, generator->ymax);
    if (generator->xmax == 0 || generator->ymax == 0) {
        print_one_map(generator->xmax, generator->ymax);
        return (0);
    }
    map = map_gen(map, generator->xmax, generator->ymax, generator);
    map = destroy_loop(map, generator);
    map = c_map(map, generator, av);
    if (ac != 4)
        map = do_imperfect_maze(map, generator, av);
    print_end_map(replace_map(map, generator->xmax, generator->ymax), \
    generator->xmax, generator->ymax);
    return (0);
}