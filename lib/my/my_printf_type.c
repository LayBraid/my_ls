/*
** EPITECH PROJECT, 2021
** printf
** File description:
** No file there , just an epitech header example
*/

#include "my.h"

flags *put_type(char c, void (*function)(char *str, va_list param, int i))
{
    flags *put = malloc(sizeof(flags));
    put->flag = c;
    put->function = function;
    return put;
}

void set_flags_final(all_flags *all)
{
    all->add[2] = put_type('u', my_printf_int_add);
    all->space[0] = put_type('d', my_printf_int_spacer);
    all->space[1] = put_type('i', my_printf_int_spacer);
    all->space[2] = put_type('u', my_printf_int_spacer);
    all->space[0] = put_type('d', my_printf_int_spacer);
    all->space[1] = put_type('i', my_printf_int_spacer);
    all->space[2] = put_type('u', my_printf_int_spacer);
    all->h[0] = put_type('x', my_printf_h_hexa_low);
    all->h[1] = put_type('X', my_printf_h_hexa_up);
    all->h[2] = put_type('o', my_printf_h_octal);
    all->h[3] = put_type('s', my_printf_string);
    all->h[4] = put_type('C', my_printf_char);
    all->h[5] = put_type('S', my_printf_string_octal);
    all->h[6] = put_type('d', my_printf_int);
    all->h[7] = put_type('i', my_printf_int);
    all->h[8] = put_type('u', my_printf_int);
    all->sub[0] = put_type('d', my_printf_int);
    all->sub[1] = put_type('i', my_printf_int);
    all->sub[2] = put_type('u', my_printf_int);
}

void set_flags_next(all_flags *all)
{
    all->simple[4] = put_type('i', my_printf_int);
    all->simple[5] = put_type('u', my_printf_int);
    all->simple[6] = put_type('b', my_printf_binary);
    all->simple[7] = put_type('o', my_printf_octal);
    all->simple[8] = put_type('x', my_printf_hexa_low);
    all->simple[9] = put_type('X', my_printf_hexa_up);
    all->simple[10] = put_type('%', my_printf_percentage);
    all->simple[11] = put_type('p', my_printf_address);
    all->point[0] = put_type('d', my_printf_int_0);
    all->point[1] = put_type('u', my_printf_int_0);
    all->point[2] = put_type('i', my_printf_int_0);
    all->point[3] = put_type('s', my_printf_string_precision);
    all->point[4] = put_type('b', my_printf_binary_precision);
    all->point[5] = put_type('o', my_printf_octal_precision);
    all->point[6] = put_type('x', my_printf_hexa_low_precision);
    all->point[7] = put_type('X', my_printf_hexa_up_precision);
    all->add[0] = put_type('d', my_printf_int_add);
    all->add[1] = put_type('i', my_printf_int_add);
    set_flags_final(all);
}

void set_flags(all_flags *all)
{
    all->simple = malloc(sizeof(flags *) * 12);
    all->point = malloc(sizeof(flags *) * 8);
    all->add = malloc(sizeof(flags *) * 3);
    all->space = malloc(sizeof(flags *) * 3);
    all->h = malloc(sizeof(flags *) * 9);
    all->sub = malloc(sizeof(flags *) * 3);
    all->simple[0] = put_type('s', my_printf_string);
    all->simple[1] = put_type('c', my_printf_char);
    all->simple[2] = put_type('S', my_printf_string_octal);
    all->simple[3] = put_type('d', my_printf_int);
    set_flags_next(all);
}

all_flags *get_all_flags(void)
{
    all_flags *flags = malloc(sizeof(all_flags));
    set_flags(flags);
    return flags;
}
