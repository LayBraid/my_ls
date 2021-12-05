/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** No file there , just an epitech header example
*/

#include "../include/directory.h"

int fill_directory(dir *d, data_t *data)
{
    struct stat *stats = malloc(sizeof(struct stat));
    register struct passwd *pw;
    register uid_t uid;
    struct group *grp;

    if (stat(d->path, stats) == -1)
        errno_print(d->name);
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
    next_fill_dir(d, stats, data);
    return 0;
}

int fill_my_file(file *f, data_t *data)
{
    struct stat *stats = malloc(sizeof(struct stat));
    register struct passwd *pw;
    register uid_t uid;
    struct group *grp;

    if (stat(f->path, stats) == -1)
        errno_print(f->name);
    grp = getgrgid(stats->st_gid);
    uid = geteuid();
    pw = getpwuid(uid);
    if (grp != NULL)
        f->group = grp->gr_name;
    f->user = pw->pw_name;
    f->stats = stats;
    f->time = stats->st_mtime;
    f->date = convert_ctime_to_date(stats);
    fill_next_file(f, stats, data);
    return 0;
}

int nb_dir_in_arg(char **av)
{
    int nb = 0;
    struct stat *stats;

    for (int i = 1; av[i]; i++) {
        stats = malloc(sizeof(struct stat));
        stat(av[i], stats);
        if (S_ISDIR(stats->st_mode)) {
            nb++;
        }
    }
    return nb;
}

int nb_file_in_arg(char **av, int ac)
{
    int nb = 0;
    struct stat *stats;

    for (int i = 1; i < ac; i++) {
        stats = malloc(sizeof(struct stat));
        stat(av[i], stats);
        if (av[i][0] == '-')
            continue;
        if (!S_ISDIR(stats->st_mode)) {
            nb++;
        }
    }
    return nb;
}

int get_directory(data_t* data, char **av, int ac)
{
    if (data->nb_dir == 0 && data->nb_files == 0) {
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
    get_directory_next(data, av, ac);
    return 0;
}
