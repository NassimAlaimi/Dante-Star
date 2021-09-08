/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-dante-baptiste.friboulet
** File description:
** main
*/

#include "my.h"

int main(int ac, char **av)
{
    solve_t *solve = malloc(sizeof(*solve));
    if (solve == NULL)
        return 84;
    if (check_error(ac, av, solve) == -1) {
        free(solve);
        return 84;
    }
    if (solve->c_maze[0][0] == 'X' || \
    solve->c_maze[solve->maze_wid - 1][solve->maze_len - 1] == 'X') {
        printf("no solutions found");
        return 0;
    }
    solve->i_maze = malloc_map(solve->i_maze, solve->maze_len, solve->maze_wid);
    fill_map(solve->i_maze, solve->maze_len, solve->maze_wid, solve->c_maze);
    solver(solve);
    my_putarr(solve->c_maze);
    free(solve);
    return 0;
}