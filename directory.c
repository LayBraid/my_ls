/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** No file there , just an epitech header example
*/

#include "include/directory.h"

int fill_directory(dir *d, data_t *data)
{
    struct stat *stats = malloc(sizeof(struct stat));
    register struct passwd *pw;
    register uid_t uid;
    struct group *grp;

    if (stat(d->path, stats) == -1)
        switch (errno) {
            case ENOENT:
                my_printf("ls: %s: %s", d->name,
                          ERROR_NO_FILE_DIRECTORY);
                exit(84);
        }
    grp = getgrgid(stats->st_gid);
    uid = geteuid();
    pw = getpwuid(uid);
    if (grp != NULL)
        d->group = grp->gr_name;
    d->user = pw->pw_name;
    d->max_link = 0;
    d->max_size = 0;
    d->stats = stats;
    d->time = stats->st_mtime;
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

int fill_my_file(file *f, data_t *data)
{
    struct stat *stats = malloc(sizeof(struct stat));
    register struct passwd *pw;
    register uid_t uid;
    struct group *grp;

    if (stat(f->path, stats) == -1)
        switch (errno) {
            case ENOENT:
                my_printf("ls: %s: %s", f->name,
                          ERROR_NO_FILE_DIRECTORY);
                exit(84);
        }
    grp = getgrgid(stats->st_gid);
    uid = geteuid();
    pw = getpwuid(uid);
    if (grp != NULL)
        f->group = grp->gr_name;
    f->user = pw->pw_name;
    f->stats = stats;
    f->time = stats->st_mtime;
    f->date = convert_ctime_to_date(stats);
    f->perm = get_permissions(stats);
    f->size = (int) stats->st_size;
    f->nb = stats->st_nlink;
    if (my_int_len(f->nb) > data->max_link)
        data->max_link = my_int_len(f->nb);
    if (my_int_len(f->size) > data->max_size)
        data->max_size = my_int_len(f->size);
    return 0;
}

int nb_dir_in_arg(char **av)
{
    int nb = 0;
    struct stat *stats = malloc(sizeof(struct stat));

    for (int i = 1; av[i]; i++) {
        stat(av[i], stats);
        if (av[i][0] != '-' && S_ISDIR(stats->st_mode)) {
            nb++;
        }
    }
    return nb;
}

int nb_file_in_arg(char **av)
{
    int nb = 0;
    struct stat *stats = malloc(sizeof(struct stat));

    for (int i = 1; av[i]; i++) {
        stat(av[i], stats);
        if (av[i][0] != '-' && !S_ISDIR(stats->st_mode)) {
            nb++;
        }
    }
    return nb;
}

int get_directory(data_t* data, char **av, int ac)
{
    struct stat *stats = malloc(sizeof(struct stat));
    int nb_skip = 1;
    int nb_file = 0;
    int nb_dir = 0;

    if (data->nb_dir == 0) {
        data->nb_dir = 1;
        data->directory = malloc(sizeof(dir *) * 1);
        data->directory[0] = malloc(sizeof(dir));
        data->directory[0]->path = ".";
        data->directory[0]->name = ".";
        fill_directory(data->directory[0], data);
        return 1;
    } else {
        data->directory = malloc(sizeof(dir *) * data->nb_dir);
        data->files = malloc(sizeof(file *) * data->nb_files);
    }
    for (int i = 1; i < ac; i++) {
        if (av[i][0] != '-') {
            stat(av[i], stats);
            if (S_ISDIR(stats->st_mode)) {
                my_printf("ici\n");
                data->directory[i - nb_skip - nb_file] = malloc(sizeof(dir));
                data->directory[i - nb_skip - nb_file]->path = av[i];
                data->directory[i - nb_skip - nb_file]->name = av[i];
                fill_directory(data->directory[i - nb_skip - nb_file], data);
                nb_dir++;
            } else {
                my_printf("là\n");
                data->files[i - nb_skip - nb_dir] = malloc(sizeof(dir));
                data->files[i - nb_skip - nb_dir]->path = av[i];
                data->files[i - nb_skip - nb_dir]->name = av[i];
                fill_my_file(data->files[i - nb_skip - nb_dir], data);
                nb_file++;
            }
        } else
            nb_skip++;
    }
    return 0;
}
