/*
** EPITECH PROJECT, 2021
** MY_LS
** File description:
** No file there , just an epitech header example
*/

#ifndef MY_LS_MY_H
    #define MY_LS_MY_H

    #include <unistd.h>
    #include <stdlib.h>
    #include <stddef.h>
    #include <stdarg.h>

    #include "../lib/my/struct.h"

    #define PRINTF_FLAGS "pcBbEeXlxFfSsdiuo0123456789#+-. %"
    #define PRINTF_FLAGS_INT "diu"
    #define PRINTF_FLAGS_NO_END " .#-+0123456789%"

int my_putchar(char c);

int my_putstr(char const *str);

char *my_strcpy(char *dest, char const *src);

char *my_strcat_c(char *dest, char const src);

char *my_itoa(int nb);

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src);

int my_rand(int i, int j);

int my_put_nbr(int n);

void my_put_octal(int nb);

int my_isdigit(char digit);

int my_int_len(int nb);

char *my_revstr(char *str);

char *convert_decimal_to_any(int nb, int base);

char *my_itoa(int nb);

char *my_str_upcase(char *str);

char *my_str_lowcase(char *str);

char *convert_decimal_to_any_long(long nb, int base);

char *my_strncpy(char *dest, char const *src, int n);

int my_getnbr(char *str);

int my_str_contains_c(char c, char *str);

char *get_param(char *str, int i);

void search_flag_extra(char *str, va_list param, int i);

void search_flag(char *str, va_list param, int i, all_flags *my_flags);

char *reformat_p(char *param);

int my_printf(char *str, ...);

void my_printf_char(char *str, va_list param, int i);

void my_printf_string(char *str, va_list param, int i);

void my_printf_string_octal(char *str, va_list param, int i);

void my_printf_int(char *str, va_list param, int i);

void my_printf_int_0(char *str, va_list param, int i);

void my_printf_percentage(char *str, va_list param, int i);

void my_printf_binary(char *str, va_list param, int i);

void my_printf_octal(char *str, va_list param, int i);

void my_printf_hexa_low(char *str, va_list param, int i);

void my_printf_hexa_up(char *str, va_list param, int i);

void my_printf_string_precision(char *str, va_list param, int i);

void my_printf_int_add(char *str, va_list param, int i);

void my_printf_int_space(char *str, va_list param, int i);

void my_printf_address(char *str, va_list param, int i);

void my_printf_int_spacer(char *str, va_list param, int i);

void my_printf_space(char *str, va_list param, int i);

void my_printf_h_octal(char *str, va_list param, int i);

void my_printf_h_hexa_low(char *str, va_list param, int i);

void my_printf_h_hexa_up(char *str, va_list param, int i);

void my_printf_binary_precision(char *str, va_list param, int i);

void my_printf_octal_precision(char *str, va_list param, int i);

void my_printf_hexa_low_precision(char *str, va_list param, int i);

void my_printf_hexa_up_precision(char *str, va_list param, int i);

all_flags *get_all_flags(void);

int my_strcmp(char const *s1, char const *s2);

int my_atoi(char *str);

int my_array_str_sort(char **array, int nb);

int nb_files_in_path(char *path);

int my_exit(char *reason, int nb);

char *my_strdup(char const *src);

#endif
