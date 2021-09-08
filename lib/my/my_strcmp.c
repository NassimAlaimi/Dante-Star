/*
** EPITECH PROJECT, 2020
** B-MUL-100-NAN-1-1-myhunter-baptiste.friboulet
** File description:
** my_strcmp
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++) {
        if (s1[i] < s2[i])
            return (-1);
        if (s1[i] > s2[i])
            return (1);
    }
    return (0);
}