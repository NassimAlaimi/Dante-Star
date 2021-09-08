/*
** EPITECH PROJECT, 2021
** B-CPE-110-NAN-1-1-antman-baptiste.friboulet
** File description:
** my_perror
*/

#include "my.h"

int my_perror(char *str)
{
    write(2, str, my_strlen(str));
    return -1;
}