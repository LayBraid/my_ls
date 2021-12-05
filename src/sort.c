/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** No file there , just an epitech header example
*/

#include "../include/sort.h"

int rev_files_in_directory(dir *d)
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

int sort_files_in_directory(dir *d)
{
    file *tmp;

    for (int i = 0; i < d->nb_files - 1; i++)
        if (my_strcmp(d->files[i]->path, d->files[i + 1]->path) > 0) {
            tmp = d->files[i];
            d->files[i] = d->files[i + 1];
            d->files[i + 1] = tmp;
            sort_files_in_directory(d);
        }
    return 0;
}

int sort_files_in_directory_by_date(dir *d)
{
    file *tmp;

    for (int i = 0; i < d->nb_files - 1; i++)
        if (d->files[i]->time < d->files[i + 1]->time) {
            tmp = d->files[i];
            d->files[i] = d->files[i + 1];
            d->files[i + 1] = tmp;
            sort_files_in_directory_by_date(d);
        }
    return 0;
}

int sort_files_in_data(data_t *d)
{
    file *tmp;

    for (int i = 0; i < d->nb_files - 1; i++)
        if (my_strcmp(d->files[i]->path, d->files[i + 1]->path) > 0) {
            tmp = d->files[i];
            d->files[i] = d->files[i + 1];
            d->files[i + 1] = tmp;
            sort_files_in_data(d);
        }
    return 0;
}

int sort_files_in_data_by_date(data_t *d)
{
    file *tmp;

    for (int i = 0; i < d->nb_files - 1; i++)
        if (d->files[i]->time < d->files[i + 1]->time) {
            tmp = d->files[i];
            d->files[i] = d->files[i + 1];
            d->files[i + 1] = tmp;
            sort_files_in_data_by_date(d);
        }
    return 0;
}
