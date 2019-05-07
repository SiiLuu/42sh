/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** minishell1
*/

#include "../include/my.h"

char **sort_path(char **pathtab, char *path)
{
    int i = 5;
    int itab = 0;
    int jtab = 0;

    while (path[i] != '\0') {
        if (path[i] == ':') {
            i++;
            itab++;
            jtab = 0;
        }
        pathtab[itab][jtab] = path[i];
        i++;
        jtab++;
    }
    return (pathtab);
}

char *find_path(char **env, char **tab)
{
    char *path = my_getenv(env);
    char **pathtab = 0;
    int i = 0;
    int j = 0;

    pathtab = array_memory2(pathtab, path);
    pathtab = sort_path(pathtab, path);
    while (pathtab[i] != NULL) {
        my_strcat(pathtab[i], "/");
        my_strcat(pathtab[i], tab[0]);
        j = access(pathtab[i], 0);
        if (j == -1)
            pathtab[i] = "NULL";
        else if (j == 0)
            return (pathtab[i]);
        i++;
    }
    return (NULL);
}

/*char *init_path(char *path, char *env)
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
}*/

char **empty_env(char **env)
{
    if (env[0] == 0) {
        env[0] = "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin";
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
            tab[1] = "/home/hugo\0";
        my_strcat(buff, tab[1]);
        if (chdir(buff) == -1)
            my_printf("%s: No such file or directory.\n", tab[1]);
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
    pid = fork();
    if (pid > 0)
        wait(0);
    if (my_strlen(str) == 0)
        return (0);
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