/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** No file there , just an epitech header example
*/

#include "include/directory.h"

int errno_print(char *str)
{
    switch (errno) {
        case ENOENT:
            my_printf("ls: %s: %s", str,
                      ERROR_NO_FILE_DIRECTORY);
            exit(84);
    }
    return 0;
}

int next_fill_dir(dir *d, struct stat *stats, data_t *data)
{
    d->date = convert_ctime_to_date(stats);
    d->perm = get_permissions(stats);
    d->size = (int) stats->st_size;
    d->nb = stats->st_nlink;
    if (my_int_len(d->nb) > data->max_link)
        data->max_link = my_int_len(d->nb);
    if (my_int_len(d->size) > data->max_size)
        data->max_size = my_int_len(d->size);
    return 0;
}

int fill_next_file(file *f, struct stat *stats, data_t *data)
{
    f->perm = get_permissions(stats);
    f->size = (int) stats->st_size;
    f->nb = stats->st_nlink;
    if (my_int_len(f->nb) > data->max_link)
        data->max_link = my_int_len(f->nb);
    if (my_int_len(f->size) > data->max_size)
        data->max_size = my_int_len(f->size);
    return 0;
}

int get_directory_final(data_t* data, char **av, int *array, struct stat *stats)
{
    if (S_ISDIR(stats->st_mode)) {
        data->directory[array[3] - array[0] - array[1]] = malloc(sizeof(dir));
        data->directory[array[3] - array[0] - array[1]]->path = av[array[3]];
        data->directory[array[3] - array[0] - array[1]]->name = av[array[3]];
        fill_directory(data->directory[array[3] - array[0] - array[1]], data);
        array[2]++;
    } else {
        data->files[array[3] - array[0] - array[2]] = malloc(sizeof(dir));
        data->files[array[3] - array[0] - array[2]]->path = av[array[3]];
        data->files[array[3] - array[0] - array[2]]->name = av[array[3]];
        fill_my_file(data->files[array[3] - array[0] - array[2]], data);
        array[1]++;
    }
    return 0;
}

int get_directory_next(data_t* data, char **av, int ac)
{
    struct stat *stats;
    int array[4] = {0};
    array[0] = 1;
    array[1] = 0;
    array[2] = 0;

    for (array[3] = 1; array[3] < ac; array[3]++) {
        if (av[array[3]][0] != '-') {
            stats = malloc(sizeof(struct stat));
            stat(av[array[3]], stats);
            get_directory_final(data, av, array, stats);
        } else
            array[0]++;
    }
    return 0;
}