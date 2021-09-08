/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-dante-baptiste.friboulet
** File description:
** final_path
*/

#include "my.h"

void get_neighbour_cells(solve_t *solve, int x, int y)
{
    if (y != 0)
        solve->up = solve->i_maze[y - 1][x];
    else
        solve->up = 200000000;
    if (x != 0)
        solve->left = solve->i_maze[y][x - 1];
    else
        solve->left = 200000000;
    solve->down = solve->i_maze[y + 1][x];
    solve->right = solve->i_maze[y][x + 1];
}

int choose_lowest2(solve_t *solve)
{
    if (solve->up <= solve->down && solve->up <= solve->left && \
        solve->up <= solve->right)
        return 4;
    else if (solve->down <= solve->up && solve->down <= solve->left && \
        solve->down <= solve->right)
        return 3;
    else if (solve->left <= solve->up && solve->left <= solve->down && \
        solve->left <= solve->right)
        return 2;
    else if (solve->right <= solve->up && solve->right <= solve->down && \
        solve->right <= solve->left)
        return 1;
    return 0;
}

int choose_lowest(int x, int y, solve_t *solve)
{
    solve->up = 0;
    solve->down = 0;
    solve->right = 0;
    solve->left = 0;

    get_neighbour_cells(solve, x, y);

    if (solve->up <= 0)
        solve->up = 200000000;
    if (solve->down <= 0)
        solve->down = 200000000;
    if (solve->left <= 0)
        solve->left = 200000000;
    if (solve->right <= 0)
        solve->right = 200000000;
    return (choose_lowest2(solve));
}

int solved_way(solve_t *solve)
{
    int x = 0;
    int y = 0;
    int temp;
    solve->c_maze[0][0] = 'o';

    while (solve->c_maze[solve->maze_wid - 1][solve->maze_len - 1] != 'o') {
        temp = choose_lowest(x, y, solve);

        switch (temp) {
        case 1: x++; break;
        case 2: x--; break;
        case 3: y++; break;
        case 4: y--; break;
        default: printf("no solutions found"); return 0; break;
        }
        solve->c_maze[y][x] = 'o';
    }
    return 0;
}