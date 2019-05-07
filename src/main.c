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

char **init_tab(char *str)
{
    char **tab = NULL;

    if ((tab = malloc(sizeof(char *) * (my_strlen(str) + 1))) == NULL)
        exit(84);
    if ((tab[0] = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
        exit(84);
    return (tab);
}

char **end_tab(char **tab, int i, int j)
{
    tab[j][i] = '\0';
    j++;
    if ((tab[j] = malloc(sizeof(char) * 2)) == NULL)
        exit(84);
    tab[j] = NULL;
    return (tab);
}

char **get_tab(char **tab, int i, int j, char *str)
{
    tab[j][i] = '\0';
    j++;
    if ((tab[j] = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
        exit(84);
    return (tab);
}

char **str_to_word_tab_limited(char *str, char limit)
{
    int	i = 0;
    char **tab = NULL;
    int	j = 0;
    int	k = 0;

    tab = init_tab(str);
    while (str[i] != '\0') {
        if ((str[i] == limit) && (str[i + 1] != '\0')) {
            tab = get_tab(tab, j, k, str);
            k++;
            j = 0;
            i++;
        }
        if (str[i] != '\0') {
            tab[k][j] = str[i];
            j++;
            i++;
        }
    }
    tab = end_tab(tab, j, k);
    return (tab);
}

char *init_path(char *path, char *env)
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
}

int main(int argc, char const **argv, char **env)
{
    char *str = 0;
    char **tab = 0;
    char *pathtab = 0;
    char **pathtab2 = 0;
    int i = 0;

    env = empty_env(env);
    while (1)
        while (1) {
            signal(SIGINT, control_c);
            if ((str = get_input()) == NULL)
                return (0);
            tab = array_memory(tab, str);
            tab = my_str_to_word_array(str, tab);
            if (env_modif(env, tab) || change_directory(tab))
                break;
            pathtab2 = get_path(env);
            while (pathtab2[i] != NULL) {
                pathtab2[i] = my_strcat(pathtab2[i], "/");
                pathtab2[i] = my_strcat(pathtab2[i], tab[0]);
                if (access(pathtab2[i], F_OK) == 0) {
                    pathtab = pathtab2[i];
                    break;
                }
                i++;
            }
            main_execution(pathtab, tab, env, str);
            free(tab);
        }
    return (0);
}
