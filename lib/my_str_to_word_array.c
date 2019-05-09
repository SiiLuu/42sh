/*
** EPITECH PROJECT, 2018
** my_str_word_array
** File description:
** my_str_word_array
*/

#include "my.h"

static int spliter_count(char const *tab)
{
    int i = 0;
    int words = 0;

    while (tab[i] != '\0') {
        words += (tab[i] != '\n' && tab[i] != '\0');
        for (; tab[i] != '\0' && tab[i] != '\n' ; i++);
        i++;
    }
    return (words);
}

char **my_str_to_word_array(char const *str)
{
    char **args = NULL;
    int size = spliter_count(str);
    int i = 0;
    int k = 0;

    args = malloc(sizeof(char *) * (size + 1));
    for (int j = 0; j < size; j++) {
        for (k = 0 ; str[i + k] != '\n' && str[i + k] != '\0' ; k++);
        args[j] = malloc(sizeof(char) * (k + 1));
        for (int l = 0; l < k; l++, i++)
            args[j][l] = str[i];
        args[j][k] = '\0';
        i++;
    }
    args[size] = NULL;
    return (args);
}