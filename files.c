/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** No file there , just an epitech header example
*/

#include "include/files.h"

int file_info(data_t *data, int i, int j)
{
    struct stat *stats = malloc(sizeof(struct stat));
    struct passwd *pw;
    struct group *grp = NULL;
    if (stat(data->directory[i]->files[j]->path, stats) == -1)
        my_exit(ERROR_STAT, 84);
    grp = getgrgid(stats->st_gid);
    pw = getpwuid(stats->st_uid);
    if (grp != NULL)
        data->directory[i]->files[j]->group = grp->gr_name;
    if (pw != NULL)
        data->directory[i]->files[j]->user = pw->pw_name;
    else
        data->directory[i]->files[j]->user = "pw == null";
    data->directory[i]->files[j]->size = (int) stats->st_size;
    data->directory[i]->files[j]->time = stats->st_mtime;
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
        while ((dp = readdir(dir)) != NULL)
            if (dp->d_name[0] != '.') {
                data->directory[i]->files[j] = malloc(sizeof(file));
                data->directory[i]->files[j]->path = dp->d_name;
                data->directory[i]->files[j]->type = dp->d_type;
                file_info(data, i, j);
                j++;
            }
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
