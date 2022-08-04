#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>

/**
 * struct_list - linked list for enviromental variables
 * @var: holds enviromental variable string
 * @next: prints to next node
 */
typedef struct list
{
	char *var;
	struct list *next;
} list_t;

/* function prototypes */
/* from prompt.c */
int built_in(char **token, list_t *env, int num, char **command);
char *ignore_space(char *str);
void ctrl_D(int i, char *command, list_t *env);
int prompt(char **env);
/* from print_error.c */
void not_found(char *str, int c_n __attribute__((unused)), list_t *env);
void no_such_file_dir(char *str, int c_n __attribute__((unused)), list_t *env);
void illegal_number(char *str, int c_n __attribute__((unused)), list_t *env);
/* from get_env.c */
char *c_strdup(char *str, int cs);
char *get_env(char *str, list_t *env);
/* from _strcmp.c */
int _strcmp(char *s1, char *s2);
/* from _strdup.c */
char *_strdup(char *str);
/* from linked_list.c */
size_t print_list(list_t *h);
list_t *add_end_node(list_t **head, char *str);
int delete_nodeint_at_index(list_t **head, int index);
void free_linked_list(list_t *list);
/* from free_double_ptr.c */
void free_double_ptr(char **str);
/* from __exit.c */
int c_atoi(char *s);
int __exit(char **str, list_t *env, int num, char **command);
/* from env_linked_list.c */
list_t *env_linked_list(char **env);
int _env(char **str, list_t *env);
/* from _strcpy.c */
char *_strcpy(char *dest, char *src);
/* from _strcat.c */
char *_strcat(char *dest, char *src);
/* from _getline.c */
size_t get_line(char **str);
/* from _execve.c */
void c_exit(char **str, list_t *env);
int _execve(char **s, list_t *env, int num);
/* from _which.c */
char *_which(char *str, list_t *env);
/* from _strtok.c */
int t_strlen(char *str, int pos, char delm);
int t_size(char *str, char delm);
char *ignore_delm(char *str, char delm);
char **_str_tok(char *str, char *delm);
/* from _realloc.c */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
/* from c_strtok.c */
int c_t_size(char *str, char delm);
char **c_str_tok(char *str, char *delm);
/* from _cd.c */
char *c_strcat(char *dest, char *src);
int c_setenv(list_t **env, char *name, char *dir);
void cd_only(list_t *env, char *current);
int cd_execute(list_t *env, char *current, char *dir, char *str, int num);
int _cd(char **str, list_t *env, int num);


#endif
