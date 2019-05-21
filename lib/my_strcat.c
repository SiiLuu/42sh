/*
** EPITECH PROJECT, 2018
** my_strcat.c
** File description:
** my_strcat.c
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int a = 0;

    a = my_strlen(dest);
    while (src[i] != '\0') {
        dest[i + a] = src[i];
        i++;
    }
    dest[i + a] = '\0';
    return (dest);
}
