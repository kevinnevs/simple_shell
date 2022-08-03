#include "shell.h"
/**
 * main - Entry point
 *
 * Description: A shell program
 *
 * Return: 
 */
int main(void)
{
	char *buffer;
	char *ptr;
	char *argv[] = {"/bin/ls", "/usr/", NULL};
	/**
	 * user gets prompted:
	 * user gives input
	 * get user input using getline
	 * tokenize user input
	 * execute user input using execve
	 */

	/*prompt user*/
	buffer = prompt();
	/*remove null terminator from buffer using strtok()*/
	ptr = strtok(buffer,"\n");
	/*add user input to argv*/
	argv[0] = ptr;
	/*execute command*/
	if (execve(argv[0], argv, NULL)== -1)
	{
		perror("Error:");
	}
	return (0);

}
