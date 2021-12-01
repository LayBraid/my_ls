/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** No file there , just an epitech header example
*/

#include "include/permissions_utils.h"

char *get_permissions(struct stat stats)
{
    char *result = "";

    result = my_strcat_c(result, (S_ISDIR(stats.st_mode)) ? 'd' : '-');
    result = my_strcat_c(result, (stats.st_mode & S_IRUSR) ? 'r' : '-');
    result = my_strcat_c(result, (stats.st_mode & S_IWUSR) ? 'w' : '-');
    result = my_strcat_c(result, (stats.st_mode & S_IXUSR) ? 'x' : '-');
    result = my_strcat_c(result, (stats.st_mode & S_IRGRP) ? 'r' : '-');
    result = my_strcat_c(result, (stats.st_mode & S_IWGRP) ? 'w' : '-');
    result = my_strcat_c(result, (stats.st_mode & S_IXGRP) ? 'x' : '-');
    result = my_strcat_c(result, (stats.st_mode & S_IROTH) ? 'r' : '-');
    result = my_strcat_c(result, (stats.st_mode & S_IWOTH) ? 'w' : '-');
    result = my_strcat_c(result, (stats.st_mode & S_IXOTH) ? 'x' : '-');
    return result;
}
