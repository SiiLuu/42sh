/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** seg fault gestion
*/

#include "my.h"

int prog_return(pid_t pid, int return_value)
{
    return_value = catch_seg_fault(pid, return_value);
    if (check_return(return_value))
        return (1);
    return (0);
}

void define_seg_fault(int status)
{
    if (WTERMSIG(status) == 8 && WCOREDUMP(status))
        my_printf("Floating exception (core dumped)\n");
    if (WTERMSIG(status) == 11 && WCOREDUMP(status))
        my_printf("Segmentation fault (core dumped)\n");
    if (WTERMSIG(status) == 8 && !WCOREDUMP(status))
        my_printf("Floating exception\n");
    if (WTERMSIG(status) == 11 && !WCOREDUMP(status))
        my_printf("Segmentation fault\n");
}