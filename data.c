/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** No file there , just an epitech header example
*/
#include "include/data.h"

int init_data(data_t *data, char **av)
{
    data->nb_dir = nb_dir_in_arg(av);
    data->R = 0;
    data->r = 0;
    data->d = 0;
    data->l = 0;
    data->t = 0;
    data->max_link = 0;
    data->max_size = 0;
    return 0;
}
