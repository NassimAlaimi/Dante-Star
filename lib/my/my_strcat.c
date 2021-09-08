/*
** EPITECH PROJECT, 2020
** my_strcat.c
** File description:
** my_strcat
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i;
    int j = 0;

    i = my_strlen(dest);
    while (src[j] != '\0') {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return (dest);
}
