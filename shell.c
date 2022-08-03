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
	size_t bufsize = 32;
	/**
	 * user gets prompted:
	 * user gives input
	 * get user input using getline
	 * tokenize user input
	 * execute user input using execve
	 */

	/*prompt user*/
	prompt();

	/*get user input*/
	/*allocate memory and check if NULL*/
	buffer = (char * )malloc(bufsize * sizeof(char));
	if( buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}
	getline(&buffer,&bufsize,stdin);

	/*tokenize user input*/
	
}
