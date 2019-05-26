/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** function to execute the and command
*/
#include "my.h"
#include <errno.h>

int check_return(int return_value)
{
    if (return_value > 0)
        return (1);
    else
        return (0);
    return (0);
}

int check_exist_and(char *pathtab, char **tab)
{
    //printf("%s", pathtab);
    if (tab[0][0] == '.' && tab[0][1] == '/')
        return (0);
    if (access(pathtab, F_OK) == -1) {
        dprintf(2, "%s: Command not found.\n", tab[0]);
        return (1);
    }
    return (0);
}

int and_execution(char **tab, char **env, char *pathtab, int i)
{
    if (tab[0][0] == '.' && tab[0][1] == '/')
        i = execve(tab[0], tab, env);
    else
        i = execve(pathtab, tab, env);
    return (i);
}

int main_execution_and(char *pathtab, char **tab, char **env, char *str)
{
    pid_t pid = 0;
    int i = 0;
    static int return_value = 0;

    if (check_exist_and(pathtab, tab))
        return (1);
    if (echo_command(tab, return_value))
        return (0);
    pid = fork();
    if (pid > 0) {
        return_value = catch_seg_fault(pid, return_value);
        if (check_return(return_value))
            return (1);
    }
    else if (pid == 0) {
        i = and_execution(tab, env, pathtab, i);
        if (errno == 8)
            my_printf("%s: Exec format error. Wrong Architecture.\n", pathtab);
        if (i == -1)
            check_file_format(pathtab, str, pid);
    }
    return (0);
}