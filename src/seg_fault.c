/*
** EPITECH PROJECT, 2019
** 42sh
** File description:
** seg fault gestion
*/

#include "my.h"

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