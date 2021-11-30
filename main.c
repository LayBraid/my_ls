/*
** EPITECH PROJECT, 2021
** MY_LS
** File description:
** No file there , just an epitech header example
*/

#include "include/my_ls.h"

int see_param(data_t* data)
{
    my_printf("R: %d", data->flags->R);
    my_printf("d: %d", data->flags->d);
    return 0;
}

int nb_dir_in_arg(char **av)
{
    int nb = 0;

    for (int i = 1; av[i]; i++) {
        if (av[i][0] != '-')
            nb++;
    }
    return nb;
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

int get_directory(data_t* data, char **av, int ac)
{
    int nb_skip = 1;

    if (data->nb_dir == 0) {
        data->nb_dir = 1;
        data->directory = malloc(sizeof(dir *) * 1);
        data->directory[0] = malloc(sizeof(dir));
        data->directory[0]->path = ".";
        return 1;
    } else
        data->directory = malloc(sizeof(dir *) * data->nb_dir);
    for (int i = 1; i < ac; i++) {
        if (av[i][0] != '-') {
            data->directory[i - nb_skip] = malloc(sizeof(dir));
            data->directory[i - nb_skip]->path = av[i];
        } else
            nb_skip++;
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

int my_ls(char *path, data_t *data)
{
    DIR *dir = opendir(path);
    struct dirent *dp;
    int nb = nb_files_in_path(path);

    if (dir == NULL)
        return (84);
    char **all = malloc(sizeof(char *) * nb);
    int i = 0;
    while ((dp = readdir(dir)) != NULL) {
        if (dp->d_name[0] != '.') {
            all[i] = dp->d_name;
            i++;
        }
    }
    my_array_str_sort(all, nb);
    closedir(dir);
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
                j++;
            }
        }
    }
    return 0;
}

int main(int ac, char **av)
{
    data_t* data = malloc(sizeof(data_t));
    data->nb_dir = nb_dir_in_arg(av);
    get_directory(data, av, ac);
    check_files(data);
    fill_files(data);
    for (int i = 0; i < data->nb_dir; i++) {
        my_printf("\ndir: %s >>\n", data->directory[i]->path);
        for (int j = 0; j < data->directory[i]->nb_files; j++)
            my_printf("    | file: %s\n", data->directory[i]->files[j]->path);
    }
    return 0;
}
