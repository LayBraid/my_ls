/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** No file there , just an epitech header example
*/

#ifndef MY_LS_FORMATING_UTILS_H
    #define MY_LS_FORMATING_UTILS_H

    #include "my_ls.h"

char *get_str_file(dir *d);

char *get_str_dir(data_t *data);

char *get_str_file_file(file *f);

int format_print_skip(data_t *data, int i);

int the_printf_line_file(data_t *data);

int the_printf_line_dir(data_t *data, int i);

#endif
