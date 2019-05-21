/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** 42sh
*/

#include "my.h"

static void end_string_cleaner(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    i--;
    while (str[i] == ' ' || str[i] == '\t')
        i--;
    str[i+1] = '\0';
}

static char *string_cleaner(char *command)
{
    int i = 0;
    int p = 0;
    char *copy = malloc(sizeof(char)*my_strlen(command)+2);

    while (command[i] != '\0'){
        while (command[i] == ' ' || command[i] == '\t')
            i++;
        while (command[i] != ' ' && command[i] != '\t' && command[i] != '\0'){
            copy[p] = command[i];
            i++;
            p++;
        }
        copy[p] = ' ';
        p++;
    }
    copy[p] = '\0';
    end_string_cleaner(copy);
    free(command);
    return (copy);
}

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
    if (read > 0 && line[read - 1] == '\n') {
        line[read] = 0;
        line[read - 1] = '\0';
    }
    line = inputs(line, read);
    if (line != NULL)
        line = string_cleaner(line);
    return (line);
}