/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** No file there , just an epitech header example
*/

#ifndef MY_LS_TIME_UTILS_H
    #define MY_LS_TIME_UTILS_H

    #include "my_ls.h"
    #include "time.h"
    #include "struct.h"

date_t *convert_ctime_to_date(struct stat stats);

char *fill_time(struct stat stats);

#endif
