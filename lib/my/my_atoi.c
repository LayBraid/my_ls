/*
** EPITECH PROJECT, 2021
** printf
** File description:
** No file there , just an epitech header example
*/

#include "my.h"

int my_atoi(char *str)
{
    int res = 0;

    for (int i = 0; str[i] != '\0'; ++i)
        if (str[i] >= '0' && str[i] <= '9')
            res = res * 10 + str[i] - 48;
    return res;
}
