/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** No file there , just an epitech header example
*/

#include "include/formating.h"

int format_lines(data_t *data)
{
    the_printf_line_file(data);
    for (int i = 0; i < data->nb_dir; i++) {
        format_print_skip(data, i);
        my_printf("total %d\n", data->directory[i]->total);
        the_printf_line_dir(data, i);
        if (data->R == 1)
            flag_recursive(data->directory[i], data);
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
    format_sort(data);
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
