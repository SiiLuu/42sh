/*
** EPITECH PROJECT, 2018
** my_list
** File description:
** my_list
*/

#include "../include/my.h"

list_t add_at_begin(list_t list, char *str)
{
    element_t *new = malloc(sizeof(element_t));

    new->str = str;
    new->nxt = list;
    return (new);
}

list_t add_at_end(list_t list, char *str)
{
    element_t *new = malloc(sizeof(element_t));

    new->str = str;
    new->nxt = NULL;
    if (list == NULL)
        return (new);
    else {
        element_t *temp = list;
        while (temp->nxt != NULL) {
            temp = temp->nxt;
        }
        temp->nxt = new;
        return (list);
    }
}

void display_list(list_t list)
{
    element_t *tmp = list;

    while (tmp != NULL) {
        my_printf("%s\n", tmp->str);
        tmp = tmp->nxt;
    }
}

list_t delete_list(list_t list)
{
    element_t *tmp = list;
    element_t *tmpnxt;

    while (tmp != NULL) {
        tmpnxt = tmp->nxt;
        free(tmp);
        tmp = tmpnxt;
    }
    return (NULL);
}

int strcomp_env(char *src1, char *src2)
{
    int i = 0;

    while (src1[i] != '=' || src2[i] != '\0') {
        if (src1[i] != src2[i])
            return (0);
        i++;
    }
    return (1);
}