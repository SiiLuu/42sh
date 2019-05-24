/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** 42sh
*/

#include "my.h"

int main(int __attribute__((unused)) argc,
    char __attribute__((unused)) const **argv, char **env)
{
    simpl_t *sim = malloc(sizeof(simpl_t));
    char **tab = 0;

    sim->i = 0;
    env = empty_env(env);
    while (1) {
        if (main_loop(tab, env, sim))
            return (0);
    }
    return (0);
}