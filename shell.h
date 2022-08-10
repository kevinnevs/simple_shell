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

char *prompt(void);
int exec(char **s);

#endif
