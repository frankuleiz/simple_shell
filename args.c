#include "shell.h"

/**
 * parse_args - Parse a command string into arguments.
 * @command: The command string to parse.
 *
 * Return: An array of strings containing the arguments.
 */
char **parse_args(char *command)
{
	const char *delimiters = " \t\n\r\v\f";
	char *token, *tmp;
	char **args = NULL;
	int arg_count = 0;
	
	while (*command && strchr(delimiters, *command))
	{
		command++;
	}
	
	tmp = strdup(command);
	if (!tmp)
	{
		perror("strdup");
		exit(EXIT_FAILURE);
	}
	
	token = _strtok(tmp, delimiters);
	while (token)
	{
		arg_count++;
		token = _strtok(NULL, delimiters);
	}
	free(tmp);
	
	args = malloc((arg_count + 1) * sizeof(char *));
	if (!args)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	arg_count = 0;
	token = _strtok(command, delimiters);
	while (token)
	{
		args[arg_count] = strdup(token);
		if (!args[arg_count])
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		arg_count++;
		token = _strtok(NULL, delimiters);
	}
	args[arg_count] = NULL; 
	
	return (args);
}

