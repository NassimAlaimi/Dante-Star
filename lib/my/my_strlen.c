/*
** EPITECH PROJECT, 2021
** B-CPE-110-NAN-1-1-antman-baptiste.friboulet
** File description:
** my_strlen
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
