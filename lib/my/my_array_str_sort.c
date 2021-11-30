/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** No file there , just an epitech header example
*/

#include "my.h"

int my_array_str_sort(char **array, int nb)
{
    char *tmp;

    for (int i = 0; i < nb; i++) {
        if (i + 1 <= nb && my_strcmp(array[i], array[i + 1]) > 0) {
            tmp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = tmp;
        }
    }
    return 0;
}