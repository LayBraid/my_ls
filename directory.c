/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** No file there , just an epitech header example
*/

#include "include/directory.h"

int fill_directory(dir *d)
{
    struct stat stats;
    register struct passwd *pw;
    register uid_t uid;
    struct group *grp;

    if (stat(d->path, &stats) < 0)
        my_exit(ERROR_STAT, 84);
    grp = getgrgid(stats.st_gid);
    uid = geteuid();
    pw = getpwuid(uid);
    if (grp != NULL)
        d->group = grp->gr_name;
    d->user = pw->pw_name;
    d->modification = fill_time(stats);
    d->perm = get_permissions(stats);
    d->size = (int) stats.st_size;
    d->nb = stats.st_nlink;
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
            fill_directory(data->directory[i - nb_skip]);
        } else
            nb_skip++;
    }
    return 0;
}
