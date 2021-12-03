/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** No file there , just an epitech header example
*/

#include "include/recursive.h"

int check_for_recursive(dir *d, data_t *data_back)
{
    data_t* data;
    char **str = malloc(sizeof(char *) * d->nb_files);
    str[0] = "./my_ls ";
    str[1] = get_flags_str(data_back);

    my_printf("\n");
    for (int i = 0; i < d->nb_files; i++)
        str[i + 2] = d->files[i]->path;
    if (S_ISDIR(d->stats->st_mode)) {
        data = malloc(sizeof(data_t));
        init_data(data, str);
        get_directory(data, str, 3);
        get_flags(data, str, 3);
        check_files(data);
        fill_files(data);
        for (int i = 0; i < data->nb_dir; i++)
            sort_files_in_directory(data->directory[i]);
        format_result(data);
        if (data->R == 1)
            flag_recursive(data);
        free(data);
    }
    return 0;
}

int flag_recursive(data_t *data)
{
    for (int i = 0; i < data->nb_dir; i++)
        for (int j = 0; j < data->directory[i]->nb_files; j++)
            check_for_recursive(data->directory[i], data);
    return 0;
}
