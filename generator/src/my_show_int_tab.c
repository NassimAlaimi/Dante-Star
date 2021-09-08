/*
** EPITECH PROJECT, 2021
** B-CPE-200-NAN-2-1-dante-baptiste.friboulet
** File description:
** my_show_int_tab
*/

#include "my.h"

int my_show_int_array(int *tab, int ac)
{
    if (ac < 0) {
        my_putchar('\n');
        return 0;
    }
    ac++;
    for (int i = 0; tab[i] != 0;i++) {
        my_put_nbr(tab[i]);
        if (tab[i] != 0)
            my_putchar(' ');
    }
    my_putchar('\n');
    return (0);
}