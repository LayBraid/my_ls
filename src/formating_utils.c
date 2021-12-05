/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** No file there , just an epitech header example
*/

#include "../include/formating_utils.h"

char *get_str_file(dir *d)
{
    char *str = "%s  % ";

    str = my_strcat(str, my_itoa(d->max_link));
    str = my_strcat(str, "d %s  %s  % ");
    str = my_strcat(str, my_itoa(d->max_size));
    str = my_strcat(str, "d %s % 2d %.2d:%.2d %s\n");
    return str;
}

char *get_str_file_file(file *f)
{
    (void) f;

    return "%s  %d %s  %s  %d %s % 2d %.2d:%.2d %s\n";
}

char *get_str_dir(data_t *data)
{
    char *str = "%s  % ";

    str = my_strcat(str, my_itoa(data->max_link));
    str = my_strcat(str, "d %s  %s  % ");
    str = my_strcat(str, my_itoa(data->max_size));
    str = my_strcat(str, "d %s % 2d %.2d:%.2d %s\n");
    return str;
}

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
