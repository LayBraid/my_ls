/*
** EPITECH PROJECT, 2021
** printf
** File description:
** No file there , just an epitech header example
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;

    for (i = 0; i < my_strlen(src); i++) {
        if (n == i) {
            dest[i] = '\0';
            break;
        }
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}
