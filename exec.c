#include "shell.h"
/**
 *execute_command - execute a given command
 *@command: the command to be executed
 */
void execute_command(char *command)
{
	if (strcmp(command, "exit") == 0)
	{
		write("Exiting the shell.\n");
		exit(EXIT_SUCCESS);
	}

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
		char *args[] = {command, NULL};

		execve(command, args, NULL);

		perror(command);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
	}
}
