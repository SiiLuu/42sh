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
        if (str[a] == ';' && str[a + 1] != '\0' && str[a + 1] != '\n') {
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
    cmd[b] = '\0';
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