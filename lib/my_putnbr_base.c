/*
** EPITECH PROJECT, 2018
** my_putnbr_base
** File description:
** my_putnbr_base
*/

#include <stdio.h>
#include <string.h>

void my_putchar(char c);

int my_put_nbr(int nb);

int my_strlen(char *str);

void my_putnbr_base(int nbr, char *base)
{
    if (nbr < 0){
        my_putchar('-');
        my_put_nbr(nbr * -1);
    }
    if (nbr / my_strlen(base)) {
        my_putnbr_base(nbr / my_strlen(base), base);
    }
    my_putchar(base[nbr % my_strlen(base)]);
}
