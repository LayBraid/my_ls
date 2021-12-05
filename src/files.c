/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** No file there , just an epitech header example
*/

#include "../include/files.h"

int file_info_next(data_t *data, struct stat *stats, int i, int j)
{
    data->directory[i]->files[j]->date = convert_ctime_to_date(stats);
    data->directory[i]->files[j]->nb = stats->st_nlink;
    data->directory[i]->files[j]->perm = get_permissions(stats);
    data->directory[i]->total += (int) stats->st_blocks;
    if (my_int_len((int) stats->st_size) > data->directory[i]->max_size)
        data->directory[i]->max_size = my_int_len((int) stats->st_size);
    if (my_int_len(stats->st_nlink) > data->directory[i]->max_link)
        data->directory[i]->max_link = my_int_len(stats->st_nlink);
    return 0;
}

int file_info(data_t *data, int i, int j)
{
    struct stat *stats = malloc(sizeof(struct stat));
    struct passwd *pw;
    struct group *grp = NULL;
    if (stat(data->directory[i]->files[j]->path, stats) == -1)
        my_exit(ERROR_STAT12, 84);
    grp = getgrgid(stats->st_gid);
    pw = getpwuid(stats->st_uid);
    if (grp != NULL)
        data->directory[i]->files[j]->group = grp->gr_name;
    if (pw != NULL)
        data->directory[i]->files[j]->user = pw->pw_name;
    else
        data->directory[i]->files[j]->user = "pw == null";
    data->directory[i]->files[j]->stats = stats;
    data->directory[i]->files[j]->size = (int) stats->st_size;
    data->directory[i]->files[j]->time = stats->st_mtime;
    file_info_next(data, stats, i, j);
    return 0;
}

int check_files(data_t* data)
{
    char *str;

    for (int i = 0; i < data->nb_dir; i++) {
        str = data->directory[i]->path;
        if (str[my_strlen(str)] != '/')
            str = my_strcat(str, "/");
        if (opendir(str) == NULL)
            switch (errno) {
                case ENOENT:
                    my_printf("ls: %s: %s", data->directory[i]->path,
                        ERROR_NO_FILE_DIRECTORY);
                    exit(84);
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
    while ((dp = readdir(dir)) != NULL)
        if (dp->d_name[0] != '.')
            nb++;
    closedir(dir);
    return nb;
}

int nb_dir_in_path(char *path)
{
    int nb = 0;
    DIR *dir = opendir(path);
    char *str;
    struct dirent *dp;
    struct stat *stats;

    if (dir == NULL)
        return (84);
    while ((dp = readdir(dir)) != NULL) {
        stats = malloc(sizeof(struct stat));
        str = path;
        str = my_strcat_c(str, '/');
        str = my_strcat(str, dp->d_name);
        if (stat(str, stats) == -1)
            my_exit(ERROR_STAT12, 84);
        if (S_ISDIR(stats->st_mode) && dp->d_name[0] != '.')
            nb++;
    }
    closedir(dir);
    return nb;
}
