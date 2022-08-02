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
void no_such_file_dir(char *str, int c_n, list_t *env);

#endif
