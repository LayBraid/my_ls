/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** No file there , just an epitech header example
*/

#include "include/formating.h"

int format_lines(data_t *data)
{
    return 0;
}

int format_lines_directory(data_t *data)
{
    for (int i = 0; i < data->nb_dir; i++) {
        my_printf("%s", data->directory[i]->perm);
        /*my_printf("%s  %d %s  %s  %d  %s  %s\n",
                  data->directory[i]->perm,
                  data->directory[i]->nb,
                  data->directory[i]->user,
                  data->directory[i]->group,
                  data->directory[i]->size,
                  data->directory[i]->modification,
                  data->directory[i]->path);*/
    }
    return 0;
}

int format_directory(data_t *data)
{
    for (int i = 0; i < data->nb_dir; i++) {
        my_printf("%s\n", data->directory[i]->path);
    }
    return 0;
}

int format_simple(data_t *data)
{
    for (int i = 0; i < data->nb_dir; i++)
        for (int j = 0; j < data->directory[i]->nb_files; j++)
            my_printf("%s\n", data->directory[i]->files[j]->path);
    return 0;
}

int format_result(data_t *data)
{
    if (data->r == 1)
        for (int i = 0; i < data->nb_dir; i++)
            rev_files_in_directory(data->directory[i]);
    if (data->l == 1 && data->d == 0)
        format_lines(data);
    if (data->l == 1 && data->d == 1)
        format_lines_directory(data);
    if (data->l == 0 && data->d == 1)
        format_directory(data);
    if (data->l == 0 && data->d == 0)
        format_simple(data);
    return 0;
}
