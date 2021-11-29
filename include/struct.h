/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** No file there , just an epitech header example
*/

#ifndef MY_LS_STRUCT_H
    #define MY_LS_STRUCT_H

typedef struct flags_list
{
    char R;
    char r;
    char d;
    char l;
    char t;
} flags_t;

typedef struct all_data
{
    int nb_files;
    char **files;
    flags_t *flags;
} data_t;

#endif
