/*
** EPITECH PROJECT, 2021
** printf
** File description:
** No file there , just an epitech header example
*/

#include "my.h"

char *get_param(char *str, int i)
{
    char *param = "";

    for (int j = 1; j + i < (i + 4); j++) {
        if (my_str_contains_c(str[j + i], PRINTF_FLAGS) == 1)
            param = my_strcat_c(param, str[j + i]);
        else
            return param;
    }
    return param;
}

void search_flag_extra(char *str, va_list param, int i)
{
    if (my_isdigit(str[0]) == 1 && my_isdigit(str[1]) == 1)
        my_printf_space(str, param, i);
}

char *reformat_p(char *param)
{
    while (my_str_contains_c(param[my_strlen(param) - 1],
                                PRINTF_FLAGS_NO_END) == 1) {
        if (param[0] == '%')
            return param;
        param = my_strncpy(param, param, (my_strlen(param) - 1));
    }
    return param;
}
