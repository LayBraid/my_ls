/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** No file there , just an epitech header example
*/

#include "include/formating.h"

int format_print_skip(data_t *data, int i)
{
    if (data->nb_files > 0 && data->nb_dir > 0) {
        my_printf("\n%s:\n", data->directory[i]->name);
        return 0;
    }
    if (data->nb_files == 0 && data->nb_dir > 1) {
        my_printf("%s:\n", data->directory[i]->name);
        return 1;
    }
    if (data->nb_dir > 1) {
        my_printf("%s:\n", data->directory[i]->name);
        return 0;
    }
    if (data->R == 1) {
        my_printf("%s:\n", data->directory[i]->name);
        return 2;
    }
    return 3;
}

int format_lines(data_t *data)
{
    for (int i = 0; i < data->nb_files; i++)
        my_printf(get_str_file_file(data->files[i]),
                  data->files[i]->perm,
                  data->files[i]->nb,
                  data->files[i]->user,
                  data->files[i]->group,
                  data->files[i]->size,
                  data->files[i]->date->month_str,
                  data->files[i]->date->day,
                  data->files[i]->date->hour,
                  data->files[i]->date->min,
                  data->files[i]->name);
    for (int i = 0; i < data->nb_dir; i++) {
        format_print_skip(data, i);
        my_printf("total %d\n", data->directory[i]->total);
        for (int j = 0; j < data->directory[i]->nb_files; j++) {
            my_printf(get_str_file(data->directory[i]),
                      data->directory[i]->files[j]->perm,
                      data->directory[i]->files[j]->nb,
                      data->directory[i]->files[j]->user,
                      data->directory[i]->files[j]->group,
                      data->directory[i]->files[j]->size,
                      data->directory[i]->files[j]->date->month_str,
                      data->directory[i]->files[j]->date->day,
                      data->directory[i]->files[j]->date->hour,
                      data->directory[i]->files[j]->date->min,
                      data->directory[i]->files[j]->name);
        }
        if (data->R == 1) {
            flag_recursive(data->directory[i], data);//TODO REDUIRE FONCTION
        }

    }
    return 0;
}

int format_lines_directory(data_t *data)
{
    for (int i = 0; i < data->nb_dir; i++)
        my_printf(get_str_dir(data),
                  data->directory[i]->perm,
                  data->directory[i]->nb,
                  data->directory[i]->user,
                  data->directory[i]->group,
                  data->directory[i]->size,
                  data->directory[i]->date->month_str,
                  data->directory[i]->date->day,
                  data->directory[i]->date->hour,
                  data->directory[i]->date->min,
                  data->directory[i]->name);
    return 0;
}

int format_directory(data_t *data)
{
    for (int i = 0; i < data->nb_dir; i++)
        my_printf("%s\n", data->directory[i]->name);
    return 0;
}

int format_simple(data_t *data)
{
    for (int i = 0; i < data->nb_files; i++)
        my_printf("%s\n", data->files[i]->name);
    for (int i = 0; i < data->nb_dir; i++) {
        format_print_skip(data, i);
        for (int j = 0; j < data->directory[i]->nb_files; j++)
            my_printf("%s\n", data->directory[i]->files[j]->name);
        if (data->R == 1)
            flag_recursive(data->directory[i], data);
    }
    return 0;
}

int format_result(data_t *data)
{
    if (data->d == 1)
        data->R = 0;
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
