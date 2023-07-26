#include "shell.h"

/**
 * parse_args - handles command lines with arguements
 * @command: the command line to be handled
 * Return: arguements
 */

char **parse_args(char *command)
{
	char *token;
	int i = 0;

	char **args = malloc(BUFSIZE * sizeof(char *));

	if (args == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(command, " ");
	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;

	return (args);
}
