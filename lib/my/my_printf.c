/*
** EPITECH PROJECT, 2021
** printf
** File description:
** No file there , just an epitech header example
*/

#include "my.h"

int my_printf(char *str, ...)
{
    va_list param;
    all_flags *my_flags;
    char *p;

    va_start(param, str);
    my_flags = get_all_flags();
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == '%') {
            p = get_param(str, i);
            p = reformat_p(p);
            search_flag(str, param, i, my_flags);
            i += my_strlen(p);
        } else
            my_putchar(str[i]);
    }
    va_end(param);
    free(my_flags);
    return (0);
}
