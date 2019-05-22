/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <stdbool.h>
#include <assert.h>

#ifndef MY_H__
#define MY_H__

#define SETENV_ERRSTR \
    "setenv: Variable name must contain alphanumeric characters.\n"

typedef struct element element_t;
struct element
{
    char *str;
    struct element *nxt;
};

typedef element_t* list_t;

int my_strlen(char const *str);
char *my_strcpy(char *dest, char *src);
int my_getnbr(char *nb);
void my_put_nbr(int nbr);
void my_putchar(char c);
int my_putstr(char const *str);
void my_printf(char *str, ...);
void my_putnbr_base(int nbr, char *base);
int	my_getnbr(char *str);
int my_putstr_modif(char const *str);
char **my_str_to_word_array(char const *str);
char **array_memory(char **array, char const *str);
char *my_strcat(char *dest, char const *src);
char **sort_path(char **pathtab, char *path);
char *find_path(char **env, char **tab);
char **empty_env(char **env);
int change_directory(char **env, char **tab);
int main_execution(char *pathtab, char **tab, char **env, char *str);
void control_c(int __attribute__((unused)) contrl);
int my_strcmp(char const *s1, char const *s2);
int env_modif(char **env, char **pathtab);
int check_exist(char *pathtab, char *str);
int strcomp_env(char *src1, char *src2);
list_t delete_list(list_t list);
void display_list(list_t list);
list_t add_at_end(list_t list, char *str);
list_t add_at_begin(list_t list, char *str);
int line_exist(char *str, list_t list);
list_t unsetenv_delete(list_t list, char *str);
int count_line(char **env);
list_t setenv_add_line(list_t list, char *str, char *str2);
list_t setenv_modif_line(list_t list, char *str, char *remplace);
char *init_path(char *path, char *env);
char **get_path(char **env);
char **str_to_word_tab_limited(char *str, char limit);
char *my_getenv(char **env, char *elem);
char *get_input(void);
list_t env_modif2(list_t list, char **pathtab, int j);
int check_display_env(char **pathtab, list_t list);
int check_env_or_setenv(char **pathtab);
bool check_param_setenv(char **pathtab);
int detect_pipe(char *str);
char ***fill_tab(char *str2, char ***cmd, int pipe_nbr);
char ***free_tab(char ***cmd);
int manage_cd_params(char **tab, char *buff, size_t b, char *home_str);
void exec_sep(char **tab, char **env, char *str, int i);
char *acces_sep(char **pathtab2, char **cmd, char *pathtab, int *i);
char **check_acces_sep(char **cmd, char **tab, int *a);
int check_sep(char *str);
char **add_path(char **env);
char *get_home_env(char **env);
int cd_home(char **tab, char *buff, size_t b, char *home_str);

#endif
