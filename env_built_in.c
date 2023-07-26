#include "shell.h"
/**
 *execute_env - prints the current environment
 */
void execute_env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		char *line = environ[i];
		int len = strlen(line);

		if (len > 0 && line[len - 1] == '\n')
		{
			line[len - 1] = '\0';
		}
		write(STDOUT_FILENO, line, strlen(line));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
