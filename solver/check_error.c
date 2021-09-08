/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-dante-baptiste.friboulet
** File description:
** check_error
*/

#include "my.h"

int get_map_len(char *fp)
{
    char *c = malloc(sizeof(char) * 1);
    int count = 0;
    int fd = open(fp, O_RDONLY);

    while (read(fd, c, 1) == 1)
        count++;
    close(fd);
    return (count);
}

int get_tab_len(char **maze)
{
    int count = 0;

    for (int i = 0; maze[i] != NULL; i++)
        count++;

    return (count);
}

int check_maze(char *maze, solve_t *solve)
{
    solve->c_maze = my_str_to_word_array(maze);
    solve->og_maze = my_str_to_word_array(maze);

    solve->maze_wid = get_tab_len(solve->c_maze);
    solve->maze_len = strlen(solve->c_maze[0]);

    for (int i = 1; i <= solve->maze_wid - 1; i++) {
        if (strlen(solve->c_maze[i]) != strlen(solve->c_maze[i - 1]))
            return (my_perror("Maze should be rectangular\n"));
    }

    return 0;
}

int check_error(int ac, char **av, solve_t *solve)
{
    solve->maze_len = get_map_len(av[1]);
    char *maze = malloc(sizeof(char) * (solve->maze_len + 1));

    if (ac != 2)
        return (my_perror("Incorrect args\n"));

    int fd = open(av[1], O_RDONLY);

    if (fd == -1)
        return (my_perror("Incorrect filepath\n"));

    read(fd, maze, solve->maze_len + 1);
    maze[solve->maze_len] = '\0';
    close(fd);

    for (int i = 0; maze[i] != '\0'; i++)
        if (maze[i] != '*' && maze[i] != 'X' && maze[i] != '\n')
            return (my_perror("Incorrect maze\n"));

    if (check_maze(maze, solve) == -1)
        return -1;

    return 0;
}