/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "42.h"

#ifndef MY_H__
#define MY_H__

int my_strlen(char const *str);
char *my_strcpy(char *dest, char *src);
int my_getnbr(char *nb);
void my_put_nbr(int nbr);
void my_putchar(char c);
int my_putstr(char const *str);
void my_printf(char *str, ...);
void my_putnbr_base(int nbr, char *base);
int	my_getnbr(char *str);
int my_putstr_modif(char const *str);
char **my_str_to_word_array(char const *str);
char **array_memory(char **array, char const *str);
char *my_strcat(char *dest, char const *src);

#endif