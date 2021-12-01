/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** No file there , just an epitech header example
*/

#include "include/directory.h"

int nb_dir_in_arg(char **av)
{
    int nb = 0;

    for (int i = 1; av[i]; i++) {
        if (av[i][0] != '-')
            nb++;
    }
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
