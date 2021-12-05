/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** No file there , just an epitech header example
*/

#ifndef MY_LS_SORT_H
    #define MY_LS_SORT_H

    #include "my_ls.h"

int rev_files_in_directory(dir *d);

int sort_files_in_directory(dir *d);

int sort_files_in_directory_by_date(dir *d);

int sort_files_in_data(data_t *d);

int sort_files_in_data_by_date(data_t *d);

int rev_files_in_data(data_t *d);

int format_sort(data_t *data);

#endif
