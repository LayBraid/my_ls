/*
** EPITECH PROJECT, 2021
** MY_LS
** File description:
** No file there , just an epitech header example
*/

#include "include/my_ls.h"

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

    if (stat(data->directory[i]->files[j]->path, &stats) < 0)
        my_exit(ERROR_STAT, 84);

    data->directory[i]->files[j]->size = (int) stats.st_size;
    strftime(time, 49, "%b %d %H:%M", localtime(&(stats.st_mtime)));
    data->directory[i]->files[j]->modification = time;

    data->directory[i]->files[j]->nb = stats.st_nlink;

    data->directory[i]->files[j]->perm = get_permissions(stats);
    return 0;
}

int my_print_verif(data_t *data)
{
    for (int i = 0; i < data->nb_dir; i++) {
        my_printf("\ndir: '%s' >>\n", data->directory[i]->path);
        for (int j = 0; j < data->directory[i]->nb_files; j++) {
            my_printf("    | %s %d %s %s %d %s %s | type: %d\n",
                      data->directory[i]->files[j]->perm,
                      data->directory[i]->files[j]->nb,
                      data->directory[i]->files[j]->user,
                      data->directory[i]->files[j]->group,
                      data->directory[i]->files[j]->size,
                      data->directory[i]->files[j]->modification,
                      data->directory[i]->files[j]->path,
                      data->directory[i]->files[j]->type);
        }
    }
    return 0;
}

int main(int ac, char **av)
{
    data_t* data = malloc(sizeof(data_t));
    init_data(data, av);
    get_directory(data, av, ac);
    get_flags(data, av, ac);
    check_files(data);
    fill_files(data);
    for (int i = 0; i < data->nb_dir; i++)
        (data->t == 0) ? sort_files_in_directory(data->directory[i]) :
        sort_files_in_directory_by_date(data->directory[i]);
    format_result(data);
    //my_print_verif(data);
    return 0;
}
