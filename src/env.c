/*
** EPITECH PROJECT, 2018
** my_list
** File description:
** my_list
*/

#include "stdbool.h"
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

    if (checkenv_pline(env) == true)
        return (0);
    list = check_empty(list, env, i);
    if (!my_strcmp(pathtab[0], "setenv") && pathtab[1] != NULL) {
        if (check_param_setenv(pathtab) == true) {
            list = env_modif2(list, pathtab, 0);
        }
        else
            my_putstr(SETENV_ERRSTR);
        return (1);
    }
    if (!my_strcmp(pathtab[0], "unsetenv")) {
        if (check_env_or_setenv(pathtab) == 1)
            return (1);
        list = env_modif2(list, pathtab, 1);
        return (1);
    }
    if (check_display_env(pathtab, list))
        return (1);
    return (0);
}

char *my_getenv(char **env, char *elem)
{
    int i = 0;

    while (env[i] != 0) {
        if (strcmp(env[i], elem) == 0) {
            return (env[i]);
        }
        i++;
    }
    return (NULL);
}