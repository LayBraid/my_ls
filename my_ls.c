/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** No file there , just an epitech header example
*/

#include "include/my_ls.h"

int my_ls(int ac, char **av)
{
    data_t* data = malloc(sizeof(data_t));

    init_data(data, av);
    get_directory(data, av, ac);
    get_flags(data, av, ac);
    check_files(data);
    fill_files(data);
    for (int i = 0; i < data->nb_dir; i++)
        sort_files_in_directory(data->directory[i]);
    format_result(data);
    if (data->R == 1)
        flag_recursive(data);
    free(data);
    return 0;
}
