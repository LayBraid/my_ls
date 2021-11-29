/*
** EPITECH PROJECT, 2021
** printf
** File description:
** No file there , just an epitech header example
*/

#include "my.h"

int my_int_len(int nb)
{
    int length = 1;
    while (nb > 10) {
        nb /= 10;
        length++;
    }
    return length;
}
