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

int my_strlentab(char **tab)
{
    int a = 0;

    for (; tab[a] != NULL; a++) {
        if (!strcmp(tab[a], ";"))
            return (a);
        a++;
    }
    return (a);
}

int my_strlencmd(char const *str)
{
    int i = 0;
    int y = 0;
    int z = 0;

    for (; str[i] != '\0'; i++) {
        z++;
        if (str[i] == ' ' && z > y)
            y = i;
        else
            z = 0;
    }
    return (y);
}

void exec_sep(char **tab, char **env, char *str, int i)
{
    char **cmd = NULL;
    int a = 0;
    char *pathtab = 0;
    char **pathtab2 = 0;
    char *pipe = NULL;

    while (1) {
        while (1) {
            pipe = malloc(sizeof(char) * 50);
            cmd = malloc(sizeof(char *) * my_strlentab(tab) + 1);
            for (int g = 0; g != my_strlencmd(str) - 1; g++)
                cmd[g] = malloc(sizeof(char) * my_strlencmd(str));
            cmd = check_acces_sep(cmd, tab, &a);
            for (int y = 0; cmd[y] != NULL; y++) {
                strcat(pipe, cmd[y]);
                strcat(pipe, " ");
            }
            if (env_modif(env, cmd) || change_directory(cmd) || detect_pipe(pipe)) {
                a++;
                free(cmd);
                free(pipe);
                break;
            }
            i = 0;
            pathtab2 = get_path(env);
            pathtab = acces_sep(pathtab2, cmd, pathtab, &i);
            if (access(pathtab2[i], F_OK) == -1)
                pathtab = str;
            main_execution(pathtab, cmd, env, str);
            if (tab[a] == NULL)
                break;
            a++;
            free(cmd);
            free(pipe);
        }
        if (tab[a] == NULL)
                break;
    }
}