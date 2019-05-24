/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** 42sh redirections
*/

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

    if (filename[i] = '>')
        i++;
    if (access(&filename[i], 0) == 0)
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
    if (redi[1] != '\0' || redi[1] == '>' && redi[2] != '\0')
        fd = open_fd(&redi[1], mode);
    else if (filename != NULL)
        fd = open_fd(filename, mode);
    else {
        perror("Missing name for redirect.\n");
        return (-1);
    }
    dup2(1, fd);
    return (fd);
}

int check_if_redirect(char **tab)
{
    int i = 1;

    for (i = 1; tab[i] != NULL ; i++) {
        if (strstr(tab[i], ">") != NULL)
            return (redirect_to_fd(tab[i], tab[i+1]));
    }
}