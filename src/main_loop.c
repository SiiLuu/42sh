/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** 42sh
*/

#include "my.h"

int simple_command(char **tab, char **env, simpl_t *sim)
{
    if (env_modif(env, tab) || change_directory(env, tab) ||
        detect_pipe(sim->str))
        return (1);
    sim->i = 0;
    sim->pathtab2 = get_path(env);
    while (sim->pathtab2[sim->i] != NULL) {
        sim->pathtab2[sim->i] = my_strcat(sim->pathtab2[sim->i], "/");
        sim->pathtab2[sim->i] = my_strcat(sim->pathtab2[sim->i], tab[0]);
        if (access(sim->pathtab2[sim->i], F_OK) == 0) {
            sim->pathtab = sim->pathtab2[sim->i];
            break;
        }
        sim->i++;
    }
    if (access(sim->pathtab2[sim->i], F_OK) == -1)
        sim->pathtab = sim->str;
    main_execution(sim->pathtab, tab, env, sim->str);
    return (0);
}

int check_advenced(char **tab, char **env, simpl_t *sim)
{
    if ((check_sep(sim->str) == 1)) {
        exec_sep(tab, env, sim);
    }
    else if ((check_and(sim->str) == 1)) {
        exec_sep(tab, env, sim);
    }
    else if ((check_or(sim->str) == 1)) {
        exec_sep(tab, env, sim);
    }
    else {
        if (simple_command(tab, env, sim))
            return (1);
    }
    return (0);
}

int main_loop(char **tab, char **env, simpl_t *sim)
{
    while (1) {
        signal(SIGINT, control_c);
        if ((sim->str = get_input()) == NULL)
            return (1);
        if (my_strlen(sim->str) == 0)
            break;
        if (sim->str[0] == 'b' && sim->str[1] == 'i' && sim->str[2] == 'n' &&
            sim->str[3] == '/') {
            dprintf(2, "%s: Command not found.\n", sim->str);
            break;
        }
        tab = my_str_to_word_array(sim->str);
        if (check_advenced(tab, env, sim))
            break;
    }
    //faire des free j'arrive pas sans tout casser wola
    return (0);
}