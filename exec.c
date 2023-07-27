#include "shell.h"
/**
 * execute_command - execute a given command
 * @command: the command to be executed
 */
void execute_command(char *command)
{
	int status;
	char **args, *full_path;
	pid_t pid;

	if (strcmp(command, "exit") == 0)
	{
		char *arg = strchr(command, ' ');

		_exit((arg != NULL) ? atoi(arg + 1) : 0);
	}
	if (strcmp(command, "env") == 0)
	{
		execute_env();
		return;
	}

	full_path = search_path(command);

	if (full_path == NULL)
	{
		char error_msg[] = "command not found: ";

		write(STDERR_FILENO, error_msg, sizeof(error_msg) - 1);
		write(STDERR_FILENO, command, strlen(command));
		write(STDERR_FILENO, "\n", 1);
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
		execve(full_path, args, NULL);
		perror(full_path);
		free(args);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
		free(args);
	}
	free(full_path);
}

