/*
** EPITECH PROJECT, 2019
** 42sh*
** File description:
** function prototype
*/

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
#include <time.h>

#ifndef MY_42_H__
#define MY_42_H__

#define SETENV_ERRSTR \
    "setenv: Variable name must contain alphanumeric characters.\n"

typedef struct element element_t;
struct element
{
    char *str;
    struct element *nxt;
};

typedef struct semic_s
{
    int i;
    int status;
    int a;
    char **cmd;
    char **pathtab2;
    char *pathtab;
    char *pipe;
}semic_t;

typedef struct simpl_s
{
    int i;
    int status;
    char *str;
    char **pathtab2;
    char *pathtab;
}simpl_t;

typedef element_t *list_t;

char **sort_path(char **pathtab, char *path);
char *find_path(char **env, char **tab);
char **empty_env(char **env, simpl_t *sim);
int change_directory(char **env, char **tab);
int main_execution(char *pathtab, char **tab, char **env, char *str);
void control_c(int __attribute__((unused)) contrl);
int my_strcmp(char const *s1, char const *s2);
int env_modif(char **env, char **pathtab, int i);
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
void exec_sep(char **tab, char **env, simpl_t *sim);
char *acces_sep(char **pathtab2, char **cmd, char *pathtab, int *i);
char **check_acces_sep(char **cmd, char **tab, int *a);
int check_sep(char *str);
char **add_path(char **env);
char *get_home_env(char **env);
int cd_home(char **tab, char *home_str);
int my_strlentab(char **tab);
int my_strlencmd(char const *str);
void malloc_cmd(semic_t *sem, char **tab, char *str);
int check_builtins_semic(semic_t *sem, char **tab, char **env);
void free_data(semic_t *sem);
int acces_semi(semic_t *sem, char *str, char **env);
int body_loop(semic_t *sem, char **tab, char *str, char **env);
int check_and(char *str);
int check_or(char *str);
int simple_command(char **tab, char **env, simpl_t *sim);
int check_advenced(char **tab, char **env, simpl_t *sim);
int main_loop(char **tab, char **env, simpl_t *sim);
int change_directory(char **env, char **tab);
int check_exist_and(char *pathtab, char **tab);
int check_return(int return_value);
int main_execution_and(char *pathtab, char **tab, char **env, char *str);
int catch_seg_fault(pid_t pid, int return_value);
void check_file_format(char *pathtab, char *str, pid_t pid);
int echo_command(char **tab, int return_value);
int main_execution_or(char *pathtab, char **tab, char **env, char *str);
void define_seg_fault(int status);
int history(char *str);
void display_history(list_t list);
void display_inversed_history(list_t list);
int check_if_redirect(char *str, char **env);
bool checkenv_pline(char **env);
void malloc_cmd_and(semic_t *sem, char **tab, char *str);

#endif