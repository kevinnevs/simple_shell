#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

/**
 * struct_list - linked list for enviromental variables
 * @var: enviromental variable string
 * @next: prints to next node
 */
typedef struct list
{
	char *var;
	struct list *next;
} list_t;

/* from prompt.c */
int prompt(void);
/* from _getline.c */
size_t get_line(char **str);
/* from _strcat.c */
char *_strcat(char *dest, char *src);
/* from _strcpy.c */
char *_strcpy(char *dest, char *src);
/* from exec.c */
int exec(char **str);

#endif
