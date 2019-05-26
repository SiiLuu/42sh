/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** 42sh
*/

#include "my.h"

char *add_format_time(char *time_str, char *new_str)
{
    int compt = 0;

    for (int i = 0; time_str[i] != '\0'; i++) {
        if (time_str[i] == ':') {
            i -= 2;
            while (time_str[i] != ' ' && compt != 5) {
                new_str[strlen(new_str)] = time_str[i];
                i++;
                compt++;
            }
            break;
        }
    }
    return (new_str);
}

char *add_format(char *str)
{
    time_t mytime = time(NULL);
    char *time_str = ctime(&mytime);
    char *new_str = calloc(strlen(str) + 25, sizeof(char));
    static int number = 0;

    number += 1;
    sprintf(time_str, "%d", number);
    new_str = strcat(new_str, "     ");
    new_str = strcat(new_str, time_str);
    time_str = ctime(&mytime);
    new_str = strcat(new_str, "\t");
    new_str = add_format_time(time_str, new_str);
    new_str = strcat(new_str, "   ");
    new_str = strcat(new_str, str);
    return (new_str);
}

list_t clear_history(list_t list)
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

int check_arg(char *str)
{
    int i = 0;

    while (str[i] != '\0' && str[i] != '-')
        i++;
    if (str[i] == '\n')
        return (0);
    if (str[i + 1] == 'r')
        return (1);
    if (str[i + 1] == 'c')
        return (2);
    return (0);
}

int history(char *str)
{
    static list_t list = NULL;
    char *strr = str;
    int arg = 0;

    if (str[0] == 'h' && str[1] == 'i' && str[2] == 's' && str[3] == 't' &&
        str[4] == 'o' && str[5] == 'r' && str[6] == 'y') {
        str = add_format(str);
        list = add_at_end(list, str);
        arg = check_arg(strr);
        if (arg == 0)
            display_history(list);
        if (arg == 1)
            display_inversed_history(list);
        if (arg == 2)
            list = clear_history(list);
        return (1);
    }
    str = add_format(str);
    list = add_at_end(list, str);
    return (0);
}