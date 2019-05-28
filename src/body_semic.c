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

    sem->status = 0;
    sem->i = sim->i;
    sem->status = sim->status;
    while (1) {
        if (body_loop(sem, tab, sim->str, env))
            break;
        if (tab[sem->a] == NULL)
            break;
    }
}

char **empty_env(char **env, simpl_t *sim)
{
    int count = 0;

    if (env[0] == 0) {
        env[0] = "PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin";
        env[1] = NULL;
        return (env);
    }
    for (int i = 0; env[i] != NULL; i++) {
        if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T' &&
            env[i][3] == 'H' && env[i][4] == '=')
            count = 1;
    }
    if (count != 1) {
        env = add_path(env);
        sim->status = 1;
    }
    return (env);
}

int change_directory(char **env, char **tab)
{
    char *buff = NULL;
    char *home_str = NULL;
    int status = 0;
    size_t b = 128;

    home_str = get_home_env(env);
    buff = malloc(sizeof(char) * 128);
    status = manage_cd_params(tab, buff, b, home_str);
    free(buff);
    free(home_str);
    return (status);
}