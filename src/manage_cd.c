/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** 42sh
*/

#include "my.h"

int manage_cd_params(char **tab, char *buff, size_t b)
{
    if (tab[0][0] == 'c' && tab[0][1] == 'd' && tab[0][2] == '\0' &&
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
    else if (tab[0][0] == 'c' && tab[0][1] == 'd' && tab[0][2] == '\0' &&
            tab[1] == NULL) {
                chdir("/");
            }
    return (0);
}