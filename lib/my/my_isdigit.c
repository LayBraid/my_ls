/*
** EPITECH PROJECT, 2021
** printf
** File description:
** No file there , just an epitech header example
*/

#include "my.h"

int my_isdigit(char digit)
{
    if (digit < '0' || digit > '9')
        return 0;
    return 1;
}
