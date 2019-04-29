/*
** EPITECH PROJECT, 2018
** my_list
** File description:
** my_list
*/

#include "../include/my.h"

list_t setenv_modif_line(list_t list, char *str, char *remplace)
{
    element_t *tmp = list;

    while (tmp != NULL) {
        if (strcomp_env(tmp->str, str)) {
            my_strcpy(tmp->str, str);
            my_strcat(tmp->str, "=");
            my_strcat(tmp->str, remplace);
            return (list);
        }
        tmp = tmp->nxt;
    }
    return (list);
}

list_t setenv_add_line(list_t list, char *str, char *str2)
{
    char *new_env = NULL;

    if (str2 == NULL) {
        new_env = malloc(my_strlen(str) + 1);
        new_env = my_strcpy(new_env, str);
        new_env = my_strcat(new_env, "=");
        list = add_at_end(list, new_env);
    }
    else {
        new_env = malloc(my_strlen(str) + 1 + my_strlen(str2));
        new_env = my_strcpy(new_env, str);
        new_env = my_strcat(new_env, "=");
        new_env = my_strcat(new_env, str2);
        list = add_at_end(list, new_env);
    }
    return (list);
}

int count_line(char **env)
{
    int i = 0;

    while (env[i] != NULL)
        i++;
    return (i - 1);
}

list_t unsetenv_delete(list_t list, char *str)
{
    element_t *tmp = list;
    list_t list2 = NULL;

    while (tmp != NULL && tmp->nxt != NULL) {
        if (strcomp_env(tmp->str, str))
            tmp = tmp->nxt;
        list2 = add_at_end(list2, tmp->str);
        tmp = tmp->nxt;
    }
    return (list2);
}

int line_exist(char *str, list_t list)
{
    element_t *tmp = list;

    while (tmp != NULL) {
        if (strcomp_env(tmp->str, str)) {
            return (1);
        }
        tmp = tmp->nxt;
    }
    return (0);
}