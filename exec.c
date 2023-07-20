#include "shell.h"
/**
 *execute_command - execute a given command
 *@command: the command to be executed
 */
void execute_command(char *command)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		char *args[2];

		args[0] = command;
		args[1] = NULL;

		execve(command, args, NULL);

		perror(command);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
	}
}
