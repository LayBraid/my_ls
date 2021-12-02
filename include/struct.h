/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** No file there , just an epitech header example
*/

#ifndef MY_LS_STRUCT_H
    #define MY_LS_STRUCT_H

typedef struct date_struct
{
    int sec;
    int min;
    int hour;
    int day;
    char *day_str;
    int month;
    char *month_str;
    int year;
} date_t;

typedef struct file_struct
{
    char *path;
    int nb;
    int type;
    char *perm;
    char *user;
    char *group;
    int size;
    date_t *date;
} file;

typedef struct directory_struct
{
    char *path;
    int nb_files;
    int total;
    int max_size;
    int max_link;
    int nb;
    char *perm;
    char *user;
    char *group;
    int size;
    date_t *date;
    file **files;
} dir;

typedef struct all_data
{
    int nb_dir;
    dir **directory;
    int R;
    int r;
    int d;
    int l;
    int t;
    int max_size;
    int max_link;
} data_t;

#endif
