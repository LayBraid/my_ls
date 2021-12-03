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

int nb_file_in_arg(char **av);

int get_directory(data_t* data, char **av, int ac);

#endif
