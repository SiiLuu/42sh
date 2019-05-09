/*
** EPITECH PROJECT, 2018
** my_printf.c
** File description:
** Printf
*/

#include <stdarg.h>
#include "my.h"
#include <stdio.h>

void switch1(char *str, va_list ap, int i)
{
    char *result_str;
    int result_int;

    switch (str[i+1]) {
    case '%':
        my_putchar('%');
    break;
    case 's':
        result_str = va_arg(ap, char *);
        my_putstr(result_str);
    break;
    case 'd':
        result_int = va_arg(ap, int);
        my_put_nbr(result_int);
    break;
    }
}

void switch2(char *str, va_list ap, int i)
{
    unsigned int result_unsigned_int = 0;

    switch (str[i+1]) {
    case 'x':
        result_unsigned_int = va_arg(ap, unsigned int);
        my_putnbr_base(result_unsigned_int, "0123456789abcdef");
    break;
    case 'X':
        result_unsigned_int = va_arg(ap, unsigned int);
        my_putnbr_base(result_unsigned_int, "0123456789ABCDEF");
    break;
    case 'u':
        result_unsigned_int = va_arg(ap, unsigned int);
        my_putnbr_base(result_unsigned_int, "0123456789");
    break;
    case 'o':
        result_unsigned_int = va_arg(ap, unsigned int);
        my_putnbr_base(result_unsigned_int, "01234567");
    break;
    }
}

void switch3(char *str, va_list ap, int i)
{
    int result_int = 0;
    char result_char;

    switch (str[i+1]) {
    case 'c':
        result_char = va_arg(ap, int);
        my_putchar(result_char);
    break;
    case 'i':
        result_int = va_arg(ap, int);
        my_put_nbr(result_int);
    break;
    case 'b':
        result_int = va_arg(ap, int);
        my_putnbr_base(result_int, "01");
    break;
    }
}

void switch4(char *str, va_list ap, int i)
{
    int result_int;
    char *result_str;

    switch (str[i+1]) {
    case 'p':
        result_int = va_arg(ap, int);
        my_putstr("0x");
        my_putnbr_base(result_int, "0123456789abcdef");
    break;
    case 'S':
        result_str = va_arg(ap, char *);
        my_putstr_modif(result_str);
    break;
    }
}

void my_printf(char *str, ...)
{
    int i = 0;
    va_list ap;

    va_start(ap, *str);
    while (str[i] != '\0') {
        if (str[i] == '%') {
            switch1(str, ap, i);
            switch2(str, ap, i);
            switch3(str, ap, i);
            switch4(str, ap, i);
            i++;
        }else {
            my_putchar(str[i]);
        }
        i++;
    }
    va_end(ap);
}
