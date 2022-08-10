#include "shell.h"
/**
 * main - creates simple shell
 * @ac: argument count
 * @av: argument vector
 * @env: enviromental variables
 * Return: 0 on success
 */
int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;

	prompt(env);

	return (0);
}
