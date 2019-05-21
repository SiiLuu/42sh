/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** 42sh
*/

#include "my.h"

void loop_pipe(char ***cmd) 
{
    int p[2];
    pid_t pid;
    int fd_in = 0;

    while (*cmd != NULL) {
        pipe(p);
        if ((pid = fork()) == -1)
            exit(EXIT_FAILURE);
        else if (pid == 0) {
            dup2(fd_in, 0);
            if (*(cmd + 1) != NULL)
                dup2(p[1], 1);
            close(p[0]);
            execvp((*cmd)[0], *cmd);
            exit(EXIT_FAILURE);
        }
        else {
            wait(NULL);
            close(p[1]);
            fd_in = p[0];
            cmd++;
        }
    }
}

int count_pipe(char *str)
{
    int pipe = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '|')
            pipe += 1;
        if ((str[i] == '|' && str[i + 1] == '|') || (str[i] == '&'
            && str[i + 1] == '&') || str[i] == ';')
            return (0);
    }
    return (pipe);
}

int pipe_str(char *str)
{
    char ***cmd = 0;
    int pipe_nbr = count_pipe(str);

    cmd = malloc(sizeof(char ***) * (pipe_nbr + 2));
    cmd = fill_tab(str, cmd, pipe_nbr);
    loop_pipe(cmd);
    cmd = free_tab(cmd);
    return (0);
}

int detect_pipe(char *str)
{
    if (count_pipe(str) != 0) {
        pipe_str(str);
        return (1);
    }
    return (0);
}