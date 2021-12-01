/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** No file there , just an epitech header example
*/

#include "include/directory.h"

char *fill_directory_time(dir *d, struct stat stats)
{
    char *time;
    time = ctime(&stats.st_mtime);
    my_printf("time: %s\n", time);
    time = my_strncpy(time, time, 12);
    my_printf("time: %s\n", time);
    return time;
}

int fill_directory(dir *d)
{
    struct stat stats;
    register struct passwd *pw;
    register uid_t uid;
    struct stat statbuf;
    struct group *grp;
    grp = getgrgid(statbuf.st_gid);
    uid = geteuid();
    pw = getpwuid(uid);

    if (grp != NULL)
        d->group = grp->gr_name;
    d->user = pw->pw_name;
    if (stat(d->path, &stats) < 0)
        my_exit(ERROR_STAT, 84);
    d->modification = fill_directory_time(d, stats);
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
