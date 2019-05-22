/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** 42sh
*/

#include "my.h"

void exec_sep(char **tab, char **env, char *str, int i)
{
    semic_t *sem = malloc(sizeof(semic_t));

    sem->i = i;
    while (1) {
        body_loop(sem, tab, str, env);
        if (tab[sem->a] == NULL)
                break;
    }
    free(sem->pathtab);
    free(sem);
}