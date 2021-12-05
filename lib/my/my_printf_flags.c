/*
** EPITECH PROJECT, 2021
** printf
** File description:
** No file there , just an epitech header example
*/

#include "my.h"

void search_next_flag(char *p, va_list param, int i, all_flags *my_flags)
{
    for (int j = 0; j < 3; j++) {
        if (my_flags->space[j]->flag == p[my_strlen(p) - 1] && p[0] == ' ')
            return my_flags->space[j]->function(p, param, i);
    }
    for (int j = 0; j < 9; j++) {
        if (my_flags->h[j]->flag == p[my_strlen(p) - 1] && p[0] == '#')
            return my_flags->h[j]->function(p, param, i);
    }
    for (int j = 0; j < 3; j++) {
        if (my_flags->sub[j]->flag == p[1] && p[0] == '-')
            return my_flags->sub[j]->function(p, param, i);
    }
    return search_flag_extra(p, param, i);
}

void search_flag(char *str, va_list param, int i, all_flags *my_flags)
{
    char *p = get_param(str, i);
    p = reformat_p(p);

    for (int j = 0; j < 12; j++) {
        if (my_flags->simple[j]->flag == p[0])
            return my_flags->simple[j]->function(p, param, i);
    }
    for (int j = 0; j < 8; j++) {
        if (my_flags->point[j]->flag == p[my_strlen(p) - 1] &&
            (p[0] == '.' || p[0] == '0'))
            return my_flags->point[j]->function(p, param, i);
    }
    for (int j = 0; j < 3; j++) {
        if (my_flags->add[j]->flag == p[1] && p[0] == '+')
            return my_flags->add[j]->function(p, param, i);
    }
    return search_next_flag(p, param, i, my_flags);
}
