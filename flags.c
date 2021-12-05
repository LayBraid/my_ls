/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** No file there , just an epitech header example
*/

#include "include/flags.h"

int put_flags(data_t *data, char *str)
{
    for (int i = 0; i < my_strlen(str); i++) {
        switch (str[i]) {
            case 'R':
                data->R = 1;
                break;
            case 'r':
                data->r = 1;
                break;
            case 'd':
                data->d = 1;
                break;
            case 'l':
                data->l = 1;
                break;
            case 't':
                data->t = 1;
                break;
        }
    }
    return 0;
}

int get_flags(data_t *data, char **av, int ac)
{
    if (ac == 1)
        return 1;
    for (int i = 1; i < ac; i++)
        if (av[i][0] == '-')
            put_flags(data, av[i]);
    return 0;
}

int switch_flags(data_t *data, data_t *data_back)
{
    data->R = data_back->R;
    data->r = data_back->r;
    data->t = data_back->t;
    data->l = data_back->l;
    data->d = data_back->d;
    return 0;
}