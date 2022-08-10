#include "shell.h"
/**
 * exec - Function
 *
 * Description: execve function
 *
 * @
 * Return:
 */
int exec(char **str)
{
	if (execve(s[0], s, NULL) == -1)
	{
		perror("Error:");
	}
	return (0);
}

