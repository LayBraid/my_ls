/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** No file there , just an epitech header example
*/

#include "my.h"

int my_exit(char *reason, int nb)
{
    my_putstr(reason);
    exit(nb);
}
