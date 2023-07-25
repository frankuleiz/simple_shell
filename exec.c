#include "shell.h"
/**
 *execute_command - execute a given command
 *@command: the command to be executed
 */
void execute_command(char *command)
{
	pid_t pid;
	int status;
	char **args;

	if (strcmp(command, "exit") == 0)
	{
		char exit_msg[] = "Exiting the shell.\n";

		write(STDOUT_FILENO, exit_msg, sizeof(exit_msg) - 1);
		exit(EXIT_SUCCESS);
	}
	if (strcmp(command, "env") == 0)
	{
		execute_env();
		return;
	}
	args = parse_args(command);
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(args);
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		execve(command, args, NULL);
		perror(command);
		free(args);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
		free(args);
	}
}
