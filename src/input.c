/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** 42sh
*/

#include "my.h"

char *inputs(char *line, ssize_t read)
{
    if (isatty(0)) {
        if (!my_strcmp(line, "exit") || read == -1) {
            my_printf("exit\n");
            return (NULL);
        }
        if (read == -1) {
            my_printf("exit");
            return (NULL);
        }
    }
    else {
        if (!my_strcmp(line, "exit") || read == -1)
            return (NULL);
        if (read == -1)
            return (NULL);
    }
    return (line);
}

char *get_input(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read = 0;

    if (isatty(0))
        my_putstr("$ ~ ");
    read = getline(&line, &len, stdin);
    if (line[read - 1] == '\n') {
        line[read] = 0;
        line[read - 1] = '\0';
    }
    line = inputs(line, read);
    return (line);
}