/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** 42sh
*/

#include <errno.h>
#include "my.h"

int catch_seg_fault(pid_t pid, int return_value)
{
    pid_t w = 0;
    int status = 0;

    if ((w = waitpid(pid, &status, 0)) != -1) {
        if (WIFEXITED(status))
            return_value = WEXITSTATUS(status);
        else {
            return_value = status;
            define_seg_fault(status);
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
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '&' && str[i + 1] == '&' && (str[i + 2] == '\0' ||
        str[i + 2] == '\0')) {
            my_putstr("Invalid null command.\n");
            return (1);
        }
        if (str[i] == '|' && str[i + 1] == '|' && (str[i + 2] == '\0' ||
        str[i + 2] == '\0')) {
            my_putstr("Invalid null command.\n");
            return (1);
        }
    }
    if (check_exist(pathtab, str))
        return (1);
    if (my_strlen(str) == 0)
        return (1);
    return (0);
}

int echo_command(char **tab, int return_value)
{
    if (strcmp(tab[0], "echo") == 0 && (strcmp(tab[1], "$?") == 0 ||
        strcmp(tab[1], "\"$?\"") == 0 )) {
        printf("%d\n", return_value);
        return (1);
    }
    return (0);
}

int main_execution(char *pathtab, char **tab, char **env, char *str)
{
    pid_t pid = 0;
    int i = 0;
    static int return_value = 0;

    if (echo_command(tab, return_value))
        return (0);
    if (check_wrong_command(pathtab, str))
        return (0);
    pid = fork();
    if (pid > 0)
        return_value = catch_seg_fault(pid, return_value);
    else if (pid == 0) {
        i = execve(pathtab, tab, env);
        if (errno == 8)
            my_printf("%s: Exec format error. Wrong Architecture.\n", pathtab);
        if (i == -1)
            check_file_format(pathtab, str, pid);
    }
    return (0);
}