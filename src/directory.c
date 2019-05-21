/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** 42sh
*/

#include <errno.h>
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

void catch_seg_fault(pid_t pid)
{
    pid_t w = 0;
    int status = 0;

    if ((w = waitpid(pid, &status, 0)) != -1) {
        if (WTERMSIG(status) == 8 && WCOREDUMP(status))
            my_printf("Floating point exception (core dumped)\n");
        if (WTERMSIG(status) == 11 && WCOREDUMP(status))
            my_printf("Segmentation fault (core dumped)\n");
        if (WTERMSIG(status) == 8 && !WCOREDUMP(status))
            my_printf("Floating point exception\n");
        if (WTERMSIG(status) == 11 && !WCOREDUMP(status))
            my_printf("Segmentation fault\n");
    }
}

void check_file_format(char *pathtab, char *str, pid_t pid)
{
    struct stat sd;

    stat(pathtab, &sd);
    if (S_ISDIR(sd.st_mode))
        my_printf("%s: Permission denied.\n", str);
    pid = getpid();
    kill(pid, SIGKILL);
}

int main_execution(char *pathtab, char **tab, char **env, char *str)
{
    pid_t pid = 0;
    int i = 0;

    if (check_exist(pathtab, str))
        return (1);
    if (my_strlen(str) == 0)
        return (0);
    pid = fork();
    if (pid > 0)
        catch_seg_fault(pid);
    else if (pid == 0) {
        i = execve(pathtab, tab, env);
        if (errno == 8)
            my_printf("%s: Exec format error. Wrong architecture.\n", pathtab);
        if (i == -1)
            check_file_format(pathtab, str, pid);
    }
    return (0);
}