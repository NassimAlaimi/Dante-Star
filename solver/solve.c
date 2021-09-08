/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-dante-baptiste.friboulet
** File description:
** solve
*/

#include "my.h"

void solving(solve_t *solve, int i, int j)
{
    if (solve->i_maze[i][j] == 0) {

        if (i == 0) {
            if (solve->i_maze[i + 1][j] > 0 || solve->i_maze[i][j - 1] > 0 \
            || solve->i_maze[i][j + 1] > 0) {
                solve->i_maze[i][j] = solve->distance;
                solve->distance ++;
            }
        } else if (solve->i_maze[i - 1][j] > 0 || solve->i_maze[i + 1][j] > 0 \
        || solve->i_maze[i][j - 1] > 0 || solve->i_maze[i][j + 1] > 0) {
            solve->i_maze[i][j] = solve->distance;
            solve->distance ++;
        }
    }
}

int solver(solve_t *solve)
{
    solve->distance = 2;

    solve->i_maze[solve->maze_wid - 1][solve->maze_len - 1] = 1;

    while (solve->i_maze[0][0] == 0) {
        for (int i = solve->maze_wid - 1; i >= 0; i--) {
            for (int j = solve->maze_len - 1; j >= 0; j--) {
                solving(solve, i, j);
            }
        }
    }
    solved_way(solve);
    return 0;
}