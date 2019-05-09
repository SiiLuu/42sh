/*
** EPITECH PROJECT, 2018
** my_list
** File description:
** my_list
*/

#include "my.h"

list_t env_modif2(list_t list, char **pathtab, int j)
{
    if (j == 0) {
        if (line_exist(pathtab[1], list) && pathtab[2] != NULL)
            list = setenv_modif_line(list, pathtab[1], pathtab[2]);
        else
            list = setenv_add_line(list, pathtab[1], pathtab[2]);
    }
    if (j == 1)
        list = unsetenv_delete(list, pathtab[1]);
    return (list);
}

list_t check_empty(list_t list, char **env, int i)
{
    static unsigned int compt = 0;

    if (compt == 0) {
        while (env[i] != NULL && compt == 0) {
            list = add_at_begin(list, env[i]);
            i--;
        }
    }
    compt = 1;
    return (list);
}

int check_display_env(char **pathtab, list_t list)
{
    if (!my_strcmp(pathtab[0], "env") || ((!my_strcmp(pathtab[0], "setenv")
        && pathtab[1] == NULL))) {
        display_list(list);
        return (1);
    }
    return (0);
}

int env_modif(char **env, char **pathtab)
{
    static list_t list = NULL;
    int i = count_line(env);

    list = check_empty(list, env, i);
    if (!my_strcmp(pathtab[0], "setenv") && pathtab[1] != NULL) {
        list = env_modif2(list, pathtab, 0);
        return (1);
    }
    if (!my_strcmp(pathtab[0], "unsetenv")) {
        if (pathtab[1] == NULL) {
            my_printf("unsetenv: Too few arguments.\n");
            return (1);
        }
        list = env_modif2(list, pathtab, 1);
        return (1);
    }
    if (check_display_env(pathtab, list))
        return (1);
    return (0);
}

char *my_getenv(char **env)
{
    int i = 0;
    int j = 0;

    while (env[i] != 0) {
        if (env[i][j] == 'P' && env[i][j + 1] == 'A' && env[i][j + 2] == 'T'
            && env[i][j + 3] == 'H') {
            return (env[i]);
        }
        i++;
    }
    return (NULL);
}