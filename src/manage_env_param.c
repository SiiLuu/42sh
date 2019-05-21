/*
** EPITECH PROJECT, 2018
** my_list
** File description:
** my_list
*/

#include <stdbool.h>
#include "../include/my.h"

char **add_path(char **env)
{
    int i = 0;
    int j = 0;
    char **new_str = NULL;

    for (i = 0; env[i] != NULL; i++);
    new_str = malloc(sizeof(char *) * (i + 1));

    for (j = 0; j != i; j++) {
        new_str[j] = env[j];
    }
    new_str[j] = "PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin";
    new_str[j + 1] = NULL;
    return (new_str);
}

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