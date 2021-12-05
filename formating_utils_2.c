/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** No file there , just an epitech header example
*/


#include "include/formating_utils.h"

int the_printf_line_file(data_t *data)
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
    return 0;
}


int the_printf_line_dir(data_t *data, int i)
{
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
    return 0;
}
