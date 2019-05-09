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
    char *str = 0;
    char **tab = 0;
    char *pathtab = 0;
    char **pathtab2 = 0;
    int i = 0;

    env = empty_env(env);
    while (1)
        while (1) {
            signal(SIGINT, control_c);
            if ((str = get_input()) == NULL)
                return (0);
            tab = array_memory(tab, str);
            tab = my_str_to_word_array(str, tab);
            if (env_modif(env, tab) || change_directory(tab))
                break;
            i = 0;
            pathtab2 = get_path(env);
            while (pathtab2[i] != NULL) {
                pathtab2[i] = my_strcat(pathtab2[i], "/");
                pathtab2[i] = my_strcat(pathtab2[i], tab[0]);
                if (access(pathtab2[i], F_OK) == 0) {
                    pathtab = pathtab2[i];
                    break;
                }
                i++;
            }
            if (access(pathtab2[i], F_OK) == -1)
                pathtab = str;
            main_execution(pathtab, tab, env, str);
            free(tab);
        }
    return (0);
}
