/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** 42sh
*/

#include "my.h"

char **empty_env(char **env)
{
    if (env[0] == 0) {
        env[0] = "PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin";
        env[1] = NULL;
    }
    return (env);
}

int change_directory(char **tab)
{
    char buff[256];

    if (tab[0][0] == 'c' && tab[0][1] == 'd') {
        getcwd(buff, sizeof buff);
        my_strcat(buff, "/");
        if (tab[1] == NULL)
            tab[1] = "/home/hugo";
        my_strcat(buff, tab[1]);
        if (chdir(buff) == -1)
            dprintf(2, "%s: Not a directory.\n", tab[1]);
        return (1);
    }
    return (0);
}

int main_execution(char *pathtab, char **tab, char **env, char *str)
{
    pid_t pid;
    struct stat sd;

    if (check_exist(pathtab, str))
        return (1);
    if (my_strlen(str) == 0)
        return (0);
    pid = fork();
    if (pid > 0)
        wait(0);
    else if (pid == 0)
        if (execve(pathtab, tab, env) == -1) {
            stat(pathtab, &sd);
            if (S_ISDIR(sd.st_mode))
                my_printf("%s: Permission denied.\n", str);
            else
                my_printf("%s: Command not found.\n", str);
            pid = getpid();
            kill(pid, SIGKILL);
        }
    return (0);
}