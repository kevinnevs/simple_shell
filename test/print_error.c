#include "shell.h"
/**
 * no_such_file_dir - writes error ("./shell: No such file or directory")
 * @str: users typed cmd
 * @c_n: nth users typed command
 * @env: enviromental variables linked list to write shell name
 */
void no_such_file_dir(char *str, int c_n, list_t *env)
{
	int count = 0;
	char *shell, *num;

	/* get shell name to write */
	shell = get_env("_", env);
	while (shell[count] != '\0')
		count++;
	write(STDOUT_FILENO, shell, count);
	free(shell);
	write(STDOUT_FILENO, ": ", 2);
	/*convert cmd line num to string to write */
	num = int_to_string(c_n);
	count = 0;
	while (num[count] != '\0')
		count++;
	write(STDOUT_FILENO, num, count);
	free(num);
	write(STDOUT_FILENO, ": ", 2);
	count = 0;
	while (str[count] != '\0')
		count++;
	write(STDOUT_FILENO, str, count);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "No such file or directory\n" ,30);
}

