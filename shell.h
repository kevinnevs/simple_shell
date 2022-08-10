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
size_t _getline(char **str, size_t *size, FILE *stream);
/* from _strcat.c */
char *_strcat(char *dest, char *src);
/* from _strcpy.c */
char *_strcpy(char *dest, char *src);
/* from exec.c */
int exec(char **str);
/*from _which.c*/
char *path(char *str);
char *c_strdup(char *str, int cs);
char *_which(char *str);
/* from _strdup.c */
char *_strdup(char *str);
/* from _realloc.c */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif
