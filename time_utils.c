/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** No file there , just an epitech header example
*/

#include "include/time_utils.h"

char *fill_time(struct stat stats)
{
    char *time;
    char *result = "";
    time = ctime(&stats.st_mtime);
    result = my_strcat_c(result, time[4]);
    result = my_strcat_c(result, time[5]);
    result = my_strcat_c(result, time[6]);
    result = my_strcat_c(result, time[7]);
    result = my_strcat_c(result, time[8]);
    result = my_strcat_c(result, time[9]);
    result = my_strcat_c(result, time[10]);
    result = my_strcat_c(result, time[11]);
    result = my_strcat_c(result, time[12]);
    result = my_strcat_c(result, time[13]);
    result = my_strcat_c(result, time[14]);
    result = my_strcat_c(result, time[15]);
    return result;
}
