#include "shell.h"
/**
 * built_in - handles builtins
 * @token: users cmd
 * @env: enviromental variable
 * @num: takes nth user cmd to write error message
 * @command: bring in comand to free
 * Return: 1 if acted on builtin, 0 if not
 */
int built_in(char **token, list_t *env, int num, char **command)
{
	int i = 0;
	/* if user types "exit", free cmd tokens, and exit */
	if (_strcmp(token[0], "exit") == 0)
	{
		i = __exit(token, env, num, command);
	}
	/* if user types "env", print, free cmd tokens, and reprompt */
	else if (_strcmp(token[0], "env") == 0)
	{
		_env(token, env);
		i = 1;
	}
	/* if user types "cd" , it will change directory */
	else if (_strcmp(token[0], "cd") == 0)
	{
		i = _cd(token, env, num);
	}
	/* if user types "setenv", create or modify linked list node */
	else if (_strcmp(token[0], "setenv") == 0)
	{
		_setenv(&env, token);
		i = 1;
	}
	/* if user types "setenv", remove linked list node */
	else if (_strcmp(token[0], "unsetenv") == 0)
	{
		_unsetenv(&env, token);
		i = 1;
	}
	return (i);
}

/**
 * ignore_space - returns string without spaces infront
 * @str: string
 * Return: new string
 */
char *ignore_space(char *str)
{
	while (*str == ' ')
		str++;
	return (str);
}

/**
 * ctrl_D - a func that exxits program if ctrl+D is pressed
 * @i: characters read via getline
 * @command: users cmd
 * @env: enviromental variable linked list
 */
void ctrl_D (int i, char *command, list_t *env)
{
	/* handles Ctrl+D */
	if (i == 0)
	{
		free(command); /*exits with newline if in shell */
		free_linked_list(env);
		/* ctrl+d prints newline */
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
}

/**
 * prompt - a function that prompts a user to key in
 * @en: enviromental variables
 * Return: 0 Always success
 */
int prompt(char **en)
{
	list_t *env;
	size_t i = 0, n = 0;
	int command_line_no = 0, exit_stat = 0;
	char *command, *n_command, **token;

	env = env_linked_list(en);
	do {
		command_line_no++;
		/* prompts again if in interactive shell */
		if(isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		/* reads users command in stdin */
		i = get_line(&command);
		/* exits shell if ctrl+D */
		ctrl_D(i, command, env);
		n_command = command;
		/* ignore_space function */
		command = ignore_space(command);
		/* replace get_lines \n with \0 */
		while (command[0] != '\n')
			n++;
		command[n] = '\0';
		/* prompts again if user hits enter only */
		if (command[0] == '\0')
		{
			free(n_command);
			continue;
		}
		
		token = NULL; token = _str_tok(command, " "); /*token user command */
		if (n_command != NULL)
			free(n_command);
		exit_stat = built_in(token, env, command_line_no, NULL);
		if (exit_stat)
			continue;
		exit_stat = _execve(token, env, command_line_no);
	}
	/* keeps on repeating till user exits shell */
	while (1);
	return (exit_stat);
}
