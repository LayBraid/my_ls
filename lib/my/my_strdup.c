/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** No file there , just an epitech header example
*/

#include "my.h"

char *my_strdup(char const *src)
{
    char * dest;
    dest = (malloc (sizeof(src)+1));
    for (int i = 0; i < my_strlen(src); ++i) {
        dest[i] = src[i];
    }
    return dest;
}
