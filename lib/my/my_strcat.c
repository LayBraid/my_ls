/*
** EPITECH PROJECT, 2021
** MyHunter
** File description:
** No file there , just an epitech header example
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i;
    int lenght = my_strlen(dest);
    char *tmp = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));
    for (int j = 0; j < dest[j] != '\0'; ++j) {
        tmp[j] = dest[j];
    }
    for (i = 0; src[i] != '\0'; i++)
        tmp[lenght + i] = src[i];
    tmp[lenght + i] = '\0';
    return (tmp);
}
