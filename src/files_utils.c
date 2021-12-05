/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** No file there , just an epitech header example
*/

#include "../include/files.h"

char *get_path(dir *d, struct dirent *dp)
{
    char *path_dir = d->path;
    path_dir = my_strcat(path_dir,"/");
    path_dir = my_strcat(path_dir, dp->d_name);
    return path_dir;
}

int fill_first(struct dirent *dp, dir *d, int *array, data_t *data)
{
    d->files[array[1]] = malloc(sizeof(file));
    d->files[array[1]]->path = get_path(d, dp);
    d->files[array[1]]->name = dp->d_name;
    d->files[array[1]]->type = dp->d_type;
    file_info(data, array[0], array[1]);
    return 0;
}

int fill_files(data_t *data)
{
    DIR *dir;
    int array[2] = {0};
    struct dirent *dp;

    for ( ; array[0] < data->nb_dir; array[0]++) {
        array[1] = 0;
        data->directory[array[0]]->nb_files = nb_files_in_path(data->
                directory[array[0]]->path);
        data->directory[array[0]]->files = malloc(sizeof(file *) * data->
                directory[array[0]]->nb_files);
        dir = opendir(data->directory[array[0]]->path);
        while ((dp = readdir(dir)) != NULL)
            if (dp->d_name[0] != '.') {
                fill_first(dp, data->directory[array[0]], array, data);
                array[1]++;
            }
    }
    return 0;
}