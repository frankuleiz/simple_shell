#include "shell.h"

/**
 * parse_args - handles command lines with arguements
 * @command: the command line to be handled
 * Return: arguements
 */

char **parse_args(char *command)
{
	char *start = command;
	int i = 0;

	char **args = malloc(BUFSIZE * sizeof(char *));

	if (args == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	while (*command)
	{
		while (*command && isspace(*command))
		{
			*command = '\0';
			command++;
		}
		if (*command == '\0')
		{
			break;
		}
		start = command;
		while (*command && !isspace(*command))
		{
			command++;
		}
		args[i++] = start;

		if (*command)
		{
			*command++ = '\0';
		}
	}
	args[i] = NULL;
	return (args);
}
