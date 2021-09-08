/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-dante-baptiste.friboulet
** File description:
** check_erroe
*/

#include "my.h"

int check_error(int ac, char **av)
{
    if (ac < 3) {
        write(2, "Error : not enough arguments.\n", 30);
        return (-1);
    } else if (ac > 4) {
        write(2, "Error : too few arguments.\n", 27);
        return (-1);
    } else if (my_str_isnum(av[1]) == 0 || my_str_isnum(av[2]) == 0) {
        write(2, "Error : invalid number.\n", 25);
        return (-1);
    } else if (ac == 4) {
        if (strcmp(av[3], "perfect") != 0) {
            write(2, "Error : invalid argument.\n", 27);
            return (-1);
        }
    }
    return (0);
}