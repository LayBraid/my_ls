/*
** EPITECH PROJECT, 2021
** MyHunter
** File description:
** No file there , just an epitech header example
*/

#include "my.h"

int my_strlen(char const *str)
{
    int length = 0;

    while (str[length])
        length++;
    return length;
}
