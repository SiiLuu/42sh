/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** my_getnbr
*/

#include "../include/my.h"

int	my_getnbr(char *str)
{
    int i = 0;
    int n = 0;

    if (str[0] == '-' && str[1] != '\0')
        i++;
    while (str[i] != '\0')
    {
        if (str[i] == '\n')
            break;
        n = n + str[i] - 48;
        n = n * 10;
        i++;
    }
    n /= 10;
    return (n);
}
