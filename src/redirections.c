/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** 42sh redirections
*/

#include "my.h"
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

static int open_fd(char *filename, int mode)
{
    int i = 0;
    int fd = -1;

    if (filename[i] == '>')
        i++;
    if (access(&filename[i], 0) < 0)
        fd = open(&filename[i], O_RDWR | O_CREAT, 0664);
    else if (mode == 1)
        fd = open(&filename[i], O_RDWR | O_APPEND);
    else
        fd = open(&filename[i], O_RDWR);
    return (fd);
}

static int redirect_to_fd(char *redi, char *filename)
{
    int fd = -1;
    int mode = 0;

    if (redi[0] != '>') {
        perror("Impossible to redirect this fd.\n");
        return (-1);
    }
    if (redi[1] == '>')
        mode = 1;
    if ((redi[1] != '\0' && redi[1] != '>') ||
        (redi[1] == '>' && redi[2] != '\0'))
        fd = open_fd(&redi[1], mode);
    else if (filename != NULL)
        fd = open_fd(filename, mode);
    else {
        perror("Missing name for redirect.\n");
        return (-1);
    }
    return (fd);
}

void correct_tab(char **tab)
{
    int i = 0;

    for (i = 1; tab[i] != NULL ; i++)
        if (strstr(tab[i], ">") != NULL)
            tab[i] = NULL;
}

int check_if_redirect(char *str, char **env)
{
    int i = 1;
    int new_fd = -1;
    char **tab = my_str_to_word_array(str);
    pid_t new_pid = 0;

    for (i = 1; tab[i] != NULL ; i++) {
        if (strstr(tab[i], ">") != NULL)
            new_fd = redirect_to_fd(tab[i], tab[i+1]);
    }
    if (new_fd < 0)
        return (0);
    correct_tab(tab);
    new_pid = fork();
    if (new_pid > 0)
        wait(NULL);
    else{
        i = dup2(new_fd, 1);
        execve("/bin/ls", tab, env);
    }
    close(new_fd);
    return (1);
}