/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** No file there , just an epitech header example
*/

#include "../include/time_utils.h"

char *extract_between(char *str, int start, int stop)
{
    char *result = "";

    for ( ; start <= stop; start++)
        result = my_strcat_c(result, str[start]);
    return result;
}

int get_int_month_next(char *str)
{
    if (my_strcmp(str, "Jul") == 0)
        return 7;
    if (my_strcmp(str, "Aug") == 0)
        return 8;
    if (my_strcmp(str, "Sep") == 0)
        return 9;
    if (my_strcmp(str, "Oct") == 0)
        return 10;
    if (my_strcmp(str, "Nov") == 0)
        return 11;
    if (my_strcmp(str, "Dec") == 0)
        return 12;
    return 0;
}

int get_int_month(char *str)
{
    if (my_strcmp(str, "Jan") == 0)
        return 1;
    if (my_strcmp(str, "Feb") == 0)
        return 2;
    if (my_strcmp(str, "Mar") == 0)
        return 3;
    if (my_strcmp(str, "Apr") == 0)
        return 4;
    if (my_strcmp(str, "May") == 0)
        return 5;
    if (my_strcmp(str, "Jun") == 0)
        return 6;
    return get_int_month_next(str);
}

date_t *convert_ctime_to_date(struct stat *stats)
{
    char *time;
    date_t *date = malloc(sizeof(date_t));

    time = ctime(&stats->st_mtime);
    date->sec = my_atoi(extract_between(time, 17, 18));
    date->min = my_atoi(extract_between(time, 14, 15));
    date->hour = my_atoi(extract_between(time, 11, 12));
    date->day = my_atoi(extract_between(time, 8, 9));
    date->day_str = extract_between(time, 0, 2);
    date->month = get_int_month(extract_between(time, 4, 6));
    date->month_str = extract_between(time, 4, 6);
    date->year = my_atoi(extract_between(time, 20, 23));
    return date;
}
