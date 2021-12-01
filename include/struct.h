/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** No file there , just an epitech header example
*/

#ifndef MY_LS_STRUCT_H
    #define MY_LS_STRUCT_H

typedef struct file_struct
{
    char *path;
    int nb;
    int type;
    char *perm;
    char *user;
    char *group;
    int size;
    char *modification;
} file;

typedef struct directory_struct
{
    char *path;
    int nb_files;
    int total;
    int nb;
    char *perm;
    char *user;
    char *group;
    int size;
    char *modification;
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
} data_t;

#endif
