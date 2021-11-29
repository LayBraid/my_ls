/*
** EPITECH PROJECT, 2021
** printf
** File description:
** No file there , just an epitech header example
*/

#include "my.h"

int my_str_contains_c(char c, char *str)
{
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == c)
            return 1;
    }
    return 0;
}
