/*
** EPITECH PROJECT, 2021
** MyHunter
** File description:
** No file there , just an epitech header example
*/

#include "my.h"

int my_rand(int i, int j)
{
    int random_value = rand();
    int r = random_value % j;
    if (r < i)
        r += i;
    return r;
}
