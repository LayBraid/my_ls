/*
** EPITECH PROJECT, 2021
** MyHunter
** File description:
** No file there , just an epitech header example
*/

#include "my.h"

char *my_strcat_c(char *dest, char const src)
{
    int i = my_strlen(dest);

    char *returned;
    returned = malloc(sizeof(char) * (i + 2));
    returned = my_strcpy(returned, dest);
    returned[i] = src;
    returned[i + 1] = '\0';
    return (returned);
}
