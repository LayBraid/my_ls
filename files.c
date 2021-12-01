/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** No file there , just an epitech header example
*/

#include "include/files.h"

int sort_files_in_directory(dir *d)
{
    file *tmp;
    for (int i = 0; i < d->nb_files - 1; i++) {
        if (my_strcmp(d->files[i]->path, d->files[i + 1]->path) > 0) {
            tmp = d->files[i];
            d->files[i] = d->files[i + 1];
            d->files[i + 1] = tmp;
            sort_files_in_directory(d);
        }
    }
    return 0;
}

int fill_files(data_t *data)
{
    DIR *dir;
    struct dirent *dp;
    int j;

    for (int i = 0; i < data->nb_dir; i++) {
        j = 0;
        data->directory[i]->nb_files = nb_files_in_path(data->
                directory[i]->path);
        data->directory[i]->files = malloc(sizeof(file *) * data->
                directory[i]->nb_files);
        dir = opendir(data->directory[i]->path);
        while ((dp = readdir(dir)) != NULL) {
            if (dp->d_name[0] != '.') {
                data->directory[i]->files[j] = malloc(sizeof(file));
                data->directory[i]->files[j]->path = dp->d_name;
                file_info(data, i, j);
                j++;
            }
        }
    }
    return 0;
}

int check_files(data_t* data)
{
    char *str;

    for (int i = 0; i < data->nb_dir; i++) {
        str = data->directory[i]->path;
        if (str[my_strlen(str)] != '/')
            str = my_strcat(str, "/");
        str = my_strcat(str, ".");
        if (opendir(str) == NULL) {
            switch (errno) {
                case ENOENT:
                    my_putstr(ERROR_NO_FILE_DIRECTORY);
                    exit(84);
            }
        }
    }
    return 0;
}

int nb_files_in_path(char *path)
{
    int nb = 0;
    DIR *dir = opendir(path);
    struct dirent *dp;

    if (dir == NULL)
        return (84);
    while ((dp = readdir(dir)) != NULL) {
        if (dp->d_name[0] != '.')
            nb++;
    }
    closedir(dir);
    return nb;
}
