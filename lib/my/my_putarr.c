/*
** EPITECH PROJECT, 2021
** my_putarr.c
** File description:
** my_putarr
*/

#include "my.h"

void my_putarr(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        my_putstr(array[i]);
        my_putchar('\n');
    }
}