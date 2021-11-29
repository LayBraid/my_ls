/*
** EPITECH PROJECT, 2021
** printf
** File description:
** No file there , just an epitech header example
*/

#include "my.h"

char *my_revstr(char *str)
{
    int lenght = my_strlen(str);
    char temp;
    int index = 0;
    int index_2 = lenght - 1;

    while (index < lenght / 2){
        temp = str[index];
        str[index] = str[index_2];
        str[index_2] = temp;
        index++;
        index_2 -= 1;
    }
    return str;
}
