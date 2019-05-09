/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** my_putstr.c
*/

#include "my.h"

void my_putstr_modif2(char const *str, int i)
{
    if (str[i] < 33) {
            my_putchar('\\');
            my_put_nbr(0);
            my_put_nbr(0);
            my_put_nbr(str[i]);
    }
    if (str[i] == 127) {
            my_putchar('\\');
            my_put_nbr(177);
    }
}

int my_putstr_modif(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] > 32 && str[i] < 127)
            my_putchar(str[i]);
        my_putstr_modif2(str, i);
        i++;
    }
    return 0;
}
