/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-dante-baptiste.friboulet
** File description:
** my_str_is_num
*/

#include "my.h"

int my_str_isnum(char const *str)
{
    if (str[0] == '-')
        return (0);
    for (int i = 0; str[i] != '\0';) {
        if (str[i] >= '0' && str[i] <= '9')
            i++;
        else
            return (0);
    }
    return (1);
}