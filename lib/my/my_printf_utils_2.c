/*
** EPITECH PROJECT, 2021
** printf
** File description:
** No file there , just an epitech header example
*/

#include "my.h"

void my_printf_percentage(char *str, va_list param, int i)
{
    (void) param;

    if (str[0] != '%' || i < 0)
        return;
    my_putchar('%');
}

void my_printf_binary(char *str, va_list param, int i)
{
    int nb = va_arg(param, int);
    char *result;

    if (str[0] != 'b' || i < 0)
        return;
    result = convert_decimal_to_any(nb, 2);
    my_putstr(result);
}

void my_printf_octal(char *str, va_list param, int i)
{
    int nb = va_arg(param, int);
    char *result;
    (void) str;

    if (i < 0)
        return;
    result = convert_decimal_to_any(nb, 8);
    my_putstr(result);
}

void my_printf_hexa_low(char *str, va_list param, int i)
{
    int nb = va_arg(param, int);
    char *result;
    (void) str;

    if (i < 0)
        return;
    result = convert_decimal_to_any(nb, 16);
    result = my_str_lowcase(result);
    my_putstr(result);
}

void my_printf_hexa_up(char *str, va_list param, int i)
{
    int nb = va_arg(param, int);
    char *result;
    (void) str;

    if (i < 0)
        return;
    result = convert_decimal_to_any(nb, 16);
    result = my_str_upcase(result);
    my_putstr(result);
}
