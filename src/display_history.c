/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** 42sh
*/

#include "my.h"

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