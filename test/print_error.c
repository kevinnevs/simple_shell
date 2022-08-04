#include "shell.h"
/**
 * not_found - write error ("sh: 1: lss: not found")
 * @str: user's typed command
 * @c_n: nth user's typed command
 * @env: bring in environmental variables linked list to write shell name
 */
void not_found(char *str, int c_n __attribute__((unused)), list_t *env)
{
	int count = 0;
	char *shell;

	/* get shell name to write */
	shell = get_env("_", env);
	while (shell[count] != '\0')
		count++;
	write(STDOUT_FILENO, shell, count);
	free(shell);
	write(STDOUT_FILENO, ": ", 2);
	/*printing the error name */
	count = 0;
	while (str[count] != '\0')
		count++;
	write(STDOUT_FILENO, str, count);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "No such file or directory\n" ,30);
}

/**
 * cant_cd_to - write error ("sh: 2: cd: can't cd to xyz")
 * @str: user's typed argument after the cmd cd
 * @c_n: nth user's typed command
 * @env: bring in environmental variables linked list to write shell name
 */
void cant_cd_to(char *str, int c_n __attribute__((unused)), list_t *env)
{
	int count = 0;
	char *shell;

	/* get shell name to write */
	shell = get_env("_", env);
	while (shell[count] != '\0')
		count++;
	write(STDOUT_FILENO, shell, count);
	free(shell);
	write(STDOUT_FILENO, ": ", 2);
	/*printing the error name */
	count = 0;
	while (str[count] != '\0')
		count++;
	write(STDOUT_FILENO, str, count);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "No such file or directory\n" ,30);
}

/**
 * no_such_file_dir - writes error ("./shell: No such file or directory")
 * @str: users typed cmd
 * @c_n: nth users typed command
 * @env: enviromental variables linked list to write shell name
 */
void no_such_file_dir(char *str, int c_n __attribute__((unused)), list_t *env)
{
	int count = 0;
	char *shell;

	/* get shell name to write */
	shell = get_env("_", env);
	while (shell[count] != '\0')
		count++;
	write(STDOUT_FILENO, shell, count);
	free(shell);
	write(STDOUT_FILENO, ": ", 2);
	/*printing the error name */
	count = 0;
	while (str[count] != '\0')
		count++;
	write(STDOUT_FILENO, str, count);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "No such file or directory\n" ,30);
}
/**
 * illegal_number - write error ("sh: 3: exit: Illegal number abc (or -1)")
 * @str: user's typed argument after the cmd exit
 * @c_n: nth user's typed command
 * @env: bring in environmental variables linked list to write shell name
 */
void illegal_number(char *str, int c_n __attribute__((unused)), list_t *env)
{
	int count = 0;
	char *shell = NULL;

	/* get shell name to write */
	shell = get_env("_", env);
	while (shell[count] != '\0')
		count++;
	write(STDOUT_FILENO, shell, count);
	free(shell);
	write(STDOUT_FILENO, ": ", 2);
	/*printing the error name */
	count = 0;
	while (str[count] != '\0')
		count++;
	write(STDOUT_FILENO, str, count);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "No such file or directory\n" ,30);
}
