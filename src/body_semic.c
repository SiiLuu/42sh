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
        if (body_loop(sem, tab, sim->str, env))
            break;
        if (tab[sem->a] == NULL)
            break;
    }
    //free(sem->pathtab);
    //free(sem);
}

int check_and(char *str)
{
    if (str[0] == '&' && str[1] == '&')
        return (0);
    for (int a = 0; str[a] != '\0'; a++)
        if (str[a] == '&' && str[a + 1] == '&' && (str[a + 2] != '\0' &&
        str[a + 2] != '\n')) {
            return (1);
        }
    return (0);
}

int check_or(char *str)
{
    if (str[0] == '|' && str[1] == '|')
        return (0);
    for (int a = 0; str[a] != '\0'; a++)
        if (str[a] == '|' && str[a + 1] == '|' && (str[a + 2] != '\0' &&
        str[a + 2] != '\n')) {
            return (1);
        }
    return (0);
}

char **empty_env(char **env)
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
    if (home_str == NULL)
        return (1);
    buff = malloc(sizeof(char) * 128);
    status = manage_cd_params(tab, buff, b, home_str);
    free(buff);
    free(home_str);
    return (status);
}