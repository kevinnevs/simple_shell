#include "shell.h"
/**
 * _which - Function
 *
 * Description: looks for files in the current PATH
 *
 * @str: pointer parameter of type char
 *
 * Return: returns file
 */

char *_which(char *str)
{
	char *env, *cat, **toks;
	int i = 0, f = 0;
	env = path("PATH");
	toks = _strtok(env, ":");
	free(env);
	while (toks[i] != NULL)
	{
		cat = _strdup(toks[i]);
		cat = _strcat(cat, "/");
		cat = _strcat(cat, str);
		if (access(cat, F_OK) == 0)
		{
			while (toks[f] != NULL)
			{
				free(toks[f]);
				f++;
			}
			free(toks);
			return (cat);
		}
		free(cat);
		i++;
	}
	while (toks[f] != NULL)
	{
		free(toks[f]);
		f++;
	}
	free(toks);
	return (NULL);
}
