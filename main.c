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

int file_info(data_t *data, int i, int j)
{
    struct stat stats;
    char *time = malloc(sizeof(char) * 50);
    register struct passwd *pw;
    register uid_t uid;
    struct stat statbuf;
    struct group *grp;

    if ((grp = getgrgid(statbuf.st_gid)) != NULL)
        data->directory[i]->files[j]->group = grp->gr_name;

    uid = geteuid();
    pw = getpwuid(uid);
    data->directory[i]->files[j]->user = pw->pw_name;

    if (stat(data->directory[i]->files[j]->path, &stats) < 0) {
        my_putstr(ERROR_STAT);
        exit(84);
    }

    data->directory[i]->files[j]->size = (int) stats.st_size;
    strftime(time, 49, "%b %d %H:%M", localtime(&(stats.st_mtime)));
    data->directory[i]->files[j]->modification = time;

    data->directory[i]->files[j]->nb = stats.st_nlink;

    data->directory[i]->files[j]->perm = "";
    data->directory[i]->files[j]->perm = my_strcat_c(data->directory[i]->files[j]->perm, (S_ISDIR(stats.st_mode)) ? 'd' : '-');
    data->directory[i]->files[j]->perm = my_strcat_c(data->directory[i]->files[j]->perm, (stats.st_mode & S_IWUSR) ? 'w' : '-');
    data->directory[i]->files[j]->perm = my_strcat_c(data->directory[i]->files[j]->perm, (stats.st_mode & S_IRUSR) ? 'r' : '-');
    data->directory[i]->files[j]->perm = my_strcat_c(data->directory[i]->files[j]->perm, (stats.st_mode & S_IXUSR) ? 'x' : '-');
    data->directory[i]->files[j]->perm = my_strcat_c(data->directory[i]->files[j]->perm, (stats.st_mode & S_IRGRP) ? 'r' : '-');
    data->directory[i]->files[j]->perm = my_strcat_c(data->directory[i]->files[j]->perm, (stats.st_mode & S_IWGRP) ? 'w' : '-');
    data->directory[i]->files[j]->perm = my_strcat_c(data->directory[i]->files[j]->perm, (stats.st_mode & S_IXGRP) ? 'x' : '-');
    data->directory[i]->files[j]->perm = my_strcat_c(data->directory[i]->files[j]->perm, (stats.st_mode & S_IROTH) ? 'r' : '-');
    data->directory[i]->files[j]->perm = my_strcat_c(data->directory[i]->files[j]->perm, (stats.st_mode & S_IWOTH) ? 'w' : '-');
    data->directory[i]->files[j]->perm = my_strcat_c(data->directory[i]->files[j]->perm, (stats.st_mode & S_IXOTH) ? 'x' : '-');
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
        sort_files_in_directory(data->directory[i]);
        my_printf("\ndir: '%s' >>\n", data->directory[i]->path);
        for (int j = 0; j < data->directory[i]->nb_files; j++) {
            my_printf("    | %s %d %s %s %d %s %s\n",
                   data->directory[i]->files[j]->perm,
                   data->directory[i]->files[j]->nb,
                   data->directory[i]->files[j]->user,
                   data->directory[i]->files[j]->group,
                   data->directory[i]->files[j]->size,
                   data->directory[i]->files[j]->modification,
                   data->directory[i]->files[j]->path);
        }
    }
    return 0;
}
