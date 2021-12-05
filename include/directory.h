/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** No file there , just an epitech header example
*/

#ifndef MY_LS_DIRECTORY_H
    #define MY_LS_DIRECTORY_H

    #include "my_ls.h"
    #include "permissions_utils.h"

int nb_dir_in_arg(char **av);

int nb_file_in_arg(char **av, int ac);

int get_directory(data_t* data, char **av, int ac);

int errno_print(char *str);

int next_fill_dir(dir *d, struct stat *stats, data_t *data);

int fill_next_file(file *f, struct stat *stats, data_t *data);

int fill_directory(dir *d, data_t *data);

int fill_my_file(file *f, data_t *data);

int get_directory_next(data_t* data, char **av, int ac);

#endif
