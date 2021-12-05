/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** No file there , just an epitech header example
*/

#include "include/sort.h"

int rev_files_in_data(data_t *d)
{
    file *tmp;
    int index = 0;
    int index_2 = d->nb_files - 1;

    while (index < d->nb_files / 2) {
        tmp = d->files[index];
        d->files[index] = d->files[index_2];
        d->files[index_2] = tmp;
        index++;
        index_2--;
    }
    return 0;
}

int format_sort(data_t *data)
{
    if (data->r == 1) {
        rev_files_in_data(data);
        for (int i = 0; i < data->nb_dir; i++)
            rev_files_in_directory(data->directory[i]);
    }
    if (data->t == 1) {
        for (int i = 0; i < data->nb_dir; i++)
            sort_files_in_directory_by_date(data->directory[i]);
        sort_files_in_data_by_date(data);
    }
    return 0;
}
