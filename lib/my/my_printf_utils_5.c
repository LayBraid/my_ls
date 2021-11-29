/*
** EPITECH PROJECT, 2021
** printf
** File description:
** No file there , just an epitech header example
*/

#include "my.h"

void my_printf_octal_precision(char *str, va_list param, int i)
{
    int nb = va_arg(param, int);
    char *result;
    int len;
    int want = (int) str[1] - 48;

    if (str[2] != 'b' || i < 0)
        return;
    result = convert_decimal_to_any(nb, 8);
    len = my_strlen(result);
    while (want > len) {
        my_putchar('0');
        want--;
    }
    my_putstr(result);
}

void my_printf_hexa_low_precision(char *str, va_list param, int i)
{
    int nb = va_arg(param, int);
    char *result;
    int len;
    int want = (int) str[1] - 48;

    if (str[2] != 'b' || i < 0)
        return;
    result = convert_decimal_to_any(nb, 16);
    result = my_str_lowcase(result);
    len = my_strlen(result);
    while (want > len) {
        my_putchar('0');
        want--;
    }
    my_putstr(result);
}

void my_printf_hexa_up_precision(char *str, va_list param, int i)
{
    int nb = va_arg(param, int);
    char *result;
    int len;
    int want = (int) str[1] - 48;

    if (str[2] != 'b' || i < 0)
        return;
    result = convert_decimal_to_any(nb, 16);
    result = my_str_upcase(result);
    len = my_strlen(result);
    while (want > len) {
        my_putchar('0');
        want--;
    }
    my_putstr(result);
}
