/*
** EPITECH PROJECT, 2021
** printf
** File description:
** No file there , just an epitech header example
*/

#include "my.h"

char *my_str_lowcase(char *str)
{
    for (int i = 0; i < my_strlen(str); ++i) {
        if (str[i] > 64 && str[i] < 91)
            str[i] += 32;
    }
    return (str);
}
