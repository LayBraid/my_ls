/*
** EPITECH PROJECT, 2021
** printf
** File description:
** No file there , just an epitech header example
*/

#include "my.h"
#include "printf.h"
void my_printf_char(char *str, va_list param, int i)
{
    if (str[0] != 'c' || i < 0)
        return;
    my_putchar((char) va_arg(param, int));
}

void my_printf_string(char *str, va_list param, int i)
{
    if (str[0] != 's' || i < 0)
        return;
    my_putstr((char *) va_arg(param, char *));
}

void my_printf_string_octal(char *str, va_list param, int i)
{
    char *arg = va_arg(param, char *);

    if (str[0] != 'S' || i < 0)
        return;
    for (int j = 0; arg[j]; j++) {
        if (arg[j] > 31 && arg[j] < 122)
            my_putchar(arg[j]);
        else
            my_put_octal(arg[j]);
    }
}

void my_printf_int(char *str, va_list param, int i)
{
    (void) str;
    (void) i;

    my_put_nbr((int) va_arg(param, int));
}

void my_printf_int_0(char *str, va_list param, int i)
{
    int tmp = va_arg(param, int);
    int len = my_int_len(tmp);
    int want = (int) str[1] - 48;

    if (my_str_contains_c(str[2], PRINTF_FLAGS_INT) != 1 || i < 0)
        return;
    while (want > len) {
        my_putchar('0');
        want--;
    }
    my_put_nbr(tmp);
}
