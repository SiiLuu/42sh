/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** 42sh
*/

#include "my.h"


char **split(const char *str, const char *delim)
{
    char *aux;
    char *p;
    char **res;
    char *argv[200];
    int n = 0, i;

    aux = strdup(str);
    assert(aux);
    for (p = strtok(aux, delim); p; p = strtok(NULL, delim))
        argv[n++] = p;
    argv[n++] = NULL;
    argv[n++] = aux;
    res = calloc(n, sizeof(char *));
    assert(res);
    for (i = 0; i < n; i++)
        res[i] = argv[i];
    return (res);
}

char *check_before_return(char *str)
{
    if (str[(strlen(str) - 1)] == ' ')
        str[(strlen(str) - 1)] = '\0';
    return (str);
}

char *return_command(char *str2, char *str)
{
    char **argv = 0;
    static int i = 0;

    argv = split(str2, " ");
    for (; argv[i]; i++) {
        if (argv[i][0] == '|') {
            i++;
            str = check_before_return(str);
            return (str);
        }
        str = strcat(str, argv[i]);
        str = strcat(str, " ");
    }
    free(argv[i + 1]);
    free(argv);
    str = check_before_return(str);
    i = 0;
    return (str);
}

char ***fill_tab(char *str2, char ***cmd, int pipe_nbr)
{
    int i = 0;
    char *str = 0;

    for (; i != (pipe_nbr + 1); i++) {
        str = calloc(256, sizeof(char));
        cmd[i] = my_str_to_word_array(return_command(str2, str));
        free(str);
    }
    cmd[i] = NULL;
    return (cmd);
}

char ***free_tab(char ***cmd)
{
    for (int i = 0; cmd[i] != NULL; i++) {
        for (int j = 0; cmd[i][j] != NULL; j++)
            free(cmd[i][j]);
        free(cmd[i]);
    }
    free(cmd);
    return (cmd);
}