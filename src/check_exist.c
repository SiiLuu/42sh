/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** 42sh
*/

#include "my.h"

int check_exist(char *pathtab, char *str)
{
    if (access(pathtab, F_OK) == -1) {
        dprintf(2, "%s: Command not found.\n", str);
        return (1);
    }
    return (0);
}
