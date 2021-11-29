/*
** EPITECH PROJECT, 2021
** printf
** File description:
** No file there , just an epitech header example
*/

#include "my.h"

void my_printf_space(char *str, va_list param, int i)
{
    int space = (int) str[1] - 48;
    space += (int) (str[0] - 48) * 10;
    (void) param;

    if (i < 0)
        return;
    for ( ; space > 0; space--)
        my_putchar(' ');
}

void my_printf_h_octal(char *str, va_list param, int i)
{
    my_putchar('0');
    my_printf_octal(str, param, i);
}

void my_printf_h_hexa_low(char *str, va_list param, int i)
{
    my_putstr("0x");
    my_printf_hexa_low(str, param, i);
}

void my_printf_h_hexa_up(char *str, va_list param, int i)
{
    my_putstr("0X");
    my_printf_hexa_up(str, param, i);
}

void my_printf_binary_precision(char *str, va_list param, int i)
{
    int nb = va_arg(param, int);
    char *result;
    int len;
    int want = (int) str[1] - 48;

    if (str[2] != 'b' || i < 0)
        return;
    result = convert_decimal_to_any(nb, 2);
    len = my_strlen(result);
    while (want > len) {
        my_putchar('0');
        want--;
    }
    my_putstr(result);
}
