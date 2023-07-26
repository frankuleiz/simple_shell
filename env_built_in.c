#include "shell.h"
/**
 *execute_env - prints the current environment
 */
void execute_env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		i++;
		write(STDOUT_FILENO, "\n", 1);
	}
}
