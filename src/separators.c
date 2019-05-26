/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** 42sh
*/

#include "my.h"

void malloc_cmd(semic_t *sem, char **tab, char *str)
{
    sem->pipe = malloc(sizeof(char) * 50);
    sem->cmd = malloc(sizeof(char *) * my_strlentab(tab) + 1);
    for (int g = 0; g != my_strlencmd(str) - 1; g++)
        sem->cmd[g] = malloc(sizeof(char) * my_strlencmd(str));
    sem->cmd = check_acces_sep(sem->cmd, tab, &sem->a);
    for (int y = 0; sem->cmd[y] != NULL; y++) {
            strcat(sem->pipe, sem->cmd[y]);
            strcat(sem->pipe, " ");
    }
}

void malloc_cmd_and(semic_t *sem, char **tab, char *str)
{
    sem->cmd = malloc(sizeof(char *) * my_strlentab(tab) + 1);
    sem->pipe = malloc(sizeof(char) * 50);
    for (int g = 0; g != my_strlencmd(str) - 1; g++)
        sem->cmd[g] = malloc(sizeof(char) * my_strlencmd(str));
    sem->cmd = check_acces_sep(sem->cmd, tab, &sem->a);
    for (int y = 0; sem->cmd[y] != NULL; y++) {
            strcat(sem->pipe, sem->cmd[y]);
            strcat(sem->pipe, " ");
    }
}

int check_builtins_semic(semic_t *sem, char **tab, char **env)
{
    if (env_modif(env, sem->cmd) || change_directory(env, sem->cmd) ||
        detect_pipe(sem->pipe)) {
        if (tab[sem->a] == NULL)
            return (1);
        sem->a++;
        for (int x = 0; sem->cmd[x] != NULL; x++)
            free(sem->cmd[x]);
        free(sem->pipe);
        return (1);
    }
    return (0);
}

void free_data(semic_t *sem)
{
    for (int x = 0; sem->cmd[x] != NULL; x++)
        free(sem->cmd[x]);
    free(sem->cmd);
    free(sem->pipe);
}

int acces_semi(semic_t *sem, char *str, char **env)
{
    sem->i = 0;
    sem->pathtab2 = get_path(env);
    sem->pathtab = acces_sep(sem->pathtab2, sem->cmd, sem->pathtab, &sem->i);
    if (access(sem->pathtab2[sem->i], F_OK) == -1)
        sem->pathtab = str;
    if (check_and(str)) {
        if (main_execution_and(sem->pathtab, sem->cmd, env, str))
            return (1);
    }
    else if (check_or(str)) {
        if (main_execution_or(sem->pathtab, sem->cmd, env, str))
            return (1);
    }
    else
        main_execution(sem->pathtab, sem->cmd, env, str);
    return (0);
}

int body_loop(semic_t *sem, char **tab, char *str, char **env)
{
    while (1) {
        if (check_and(str))
            malloc_cmd_and(sem, tab, str);
        else
            malloc_cmd(sem, tab, str);
        if (check_builtins_semic(sem, tab, env))
            break;
        if (acces_semi(sem, str, env))
            return (1);
        if (tab[sem->a] == NULL)
            break;
        sem->a++;
    }
    return (0);
}