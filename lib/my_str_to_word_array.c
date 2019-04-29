/*
** EPITECH PROJECT, 2018
** my_str_word_array
** File description:
** my_str_word_array
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/my.h"

int compt_space(char const *str)
{
    int i = 0;
    int compt = 0;

    while (str[i] != '\0') {
        if (str[i] == ' ' || str[i] == '\t')
            compt++;
        i++;
    }
    return (compt);
}

char **array_memory(char **array, char const *str)
{
    array = malloc(sizeof(char *) * my_strlen(str));
    for (int f = 0; f <= compt_space(str); f++)
        array[f] = malloc(sizeof(char) * my_strlen(str) + 2);
    return (array);
}

char *change_str_next(int j, char *newstr)
{
    j -= 2;
    if (newstr[j] == ' ') {
        newstr[j] = '\0';
        return (newstr);
    }
    j += 2;
    newstr[j] = '\0';
    return (newstr);
}

char *change_str(char const *str)
{
    int i = 0;
    int j = 0;
    char *newstr = malloc(sizeof(char) * my_strlen(str));

    while (str[i] != '\0') {
        if (str[i] == ' ' || str[i] == '\t') {
            while (str[i] == ' ' || str[i] == '\t')
                i++;
            if (j != 0) {
                newstr[j] = ' ';
                j++;
            }
        }
        newstr[j] = str[i];
        i++;
        j++;
    }
    newstr = change_str_next(j, newstr);
    return (newstr);
}

char **my_str_to_word_array(char *str, char **tab)
{
    int itab = 0;
    int jtab = 0;
    int i = 0;

    str = change_str(str);
    while (str[i] != '\0') {
        if (str[i] == ' ' || str[i] == '\t') {
            while (str[i] == ' ' || str[i] == '\t')
                i++;
            if (my_strlen(tab[itab]) != 0)
                itab++;
            jtab = 0;
        }
        tab[itab][jtab] = str[i];
        jtab++;
        i++;
    }
    tab[++itab] = NULL;
    return (tab);
}
