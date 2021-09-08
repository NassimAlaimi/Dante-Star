/*
** EPITECH PROJECT, 2021
** B-PSU-200-NAN-2-1-mysokoban-baptiste.friboulet
** File description:
** my_str_to_word_array
*/

#include "my.h"

int is_alphanum(char const *str, int i)
{
    if (str[i] >= 32 && str[i] <= 126 && str[i])
        return 1;
    return 0;
}

int count_words(char const *str)
{
    int nb_strings = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if ((is_alphanum(str, i) == 1) && (is_alphanum(str, i + 1) == 0))
            nb_strings++;
    return (nb_strings);
}

char **alloc_array(char const *str, char **array, int nb_strings)
{
    int pos = 0;
    int word_length = 0;

    while (is_alphanum(str, pos) == 0)
        pos++;
    for (int i = 0; i < nb_strings; i++) {
        while (is_alphanum(str, pos) == 1) {
            word_length++;
            pos++;
        }
        pos++;
        array[i] = malloc(sizeof(char) * word_length + 1);
        word_length = 0;
        while (is_alphanum(str, pos) == 0) {
            pos++;
        }
    }
    return (array);
}

char **store_string(char const *str, char **array, int nb_strings)
{
    int x = 0;
    int pos = 0;

    while (is_alphanum(str, pos) == 0)
        pos++;
    for (int i = 0; i < nb_strings; i++) {
        while (is_alphanum(str, pos) == 1) {
            array[i][x] = str[pos];
            pos++;
            x++;
        }
        x = 0;
        pos++;
        while (is_alphanum(str, pos) == 0) {
            pos++;
        }
    }
    return (array);
}

char **my_str_to_word_array(char const *str)
{
    char **array = NULL;
    int nb_strings = 0;

    if (str == NULL)
        return (NULL);
    nb_strings = count_words(str);
    array = malloc(sizeof(char *) * nb_strings + 1);
    array = alloc_array(str, array, nb_strings);
    array = store_string(str, array, nb_strings);
    array[nb_strings] = NULL;
    return (array);
}