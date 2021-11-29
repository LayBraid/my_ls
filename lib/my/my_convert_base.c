/*
** EPITECH PROJECT, 2021
** printf
** File description:
** No file there , just an epitech header example
*/

#include "my.h"

char get_c_by_index(int nb)
{
    if (nb >= 0 && nb <= 9)
        return (nb + 48);
    else
        return (nb + 87);
}

char *convert_decimal_to_any(int nb, int base)
{
    char *result = "";

    while (nb > 0) {
        result = my_strcat_c(result, get_c_by_index(nb % base));
        nb /= base;
    }
    my_revstr(result);
    return result;
}

char *convert_decimal_to_any_long(long nb, int base)
{
    char *result = "";

    while (nb > 0) {
        result = my_strcat_c(result, get_c_by_index(nb % base));
        nb /= base;
    }
    my_revstr(result);
    return result;
}
