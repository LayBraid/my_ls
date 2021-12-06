/*
** EPITECH PROJECT, 2021
** printf
** File description:
** No file there , just an epitech header example
*/

#ifndef PRINTF_STRUCT_H
    #define PRINTF_STRUCT_H

    #include "my.h"

typedef struct type_flags {
    char flag;
    void (* function)(char *str, va_list param, int i);
} flags;

typedef struct type_flags_all {
    flags **simple;
    flags **point;
    flags **add;
    flags **space;
    flags **h;
    flags **sub;
} all_flags;

#endif
