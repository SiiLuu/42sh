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

int change_directory(char **tab)
{
    char *buff;
    int status = 0;
    size_t b = 128;

    buff = malloc(sizeof(char) * 128);
    status = manage_cd_params(tab, buff, b);
    return (status);
}

int catch_seg_fault(pid_t pid, int return_value)
{
    pid_t w = 0;
    int status = 0;

    if ((w = waitpid(pid, &status, 0)) != -1) {
        if (WIFEXITED(status))
            return_value = WEXITSTATUS(status);
        else {
            return_value = status;
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
    return (return_value);
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

int check_wrong_command(char *pathtab, char *str)
{
    if (check_exist(pathtab, str))
        return (1);
    if (my_strlen(str) == 0)
        return (1);
    return (0);
}

int main_execution(char *pathtab, char **tab, char **env, char *str)
{
    pid_t pid = 0;
    int i = 0;
    static int return_value = 0;

    if (strcmp(tab[0], "echo") == 0 && strcmp(tab[1], "$?") == 0) {
        printf("%d\n", return_value);
        return (1);
    }
    if (check_wrong_command(pathtab, str))
        return (0);
    pid = fork();
    if (pid > 0)
        return_value = catch_seg_fault(pid, return_value);
    else if (pid == 0) {
        i = execve(pathtab, tab, env);
        if (errno == 8)
            my_printf("%s: Exec format error. Wrong architecture.\n", pathtab);
        if (i == -1)
            check_file_format(pathtab, str, pid);
    }
    return (0);
}