#include "shell.h"
/**
 * prompt - Function that prompts a user 
 * Description: prints "$ ", wait for the user to enter a command.
 * prints it on the next line.
 *
 * Return: 0 on Success
 */
int prompt(void)
{
	size_t buffsize = 0, i = 0, n = 0;
	int status = 0;
	pid_t pid = 0;
	char *command, **token;
	do 
	{
		write(STDOUT_FILENO, "Kev Nai Shell$ ", 15);
		command = NULL;
		i = _getline(&command, &buffsize, stdin);
		n = 0;
		while (command[n] != '\n')
			n++;
		command[n] = '\0';
		token = _strtok(command, " ");
		if (command != NULL)
			free(command);
		pid = fork();
		if (pid == 0)
		{
			exec(token);
		}
		else
		{
			wait(&status);
		}
	} while (i > 0);
	return (0);
}

