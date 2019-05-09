/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** 42sh
*/

#include "my.h"

char *init_path(char *path, char *env)
{
    int	i = 0;
    int	j = 0;

    while (env[i] != '=' && env[i] != '\0')
        i++;
    i++;
    while (env[i] != '\0') {
        path[j] = env[i];
        i++;
        j++;
    }
    path[j] = '\0';
    return (path);
}

char **get_path(char **env)
{
    int	i = 0;
    char **res = NULL;
    char *path = NULL;

    while (env[i] != NULL) {
        if (env[i][0] == 'P' && env[i][1] == 'A'
            && env[i][2] == 'T' && env[i][3] == 'H') {
            if ((path = malloc(sizeof(char *) * my_strlen(env[i]))) == NULL)
                exit(84);
            path = init_path(path , env[i]);
            res = str_to_word_tab_limited(path, ':');
        }
        i++;
    }
    return (res);
}