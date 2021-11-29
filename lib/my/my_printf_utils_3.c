/*
** EPITECH PROJECT, 2021
** printf
** File description:
** No file there , just an epitech header example
*/

#include "my.h"
#include "printf.h"

void my_printf_string_precision(char *str, va_list param, int i)
{
    int length = (int) str[1] - 48;
    char *parameter = (char *) va_arg(param, char *);
    int length_param = my_strlen(parameter);

    if (str[2] != 's' || i < 0)
        return;
    if (length < length_param)
        for (int j = 0; j < length; j++)
            my_putchar(parameter[j]);
    else
        my_putstr(parameter);
}

void my_printf_int_add(char *str, va_list param, int i)
{
    int tmp = va_arg(param, int);

    if (my_str_contains_c(str[1], PRINTF_FLAGS_INT) != 1 || i < 0)
        return;
    if (tmp > -1)
        my_putchar('+');
    my_put_nbr(tmp);
}

void my_printf_int_space(char *str, va_list param, int i)
{
    int tmp = va_arg(param, int);

    if (my_str_contains_c(str[1], PRINTF_FLAGS_INT) != 1 || i < 0)
        return;
    if (tmp > -1 && my_strlen(str) == 2)
        my_putchar(' ');
    my_put_nbr(tmp);
}

void my_printf_address(char *str, va_list param, int i)
{
    char *result;
    long long nb = (long long) va_arg(param,long long);

    if (str[0] != 'p' || i < 0)
        return;
    result = convert_decimal_to_any_long(nb, 16);
    my_putstr("0x");
    my_putstr(result);
}

void my_printf_int_spacer(char *str, va_list param, int i)
{
    (void) i;
    int tmp = va_arg(param, int);
    int len = my_int_len(tmp);
    char *want = malloc(sizeof(char) * (my_strlen(str) - 1));
    int nb;

    if (tmp > -1 && my_strlen(str) == 2)
        my_putchar(' ');
    else {
        for (int j = 1; j < my_strlen(str) - 1; j++)
            want[j - 1] = str[j];
        want[my_strlen(str) - 1] = '\0';
        nb = my_atoi(want);
        while (nb > len) {
            my_putchar(' ');
            nb--;
        }
    }
    my_put_nbr(tmp);
}
