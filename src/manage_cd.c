/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** 42sh
*/

#include "my.h"

int manage_cd_params(char **tab, char *buff, size_t b, char *home_str)
{
    if ((tab[0][0] == 'c' && tab[0][1] == 'd' && tab[0][2] == '\0') &&
        (tab[1] == NULL || tab[1][0] == '~')) {
        cd_home(tab, home_str);
        return (1);
    }
    else if (tab[0][0] == 'c' && tab[0][1] == 'd' && tab[0][2] == '\0' &&
        tab[1] != NULL) {
        if (tab[1][0] != '/') {
            getcwd(buff, b);
            my_strcat(buff, "/");
            my_strcat(buff, tab[1]);
        }
        else {
            my_strcat(buff, tab[1]);
        }
        if (chdir(buff) == -1)
            dprintf(2, "%s: Not a directory.\n", tab[1]);
        return (1);
    }
    return (0);
}

int cd_home(char **tab, char *home_str)
{
    int i = 1;
    int j = 0;
    char *h_path = NULL;

    if (home_str == NULL)
        return (1);
    j = my_strlen(home_str);
    if (tab[1] == NULL)
        chdir(home_str);
    else {
        h_path = malloc(sizeof(char) * (my_strlen(tab[1]) + \
        my_strlen(home_str)));
        my_strcpy(h_path, home_str);
        for (i = 1;  tab[1][i] != '\0'; i++, j++) {
            h_path[j] = tab[1][i];
        }
        chdir(h_path);
        free(h_path);
    }
    return (1);

}

char *get_home_env(char **env)
{
    int i = 0;
    int j = 0;
    char *home = NULL;

    for (i = 0; env[i] != NULL; i++) {
        if (strncmp(env[i], "HOME=", 5) == 0)
            break;
    }
    if (env[i] == NULL)
        return (NULL);
    else if (strncmp(env[i], "HOME=", 5) == 0) {
        home = malloc(sizeof(char) * my_strlen(env[i]) - 4);
        for (j = 0; env[i][j] != '='; j++);
        j = j + 1;
        for (int k = 0; env[i][j] != '\0'; k++, j++) {
            home[k] = env[i][j];
        }
    }
    return (home);
}
