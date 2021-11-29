/*
** EPITECH PROJECT, 2021
** printf
** File description:
** No file there , just an epitech header example
*/

#include "my.h"

void my_put_octal(int nb)
{
    char *result;
    my_putchar(92);
    result = convert_decimal_to_any(nb, 8);
    for (int i = my_strlen(result); i < 3; i++)
        my_putchar('0');
    my_putstr(result);
}
