/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** 42sh
*/

#include "my.h"

bool parse_time(char *time_str, char *new_str, bool quit, int i)
{
    int compt = 0;

    if (time_str[i] == ':') {
        i -= 2;
        while (time_str[i] != ' ' && compt != 5) {
            new_str[strlen(new_str)] = time_str[i];
            i++;
            compt++;
        }
        quit = 1;
    }
    return (quit);
}

void display_history(list_t list)
{
    element_t *tmp = list;

    while (tmp != NULL) {
        my_printf("%s\n", tmp->str);
        tmp = tmp->nxt;
    }
}

void display_inversed_history(list_t list)
{
    static list_t list2 = NULL;
    element_t *tmp = list;

    while (tmp != NULL) {
        list2 = add_at_begin(list2, tmp->str);
        tmp = tmp->nxt;
    }
    tmp = list2;
    while (tmp != NULL) {
        my_printf("%s\n", tmp->str);
        tmp = tmp->nxt;
    }
}