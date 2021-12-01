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
    time = ctime(&stats.st_mtime);
    my_printf("time: %s\n", time);
    time = my_strncpy(time, time, 12);
    my_printf("time: %s\n", time);
    return time;
}
