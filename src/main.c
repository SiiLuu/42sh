/*
** EPITECH PROJECT, 2018
** minishell1
** File description:
** minishell1
*/

#include "../include/my.h"

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
    else
        if (read == -1)
            return (NULL);
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

char *my_getenv(char **env)
{
    int i = 0;
    int j = 0;

    while (env[i] != 0) {
        if (env[i][j] == 'P' && env[i][j + 1] == 'A' && env[i][j + 2] == 'T'
            && env[i][j + 3] == 'H') {
            return (env[i]);
        }
        i++;
    }
    return (NULL);
}

int compt_doble_point(char const *str)
{
    int i = 0;
    int compt = 0;

    while (str[i] != '\0') {
        if (str[i] == ':')
            compt++;
        i++;
    }
    return (compt);
}

char **array_memory2(char **array, char const *str)
{
    array = malloc(sizeof(char *) * (compt_doble_point(str) + 1)
                    * my_strlen(str));
    for (int f = 0; f <= compt_doble_point(str); f++)
        array[f] = malloc(sizeof(char) * 50);
    return (array);
}

int main(int argc, char const **argv, char **env)
{
    char *str = 0;
    char **tab = 0;
    char *pathtab = 0;

    env = empty_env(env);
    while (1)
        while (1) {
            signal(SIGINT, control_c);
            if ((str = get_input()) == NULL)
                return (0);
            tab = array_memory(tab, str);
            tab = my_str_to_word_array(str, tab);
            pathtab = find_path(env, tab);
            if (env_modif(env, tab) || change_directory(tab))
                break;
            if (access(pathtab, F_OK) == -1)
                pathtab = str;
            main_execution(pathtab, tab, env, str);
            free(tab);
        }
    return (0);
}
