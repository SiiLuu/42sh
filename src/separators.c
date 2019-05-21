/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** 42sh
*/

#include "my.h"

int check_sep(char *str)
{
    for (int a = 0; str[a] != '\0'; a++)
        if (str[a] == ';') {
            return (1);
        }
    return (0);
}

char **check_acces_sep(char **cmd, char **tab, int *a)
{
    int b = 0;

    for (; tab[*a] != NULL; *a += 1) {
        if (!strcmp(tab[*a], ";") || !strcmp(tab[*a], "&&") ||
            !strcmp(tab[*a], "||"))
            break;
        cmd[b] = tab[*a];
        b++;
    }
    return (cmd);
}

char *acces_sep(char **pathtab2, char **cmd, char *pathtab, int *i)
{
    while (pathtab2[*i] != NULL) {
        pathtab2[*i] = my_strcat(pathtab2[*i], "/");
        pathtab2[*i] = my_strcat(pathtab2[*i], cmd[0]);
        if (access(pathtab2[*i], F_OK) == 0) {
            pathtab = pathtab2[*i];
            return (pathtab);
        }
        *i += 1;
    }
    return (NULL);
}

void exec_sep(char **tab, char **env, char *str, int i)
{
    char **cmd = NULL;
    int a = 0;
    char *pathtab = 0;
    char **pathtab2 = 0;

    while (1) {
        cmd = malloc(sizeof(tab));
        cmd = check_acces_sep(cmd, tab, &a);
        if (env_modif(env, tab) || change_directory(tab) || detect_pipe(str))
            break;
        i = 0;
        pathtab2 = get_path(env);
        pathtab = acces_sep(pathtab2, cmd, pathtab, &i);
        if (access(pathtab2[i], F_OK) == -1)
            pathtab = str;
        main_execution(pathtab, cmd, env, str);
        if (tab[a] == NULL)
            break;
        a++;
    }
    free(cmd);
}