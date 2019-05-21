/*
** EPITECH PROJECT, 2018
** my_list
** File description:
** my_list
*/

#include <stdbool.h>
#include "../include/my.h"

bool str_isalpha(char *str)
{
    int count = 0;
    int len = my_strlen(str);

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 48 && str[i] <= 57) ||
            (str[i] >= 65 && str[i] <= 90) ||
            (str[i] >= 97 && str[i] <= 122))
            count ++;
    }
    if (count != len)
        return (false);
    return (true);
}

bool check_param_setenv(char **pathtab)
{
    if (str_isalpha(pathtab[1]) != true) {
        return (false);
    }
    return (true);
}

int check_env_or_setenv(char **pathtab)
{
    if (pathtab[1] == NULL) {
        my_printf("unsetenv: Too few arguments.\n");
        return (1);
    }
    return (0);
}