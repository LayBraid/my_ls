/*
** EPITECH PROJECT, 2021
** printf
** File description:
** No file there , just an epitech header example
*/

#include "my.h"

char *my_str_upcase(char *str)
{
    for (int i = 0; i < my_strlen(str); ++i) {
        if (str[i] > 96 && str[i] < 123)
            str[i] -= 32;
    }
    return (str);
}
