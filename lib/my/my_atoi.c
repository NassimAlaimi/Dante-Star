/*
** EPITECH PROJECT, 2020
** B-CPE-110-NAN-1-1-pushswap-baptiste.friboulet
** File description:
** my_atoi
*/

#include "my.h"

int my_atoi(char *str)
{
    int n = 0;
    int i = 0;
    int sign = 1;

    if (str[0] == '-') {
        sign *= -1;
        i = 1;
    }
    while (str[i] != '\0') {
        if (str[i] >= '0' || str[i] <= '9') {
            n *= 10;
            n = n + str[i] - '0';
        }
        i++;
    }
    if (sign == -1)
        n *= sign;
    return (n);
}