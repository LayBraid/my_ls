/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** No file there , just an epitech header example
*/

#include "include/recursive.h"

char **get_str(dir *d)
{
    struct stat *stats;
    int skip = 0;
    int i;
    char **str = malloc(sizeof(char *) * d->nb_files + 1);
    str[0] = "./my_ls";

    my_printf("\n");
    for (i = 0; i < d->nb_files; i++) {
        stats = malloc(sizeof(struct stat));
        stat(d->files[i]->path, stats);
        if (S_ISDIR(stats->st_mode))
            str[i + 1 - skip] = d->files[i]->path;
        else
            skip++;
    }
    str[i + 1 - skip] = "\0";
    return str;
}

int check_for_recursive(dir *d, data_t *data_back)
{
    data_t* data;
    char **str = get_str(d);

    data = malloc(sizeof(data_t));
    init_data(data, str, data->nb_dir + 1);
    get_directory(data, str, data->nb_dir + 1);
    switch_flags(data, data_back);
    check_files(data);
    fill_files(data);
    for (int i = 0; i < data->nb_dir; i++)
        sort_files_in_directory(data->directory[i]);
    sort_files_in_data(data);
    format_result(data);
    my_printf("\n");
    free(data);
    return 0;
}

int flag_recursive(dir *d, data_t *data)
{
    if (nb_dir_in_path(d->path) > 0)
        check_for_recursive(d, data);
    return 0;
}
