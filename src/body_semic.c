/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** 42sh
*/

#include "my.h"

void exec_sep(char **tab, char **env, simpl_t *sim)
{
    semic_t *sem = malloc(sizeof(semic_t));

    sem->i = sim->i;
    while (1) {
        body_loop(sem, tab, sim->str, env);
        if (tab[sem->a] == NULL)
                break;
    }
    free(sem->pathtab);
    free(sem);
}

int check_and(char *str)
{
    for (int a = 0; str[a] != '\0'; a++)
        if (str[a] == '&' && str[a + 1] == '&') {
            return (1);
        }
    return (0);
}

int check_or(char *str)
{
    for (int a = 0; str[a] != '\0'; a++)
        if (str[a] == '|' && str[a + 1] == '|') {
            return (1);
        }
    return (0);
}