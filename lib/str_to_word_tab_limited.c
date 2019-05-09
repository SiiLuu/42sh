/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** 42sh
*/

#include "my.h"

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