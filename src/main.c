/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** 42sh
*/

#include "my.h"

int check_and(char *str)
{
    for (int a = 0; str[a] != '\0'; a++)
        if (str[a] == '&' && str[a + 1] == '&') {
            return (1);
        }
    return (0);
}

int check_or(char *str)
{
    for (int a = 0; str[a] != '\0'; a++)
        if (str[a] == '|' && str[a + 1] == '|') {
            return (1);
        }
    return (0);
}

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
            if (my_strlen(str) == 0)
                break;
            tab = my_str_to_word_array(str);
            if ((check_sep(str) == 1)) {
                exec_sep(tab, env, str, i);
            }
            else if ((check_and(str) == 1)) {
                exec_sep(tab, env, str, i);
            }
            else if ((check_or(str) == 1)) {
                exec_sep(tab, env, str, i);
            }
            else {
                if (env_modif(env, tab) || change_directory(env, tab) || detect_pipe(str))
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
            }
            free(tab);
        }
    return (0);
}